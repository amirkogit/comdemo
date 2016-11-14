#include "Precompiled.h"

// Note: Change the following in the Project Settings to test register and unregister functions
//Server Property pages :
// -Debugging :
//	Command : C : \Windows\SysWow64\regsvr32.exe
//	Command Arguments : $(TargetPath) // To test the register function
//	Command Arguments : / u $(Target Path) // To test unregister function



HRESULT __stdcall DllRegisterServer()
{
    return S_OK;
}

HRESULT __stdcall DllUnregisterServer()
{
    return S_OK;
}