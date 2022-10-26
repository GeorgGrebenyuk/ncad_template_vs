// NRX_Template.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "NRX_Template.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void hello_nrx()
{
	acutPrintf(L"\nHello, NRX!\n");
}
