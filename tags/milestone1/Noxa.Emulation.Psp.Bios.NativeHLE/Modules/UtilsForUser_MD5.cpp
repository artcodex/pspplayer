// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

#include "Stdafx.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "UtilsForUser.h"
#include "Kernel.h"

using namespace System;
using namespace System::Diagnostics;
using namespace Noxa::Emulation::Psp;
using namespace Noxa::Emulation::Psp::Bios;
using namespace Noxa::Emulation::Psp::Bios::Modules;

/** Structure to hold the MD5 context */
typedef struct _SceKernelUtilsMd5Context {
        unsigned int 	h[4];
        unsigned int 	pad;
        short unsigned int 	usRemains;
        short unsigned int 	usComputed;
        long long unsigned int 	ullTotalLen;
        unsigned char 	buf[64];
} SceKernelUtilsMd5Context;

//http://svn.ps2dev.org/filedetails.php?repname=psp&path=%2Ftrunk%2Fpspsdk%2Fsrc%2Fuser%2Fpsputils.h&rev=1721&sc=1