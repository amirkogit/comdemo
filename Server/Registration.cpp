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

HRESULT __stdcall DllRegisterServer()
{
    auto transaction = CreateTransaction();

    if (!transaction)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    // register here
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

    // unregister here
    if (!CommitTransaction(transaction.get()))
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    return S_OK;
}