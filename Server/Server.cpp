#include "Precompiled.h"
#include "Server.h"
#include "..\Proxy\Hen.h"
#include <wrl.h>

using namespace Microsoft::WRL;

static long s_serverLock;

struct Hen : IHen, IAsyncHen
{
    long m_count;

    Hen() : m_count(0) 
    {
        _InterlockedIncrement(&s_serverLock);
    }

    ~Hen()
    {
        _InterlockedDecrement(&s_serverLock);
    }

    ULONG __stdcall AddRef() override
    {
        return _InterlockedIncrement(&m_count);
    }

    ULONG __stdcall Release() override
    {
        ULONG result = _InterlockedDecrement(&m_count);

        if (0 == m_count)
        {
            delete this;
        }

        return result;
    }

    HRESULT __stdcall QueryInterface(IID const & id,
                                     void ** result) override
    {
        ASSERT(result);

        if (id == __uuidof(IHen) ||
            id == __uuidof(IUnknown))
        {
            *result = static_cast<IHen *>(this);
        }
        else if(id == __uuidof(IAsyncHen))
        {
            *result = static_cast<IAsyncHen *>(this);
        }
        else
        {
            *result = 0;
            return E_NOINTERFACE;
        }

        static_cast<IUnknown *>(*result)->AddRef();
        return S_OK;
    }

    void __stdcall Cluck() override
    {
        TRACE(L"Cluck\n");
    }

    HRESULT __stdcall SetEventHandler(IAsyncHenEventHandler * handler) override
    {
        ASSERT(handler);

        ComPtr<IAsyncHenEventHandler> reference(handler);

        auto ok = TrySubmitThreadpoolCallback([](PTP_CALLBACK_INSTANCE, void * context)
        {
            ComPtr<IAsyncHenEventHandler> handler;
            handler.Attach(static_cast<IAsyncHenEventHandler *>(context));

            Sleep(1000);

            handler->OnCluck();
        },
        reference.Get(), nullptr);

        if(ok)
        {
            reference.Detach();
        }

        return ok ? S_OK : HRESULT_FROM_WIN32(GetLastError());
    }
};

// Replacing custom IHatchery interface with the IClassFactory interface
#if 0
struct Hatchery : IHatchery
{
    ULONG __stdcall AddRef() override
    {
        return 2;
    }

    ULONG __stdcall Release() override
    {
        return 1;
    }

    HRESULT __stdcall QueryInterface(IID const & id,
        void ** result) override
    {
        ASSERT(result);

        if (id == __uuidof(IHatchery) ||
            id == __uuidof(IUnknown))
        {
            *result = static_cast<IHatchery *>(this);
        }
        else
        {
            *result = 0;
            return E_NOINTERFACE;
        }

        return S_OK;
    }

    HRESULT __stdcall CreateHen(IHen ** result) override
    {
        ASSERT(result);

        *result = new (std::nothrow) Hen;

        if (0 == *result)
        {
            return E_OUTOFMEMORY;
        }

        (*result)->AddRef();
        return S_OK;
    }
};
#endif // 0

struct Hatchery : IClassFactory
{
    ULONG __stdcall AddRef() override
    {
        return 2;
    }

    ULONG __stdcall Release() override
    {
        return 1;
    }

    HRESULT __stdcall QueryInterface(IID const & id,
        void ** result) override
    {
        ASSERT(result);

        if (id == __uuidof(IClassFactory) ||
            id == __uuidof(IUnknown))
        {
            *result = static_cast<IClassFactory *>(this);
        }
        else
        {
            *result = 0;
            return E_NOINTERFACE;
        }

        return S_OK;
    }

    HRESULT __stdcall CreateInstance(IUnknown * outer,
        IID const & iid,
        void ** result) override
    {
        ASSERT(result);
        *result = nullptr;

        if (outer)
        {
            return CLASS_E_NOAGGREGATION;
        }

        auto hen = new (std::nothrow) Hen;

        if (!hen)
        {
            return E_OUTOFMEMORY;
        }

        hen->AddRef();
        auto hr = hen->QueryInterface(iid, result);
        hen->Release();

        return hr;
    }

    HRESULT __stdcall LockServer(BOOL lock) override
    {
        if (lock)
        {
            _InterlockedIncrement(&s_serverLock);
        }
        else
        {
            _InterlockedDecrement(&s_serverLock);
        }

        return S_OK;
    }
};

HRESULT __stdcall DllGetClassObject(CLSID const & clsid,
                                    IID const & iid,
                                    void ** result)
{
    ASSERT(result);
    *result = nullptr;

    if(__uuidof(Hen) == clsid)
    {
        static Hatchery hatchery;

        return hatchery.QueryInterface(iid, result);
    }

    return CLASS_E_CLASSNOTAVAILABLE;
}

HRESULT __stdcall DllCanUnloadNow()
{
    TRACE(L"DllCanUnloadNow %s\n", s_serverLock ? L"No!" : L"Yes!");
    return s_serverLock ? S_FALSE : S_OK;
}

BOOL WINAPI DllMain(HINSTANCE module, DWORD reason, void *)
{
    if (DLL_PROCESS_ATTACH == reason)
    {
        DisableThreadLibraryCalls(module);
        TRACE(L"LoadLibrary\n");
    }
    else if (DLL_PROCESS_DETACH == reason)
    {
        TRACE(L"FreeLibrary\n");
    }
    else
    {
        ASSERT(false);
    }

    return TRUE;
}