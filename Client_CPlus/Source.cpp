//
// DClient.cpp - Dispatch client implementation
//
//   This client connects to the IX dual interface
//   through the dispinterface.
//
#include <windows.h>
#include <stdio.h>

int main()
{
	DWORD clsctx;
	clsctx = CLSCTX_INPROC_SERVER;

	HRESULT hr = OleInitialize(NULL);
	if (FAILED(hr))
	{
		printf("\nFailed to initialize. 0x%80X", hr);
		return 1;
	}

	// Get the CLSID for the application.
	wchar_t progid[] = L"Server.CoFun.1"; //áåðåì èç MyMath.rgs
	CLSID clsid;
	hr = ::CLSIDFromProgID(progid, &clsid);
	if (FAILED(hr))
	{
		printf("\nFailed to get CLSID. 0x%80X", hr);
		return 1;
	}

	// Create the component.
	IDispatch* pIDispatch = NULL;
	hr = ::CoCreateInstance(clsid,
		NULL,
		clsctx,
		IID_IDispatch,
		(void**)&pIDispatch);
	if (FAILED(hr))
	{
		printf("\nCreate instance failed.0x%80X", hr);
		OleUninitialize();
		return 1;
	}
	printf("\nCoCreateInstance succeeded.\n");

	//++++++++++++++ ÔÓÍÊÖÈß FUN61 ++++++++++++++++//

	// First we need to get the IDs for the function names.
	printf("\nGet DispID for function \"Fun11\".");

	DISPID dispid;
	OLECHAR* name = L"Fun11";//ìîæíî ïèñàòü WCHAR
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name,
		1,
		GetUserDefaultLCID(),
		&dispid);
	if (FAILED(hr))
	{
		printf("\nQuery GetIDsOfNames failed.0x%80X", hr);
		pIDispatch->Release();
		return 1;
	}
	// Build up the parameters for the invoke call.
	LONG x11 = 4;
	LONG y11 = 5;
	// Allocate and initialize a VARIANT argument.
	VARIANTARG varg[2];
	::VariantInit(&varg[0]);     // Initialize the VARIANT.
	varg[0].vt = VT_I4;			 // Type of VARIANT data
	varg[0].lVal = x11;			// Data for the VARIANT

	::VariantInit(&varg[1]);    // Initialize the VARIANT.
	varg[1].vt = VT_I4;         // Type of VARIANT data
	varg[1].lVal = y11;			// Data for the VARIANT

	// Fill in the DISPPARAMS structure.
	DISPPARAMS param;
	param.cArgs = 2;                 // Number of arguments
	param.rgvarg = varg;            // Arguments
	param.cNamedArgs = 0;            // Number of named args
	param.rgdispidNamedArgs = NULL;  // Named arguments

	// Allocate and initialize a VARIANT for the Result.
	VARIANT Result;
	::VariantInit(&Result);
	printf("\nInvoke the function \"Fun11\".");
	hr = pIDispatch->Invoke(dispid,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_METHOD,
		&param,
		&Result,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("\nInvoke call failed.0x%80X", hr);
		pIDispatch->Release();
		return 1;
	}
	
	// Display the returned string.
	if (Result.vt == VT_R4)
	{
		printf("\nReturned from component: z11 = %f\n", Result.fltVal);

	}

	//++++++++++++++ ÔÓÍÊÖÈß FUN62 ++++++++++++++++//

	// First we need to get the IDs for the function names.
	printf("\nGet DispID for function \"Fun12\".");

	DISPID dispid1;
	OLECHAR* name1 = L"Fun12";//ìîæíî ïèñàòü WCHAR
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name1,
		1,
		GetUserDefaultLCID(),
		&dispid1);
	if (FAILED(hr))
	{
		printf("\nQuery GetIDsOfNames failed.0x%80X", hr);
		pIDispatch->Release();
		return 1;
	}

	LONG a12 = 10;
	LONG b12 = 3;
	LONG c12 = 100;
	// Allocate and initialize a VARIANT argument.
	VARIANTARG varg1[3];
	::VariantInit(&varg1[0]);     // Initialize the VARIANT.
	varg1[0].vt = VT_I4;			 // Type of VARIANT data
	varg1[0].lVal = a12;			// Data for the VARIANT

	::VariantInit(&varg1[1]);    // Initialize the VARIANT.
	varg1[1].vt = VT_I4;         // Type of VARIANT data
	varg1[1].lVal = b12;			// Data for the VARIANT

	::VariantInit(&varg1[2]);    // Initialize the VARIANT.
	varg1[2].vt = VT_I4;         // Type of VARIANT data
	varg1[2].lVal = c12;			// Data for the VARIANT

								// Fill in the DISPPARAMS structure.
	DISPPARAMS param1;
	param1.cArgs = 3;                 // Number of arguments
	param1.rgvarg = varg1;            // Arguments
	param1.cNamedArgs = 0;            // Number of named args
	param1.rgdispidNamedArgs = NULL;  // Named arguments

									 // Allocate and initialize a VARIANT for the Result.
	VARIANT Result1;
	::VariantInit(&Result1);
	printf("\nInvoke the function \"Fun12\".");
	hr = pIDispatch->Invoke(dispid1,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_METHOD,
		&param1,
		&Result1,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("\nInvoke call failed.0x%80X", hr);
		pIDispatch->Release();
		return 1;
	}


	// Display the returned string.
	if (Result1.vt == VT_R4)
	{
		printf("\nReturned from component: d12 = %f\n", Result1.fltVal);

	}

	//++++++++++++++ ÔÓÍÊÖÈß FUN63 ++++++++++++++++//

	// First we need to get the IDs for the function names.
	printf("\nGet DispID for function \"Fun13\".");

	DISPID dispid2;
	OLECHAR* name2 = L"Fun13";//ìîæíî ïèñàòü WCHAR
	hr = pIDispatch->GetIDsOfNames(IID_NULL,
		&name2,
		1,
		GetUserDefaultLCID(),
		&dispid2);
	if (FAILED(hr))
	{
		printf("\nQuery GetIDsOfNames failed.0x%80X", hr);
		pIDispatch->Release();
		return 1;
	}

	DOUBLE in13 = 4.5;
	
	// Allocate and initialize a VARIANT argument.
	VARIANTARG varg2;
	::VariantInit(&varg2);     // Initialize the VARIANT.
	varg2.vt = VT_R8;			 // Type of VARIANT data
	varg2.dblVal = in13;			// Data for the VARIANT

										// Fill in the DISPPARAMS structure.
	DISPPARAMS param2;
	param2.cArgs = 1;                 // Number of arguments
	param2.rgvarg = &varg2;            // Arguments
	param2.cNamedArgs = 0;            // Number of named args
	param2.rgdispidNamedArgs = NULL;  // Named arguments

									  // Allocate and initialize a VARIANT for the Result.
	VARIANT Result2;
	::VariantInit(&Result2);
	printf("\nInvoke the function \"Fun13\".");
	hr = pIDispatch->Invoke(dispid2,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_METHOD,
		&param2,
		&Result2,
		NULL,
		NULL);
	if (FAILED(hr))
	{
		printf("\nInvoke call failed.0x%80X", hr);
		pIDispatch->Release();
		return 1;
	}


	// Display the returned string.
	if (Result2.vt == VT_R8)
	{
		printf("\nReturned from component: out13 = %f\n", Result2.dblVal);

	}

	// Release the dispatch interface.
	pIDispatch->Release();

	// Uninitialize the OLE library.
	OleUninitialize();
	return 0;
}
