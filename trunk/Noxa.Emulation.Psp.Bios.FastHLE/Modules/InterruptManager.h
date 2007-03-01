// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

#pragma once

#include "NoxaShared.h"
#include "ModulesShared.h"
#include "Module.h"

using namespace System;
using namespace System::Diagnostics;
using namespace Noxa::Emulation::Psp;
using namespace Noxa::Emulation::Psp::Bios;

namespace Noxa {
	namespace Emulation {
		namespace Psp {
			namespace Bios {
				namespace Modules {

					ref class InterruptManager : public Module
					{
					public:
						InterruptManager( Kernel^ kernel ) : Module( kernel ) {}
						~InterruptManager(){}

						property String^ Name { virtual String^ get() override { return "InterruptManager"; } }

						//virtual void Start() override;
						//virtual void Stop() override;
						//virtual void Clear() override;

					internal:
						//virtual void* QueryNativePointer( uint nid ) override;

					public: // ------ Implemented calls ------

					public: // ------ Stubbed calls ------

						[NotImplemented]
						[BiosFunction( 0xCA04A2B9, "sceKernelRegisterSubIntrHandler" )] [Stateless]
						// /user/pspintrman.h:119: int sceKernelRegisterSubIntrHandler(int intno, int no, void *handler, void *arg);
						int sceKernelRegisterSubIntrHandler( int intno, int no, int handler, int arg ){ return NISTUBRETURN; }

						[NotImplemented]
						[BiosFunction( 0xD61E6961, "sceKernelReleaseSubIntrHandler" )] [Stateless]
						// /user/pspintrman.h:129: int sceKernelReleaseSubIntrHandler(int intno, int no);
						int sceKernelReleaseSubIntrHandler( int intno, int no ){ return NISTUBRETURN; }

						[NotImplemented]
						[BiosFunction( 0xFB8E22EC, "sceKernelEnableSubIntr" )] [Stateless]
						// /user/pspintrman.h:139: int sceKernelEnableSubIntr(int intno, int no);
						int sceKernelEnableSubIntr( int intno, int no ){ return NISTUBRETURN; }

						[NotImplemented]
						[BiosFunction( 0x8A389411, "sceKernelDisableSubIntr" )] [Stateless]
						// /user/pspintrman.h:149: int sceKernelDisableSubIntr(int intno, int no);
						int sceKernelDisableSubIntr( int intno, int no ){ return NISTUBRETURN; }

						[NotImplemented]
						[BiosFunction( 0xD2E8363F, "QueryIntrHandlerInfo" )] [Stateless]
						// /user/pspintrman.h:170: int QueryIntrHandlerInfo(SceUID intr_code, SceUID sub_intr_code, PspIntrHandlerOptionParam *data);
						int QueryIntrHandlerInfo( int intr_code, int sub_intr_code, int data ){ return NISTUBRETURN; }

					};
				
				}
			}
		}
	}
}

/* GenerateStubsV2: auto-generated - 3B78F5CE */
