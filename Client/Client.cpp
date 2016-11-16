#include "Precompiled.h"
#include "..\Server\Server.h"

using namespace Microsoft::WRL;

// Note:
// Method 1: Registration based COM activation
// In the command prompt, type the following to register the Server.dll component:
// C:\regsvr32 Server.dll
// To unregister:
// C:\ regsvr32 /u Server.dll

int main()
{
    // Replacing with IClassFactory
#if 0
    ComRuntime runtime;

    ComPtr<IHatchery> hatchery;

    HR(CoGetClassObject(__uuidof(Hen),
        CLSCTX_INPROC_SERVER,
        nullptr,
        __uuidof(hatchery),
        reinterpret_cast<void **>(hatchery.GetAddressOf())));

    ComPtr<IHen> hen;

    HR(hatchery->CreateHen(hen.GetAddressOf()));

    hen->Cluck();
#endif // 0

    // Using IClassFactory
#if 0
    ComRuntime runtime;

    ComPtr<IClassFactory> hatchery;

    HR(CoGetClassObject(__uuidof(Hen),
        CLSCTX_INPROC_SERVER,
        nullptr,
        __uuidof(hatchery),
        reinterpret_cast<void **>(hatchery.GetAddressOf())));

    ComPtr<IHen> hen;

    HR(hatchery->CreateInstance(nullptr,
        __uuidof(hen),
        reinterpret_cast<void **>(hen.GetAddressOf())));

    hen->Cluck();
#endif // 0

    // using simplier method:
    // calling CoCreateInstance() method instead of CreateInstance

    ComRuntime runtime(Apartment::MultiThreaded);

    ComPtr<IHen> hen;

    HR(CoCreateInstance(__uuidof(Hen),
                        nullptr,
                        CLSCTX_INPROC_SERVER,
                        __uuidof(hen),
                        reinterpret_cast<void **>(hen.GetAddressOf())));

    hen->Cluck();

    // unloading the DLL from the client side
    for (;;)
    {
        CoFreeUnusedLibrariesEx(1000,0); // 1000 ms delay ; 2nd parameter is reserved
        hen.Reset();
        Sleep(1000);
    }
}