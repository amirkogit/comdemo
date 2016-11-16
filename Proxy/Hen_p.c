

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0613 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for Hen.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0613 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "Hen.h"

#define TYPE_FORMAT_STRING_SIZE   21                                
#define PROC_FORMAT_STRING_SIZE   67                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _Hen_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } Hen_MIDL_TYPE_FORMAT_STRING;

typedef struct _Hen_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } Hen_MIDL_PROC_FORMAT_STRING;

typedef struct _Hen_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } Hen_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const Hen_MIDL_TYPE_FORMAT_STRING Hen__MIDL_TypeFormatString;
extern const Hen_MIDL_PROC_FORMAT_STRING Hen__MIDL_ProcFormatString;
extern const Hen_MIDL_EXPR_FORMAT_STRING Hen__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAsyncHenEventHandler_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAsyncHenEventHandler_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAsyncHen_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAsyncHen_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const Hen_MIDL_PROC_FORMAT_STRING Hen__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure OnCluck */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 24 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEventHandler */

/* 30 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 32 */	NdrFcLong( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x3 ),	/* 3 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 46 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter handler */

/* 54 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 56 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 58 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const Hen_MIDL_TYPE_FORMAT_STRING Hen__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  4 */	NdrFcLong( 0x2c9db197 ),	/* 748532119 */
/*  8 */	NdrFcShort( 0x83b9 ),	/* -31815 */
/* 10 */	NdrFcShort( 0x47c3 ),	/* 18371 */
/* 12 */	0xbe,		/* 190 */
			0x14,		/* 20 */
/* 14 */	0xae,		/* 174 */
			0xd2,		/* 210 */
/* 16 */	0x9d,		/* 157 */
			0xaa,		/* 170 */
/* 18 */	0x1b,		/* 27 */
			0xb1,		/* 177 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAsyncHenEventHandler, ver. 0.0,
   GUID={0x2c9db197,0x83b9,0x47c3,{0xbe,0x14,0xae,0xd2,0x9d,0xaa,0x1b,0xb1}} */

#pragma code_seg(".orpc")
static const unsigned short IAsyncHenEventHandler_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IAsyncHenEventHandler_ProxyInfo =
    {
    &Object_StubDesc,
    Hen__MIDL_ProcFormatString.Format,
    &IAsyncHenEventHandler_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAsyncHenEventHandler_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Hen__MIDL_ProcFormatString.Format,
    &IAsyncHenEventHandler_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IAsyncHenEventHandlerProxyVtbl = 
{
    &IAsyncHenEventHandler_ProxyInfo,
    &IID_IAsyncHenEventHandler,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IAsyncHenEventHandler::OnCluck */
};

const CInterfaceStubVtbl _IAsyncHenEventHandlerStubVtbl =
{
    &IID_IAsyncHenEventHandler,
    &IAsyncHenEventHandler_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IAsyncHen, ver. 0.0,
   GUID={0x03662d63,0xac6a,0x4e70,{0xb7,0x68,0x83,0xa3,0xc3,0x9d,0x26,0xaa}} */

#pragma code_seg(".orpc")
static const unsigned short IAsyncHen_FormatStringOffsetTable[] =
    {
    30
    };

static const MIDL_STUBLESS_PROXY_INFO IAsyncHen_ProxyInfo =
    {
    &Object_StubDesc,
    Hen__MIDL_ProcFormatString.Format,
    &IAsyncHen_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAsyncHen_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Hen__MIDL_ProcFormatString.Format,
    &IAsyncHen_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IAsyncHenProxyVtbl = 
{
    &IAsyncHen_ProxyInfo,
    &IID_IAsyncHen,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IAsyncHen::SetEventHandler */
};

const CInterfaceStubVtbl _IAsyncHenStubVtbl =
{
    &IID_IAsyncHen,
    &IAsyncHen_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    Hen__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x8000265, /* MIDL Version 8.0.613 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _Hen_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IAsyncHenProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAsyncHenEventHandlerProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _Hen_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IAsyncHenStubVtbl,
    ( CInterfaceStubVtbl *) &_IAsyncHenEventHandlerStubVtbl,
    0
};

PCInterfaceName const _Hen_InterfaceNamesList[] = 
{
    "IAsyncHen",
    "IAsyncHenEventHandler",
    0
};


#define _Hen_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Hen, pIID, n)

int __stdcall _Hen_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _Hen, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _Hen, 2, *pIndex )
    
}

const ExtendedProxyFileInfo Hen_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Hen_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Hen_StubVtblList,
    (const PCInterfaceName * ) & _Hen_InterfaceNamesList,
    0, /* no delegation */
    & _Hen_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

