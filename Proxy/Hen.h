

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Hen_h__
#define __Hen_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAsyncHenEventHandler_FWD_DEFINED__
#define __IAsyncHenEventHandler_FWD_DEFINED__
typedef interface IAsyncHenEventHandler IAsyncHenEventHandler;

#endif 	/* __IAsyncHenEventHandler_FWD_DEFINED__ */


#ifndef __IAsyncHen_FWD_DEFINED__
#define __IAsyncHen_FWD_DEFINED__
typedef interface IAsyncHen IAsyncHen;

#endif 	/* __IAsyncHen_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAsyncHenEventHandler_INTERFACE_DEFINED__
#define __IAsyncHenEventHandler_INTERFACE_DEFINED__

/* interface IAsyncHenEventHandler */
/* [object][uuid] */ 


EXTERN_C const IID IID_IAsyncHenEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2c9db197-83b9-47c3-be14-aed29daa1bb1")
    IAsyncHenEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnCluck( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsyncHenEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsyncHenEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsyncHenEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsyncHenEventHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnCluck )( 
            IAsyncHenEventHandler * This);
        
        END_INTERFACE
    } IAsyncHenEventHandlerVtbl;

    interface IAsyncHenEventHandler
    {
        CONST_VTBL struct IAsyncHenEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsyncHenEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsyncHenEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsyncHenEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsyncHenEventHandler_OnCluck(This)	\
    ( (This)->lpVtbl -> OnCluck(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsyncHenEventHandler_INTERFACE_DEFINED__ */


#ifndef __IAsyncHen_INTERFACE_DEFINED__
#define __IAsyncHen_INTERFACE_DEFINED__

/* interface IAsyncHen */
/* [object][uuid] */ 


EXTERN_C const IID IID_IAsyncHen;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("03662d63-ac6a-4e70-b768-83a3c39d26aa")
    IAsyncHen : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetEventHandler( 
            IAsyncHenEventHandler *handler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsyncHenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsyncHen * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsyncHen * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsyncHen * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventHandler )( 
            IAsyncHen * This,
            IAsyncHenEventHandler *handler);
        
        END_INTERFACE
    } IAsyncHenVtbl;

    interface IAsyncHen
    {
        CONST_VTBL struct IAsyncHenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsyncHen_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsyncHen_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsyncHen_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsyncHen_SetEventHandler(This,handler)	\
    ( (This)->lpVtbl -> SetEventHandler(This,handler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsyncHen_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


