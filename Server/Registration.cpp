#include "Precompiled.h"
#include "handle.h"

// Note: Change the following in the Project Settings to test register and unregister functions
//Server Property pages :
// -Debugging :
//	Command : C : \Windows\SysWow64\regsvr32.exe
//	Command Arguments : $(TargetPath) // To test the register function
//	Command Arguments : / u $(Target Path) // To test unregister function

using namespace KennyKerr;

typedef invalid_handle Transaction;

Transaction CreateTransaction()
{
    return Transaction(CreateTransaction(nullptr, // default security descriptor
                                         nullptr, // reserved
                                         TRANSACTION_DO_NOT_PROMOTE, 
                                         0, // reserved
                                         0, // reserved
                                         INFINITE,
                                         nullptr)); // description
}

struct RegistryKeyTraits
{
    typedef HKEY pointer;

    static pointer invalid() throw()
    {
        return nullptr;
    }

    static void close(pointer value) throw()
    {
        HANDLE_VERIFY_(ERROR_SUCCESS,RegCloseKey(value));
    }
};

typedef unique_handle<RegistryKeyTraits> RegistryKey;

// Create a registry key
RegistryKey CreateRegistryKey(HKEY key,
                              wchar_t const * path,
                              Transaction const & transaction,
                              REGSAM access)
{
    HKEY handle = nullptr;

    auto result = RegCreateKeyTransacted(key,
                                         path,
                                         0, // reserved
                                         nullptr, // class
                                         REG_OPTION_NON_VOLATILE,
                                         access,
                                         nullptr, // default security descriptor
                                         &handle,
                                         nullptr, // disposition
                                         transaction.get(),
                                         nullptr); // reserved

    if (ERROR_SUCCESS != result)
    {
        SetLastError(result);
    }

    return RegistryKey(handle);
}

// Open a registry key
RegistryKey OpenRegistryKey(HKEY key,
                            wchar_t const * path,
                            Transaction const & transaction,
                            REGSAM access)
{
    HKEY handle = nullptr;

    auto result = RegOpenKeyTransacted(key,
                                       path,
                                       0,
                                       access,
                                       &handle,
                                       transaction.get(),
                                       nullptr);

    if (ERROR_SUCCESS != result)
    {
        SetLastError(result);
    }

    return RegistryKey(handle);
}

// Options for table entry for registry
enum class EntryOption
{
    None,
    Delete,
    FileName
};

struct Entry
{
    wchar_t const * Path;
    EntryOption Option;
    wchar_t const * Name;
    wchar_t const * Value;
};

static Entry Table[] =
{
    {
        L"Software\\Classes\\CLSID\\{d4fc6132-a367-4da0-ad41-ad58e8bd8f7b}",
        EntryOption::Delete,
        nullptr,
        L"Hen"
    },

    {
        L"Software\\Classes\\CLSID\\{d4fc6132-a367-4da0-ad41-ad58e8bd8f7b}\\InprocServer32",
        EntryOption::FileName,
    },

    {
        L"Software\\Classes\\CLSID\\{d4fc6132-a367-4da0-ad41-ad58e8bd8f7b}\\InprocServer32",
        EntryOption::None,
        L"ThreadingModel",
        L"Free"
    },

    {
        L"Software\\Classes\\CLSID\\{2c9db197-83b9-47c3-be14-aed29daa1bb1}",
        EntryOption::Delete,
        nullptr,
        L"Hen Proxy"
    },
    {
        L"Software\\Classes\\CLSID\\{2c9db197-83b9-47c3-be14-aed29daa1bb1}\\InprocServer32",
        EntryOption::FileName
    },
    {
        L"Software\\Classes\\CLSID\\{2c9db197-83b9-47c3-be14-aed29daa1bb1}\\InprocServer32",
        EntryOption::None,
        L"ThreadingModel",
        L"Both"
    },

    {
        L"Software\\Classes\\Interface\\{2c9db197-83b9-47c3-be14-aed29daa1bb1}",
        EntryOption::Delete,
        nullptr,
        L"IAsyncHenEventHandler"
    },
    {
        L"Software\\Classes\\Interface\\{2c9db197-83b9-47c3-be14-aed29daa1bb1}\\ProxyStubClsid32",
        EntryOption::None,
        nullptr,
        L"{2c9db197-83b9-47c3-be14-aed29daa1bb1}"
    },

    {
        L"Software\\Classes\\Interface\\{03662d63-ac6a-4e70-b768-83a3c39d26aa}",
        EntryOption::Delete,
        nullptr,
        L"IAsyncHen"
    },
    {
        L"Software\\Classes\\Interface\\{03662d63-ac6a-4e70-b768-83a3c39d26aa}\\ProxyStubClsid32",
        EntryOption::None,
        nullptr,
        L"{2c9db197-83b9-47c3-be14-aed29daa1bb1}"
    }

};

// helper function to unregister dll
bool UnRegister(Transaction const & transaction)
{
    for (auto const & entry : Table)
    {
        if (EntryOption::Delete != entry.Option)
        {
            continue;
        }

        auto key = OpenRegistryKey(HKEY_LOCAL_MACHINE,
                                   entry.Path,
                                   transaction,
                                   DELETE | KEY_ENUMERATE_SUB_KEYS | KEY_QUERY_VALUE | KEY_SET_VALUE);

        if (!key)
        {
            if (ERROR_FILE_NOT_FOUND == GetLastError())
            {
                continue;
            }

            return false;
        }

        auto result = RegDeleteTree(key.get(),
                                    nullptr); // delete the key itself

        if (ERROR_SUCCESS != result)
        {
            SetLastError(result);
            return false;
        }
    }

    return true;
}

// helper function to register dll
bool Register(Transaction const & transaction)
{
    if (!UnRegister(transaction))
    {
        return false;
    }

    wchar_t filename[MAX_PATH];

    auto const length = GetModuleFileName(reinterpret_cast<HMODULE>(&__ImageBase), // s_serverModule
                                          filename,
                                          _countof(filename));

    if (0 == length || _countof(filename) == length)
    {
        return false;
    }

    for (auto const & entry : Table)
    {
        auto key = CreateRegistryKey(HKEY_LOCAL_MACHINE,
                                     entry.Path,
                                     transaction,
                                     KEY_WRITE);

        if (!key)
        {
            return false;
        }

        if (EntryOption::FileName != entry.Option && !entry.Value)
        {
            continue;
        }

        auto value = entry.Value;

        if (!value)
        {
            ASSERT(EntryOption::FileName == entry.Option);
            value = filename;
        }

        auto result = RegSetValueEx(key.get(),
                                    entry.Name,
                                    0,// reserved
                                    REG_SZ,
                                    reinterpret_cast<BYTE const *>(value),
                                    static_cast<DWORD>(sizeof(wchar_t) * (wcslen(value) + 1)));

        if (ERROR_SUCCESS != result)
        {
            TRACE(L"RegSetValueEx failed %d\n", result);
            SetLastError(result);
            return false;
        }
    }

    return true;
}

HRESULT __stdcall DllRegisterServer()
{
    auto transaction = CreateTransaction();

    if (!transaction)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    if (!Register(transaction))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    if (!CommitTransaction(transaction.get()))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    return S_OK;
}

HRESULT __stdcall DllUnregisterServer()
{
    auto transaction = CreateTransaction();

    if (!transaction)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    if (!UnRegister(transaction))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    if (!CommitTransaction(transaction.get()))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    return S_OK;
}