#pragma once

#include <unknwn.h>

struct __declspec(uuid("d4fc6132-a367-4da0-ad41-ad58e8bd8f7b")) 
Hen;

struct __declspec(uuid("c1b11d4a-12f1-400b-87bb-95d52a4c5021"))
    IHen : IUnknown
{
    virtual void __stdcall Cluck() = 0;
};

// Replacing with IClassFactory
#if 0
struct __declspec(uuid("3cb31964-dd2b-4793-9455-ae796180d218"))
    IHatchery : IUnknown
{
    virtual HRESULT __stdcall CreateHen(IHen ** hen) = 0;
};
#endif // 0
