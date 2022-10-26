// NRX_Template.h : main header file for the NRX_Template DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


void hello_nrx();
extern "C" __declspec(dllexport) AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
    switch (msg)
    {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(appId);
        acrxDynamicLinker->registerAppMDIAware(appId);

        acedRegCmds->addCommand(L"HELLONRX_GROUP",
            L"_HELLONRX",
            L"HELLONRX",
            ACRX_CMD_TRANSPARENT,
            hello_nrx);
        break;

    case AcRx::kUnloadAppMsg:
        acedRegCmds->removeGroup(L"HELLONRX_GROUP");
        break;
    }

    return AcRx::kRetOK;
}