#include "Precompiled.h"
#include "..\Server\Server.h"

using namespace Microsoft::WRL;

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