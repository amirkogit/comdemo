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