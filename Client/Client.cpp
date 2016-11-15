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
}