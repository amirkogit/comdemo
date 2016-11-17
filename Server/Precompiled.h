#pragma once

#include <windows.h>
#include <memory>

#include <atlbase.h>
#define ASSERT ATLASSERT
#define TRACE ATLTRACE

#include <ktmw32.h>
#pragma comment(lib, "ktmw32.lib")
#pragma comment(lib, "rpcrt4.lib")