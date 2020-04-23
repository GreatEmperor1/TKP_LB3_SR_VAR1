// Fun.cpp : Implementation of CFun

#include "stdafx.h"
#include "Fun.h"


// CFun

STDMETHODIMP CFun::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IFun
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CFun::Fun11(LONG x11, LONG y11, FLOAT* z11)
{
	// TODO: Add your implementation code here
	*z11 = x11 / (float)y11;
	return S_OK;
}


STDMETHODIMP CFun::Fun12(LONG a12, LONG b12, LONG c12, FLOAT* d12)
{
	// TODO: Add your implementation code here
	*d12 = a12 / (float)b12 * c12;
	return S_OK;
}





STDMETHODIMP CFun::Fun13(DOUBLE in13, DOUBLE* out13)
{
	// TODO: Add your implementation code here
	*out13 = in13*1.65;
	return S_OK;
}
