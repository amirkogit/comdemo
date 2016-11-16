#pragma once

#include <wrl.h>

#include <atlbase.h>
#define ASSERT ATLASSERT
#define TRACE ATLTRACE

struct ComException
{
    HRESULT result;

    explicit ComException(HRESULT const value) :
        result(value)
    {

    }
};

inline void HR(HRESULT const result)
{
    _ASSERTE(S_OK == result);

    if (S_OK != result)
    {
        throw ComException(result);
    }
}

enum class Apartment
{
    MultiThreaded = COINIT_MULTITHREADED,
    SingleThreaded = COINIT_APARTMENTTHREADED
};

struct ComRuntime
{
    explicit ComRuntime(Apartment apartment = Apartment::MultiThreaded)
    {
        HR(CoInitializeEx(nullptr,
            static_cast<DWORD>(apartment)));
    }
    ~ComRuntime()
    {
        CoUninitialize();
    }
};
