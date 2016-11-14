#include "Precompiled.h"
#include "Server.h"

struct Hen : IHen
{
    long m_count;

    Hen() : m_count(0) {}

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
};

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

