// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

#include "StdAfx.h"
#include "R4000Generator.h"
#include "R4000Cpu.h"
#include "R4000Core.h"
#include "R4000Memory.h"
#include "R4000GenContext.h"
#include "R4000BiosStubs.h"

#include "Loader.hpp"
#include "CodeGenerator.hpp"

using namespace System::Diagnostics;
using namespace Noxa::Emulation::Psp;
using namespace Noxa::Emulation::Psp::Bios;
using namespace Noxa::Emulation::Psp::Cpu;
using namespace SoftWire;

extern uint _nativeSyscallCount;

#define LOGSYSCALLS

#define g context->Generator

void __syscallBounce( int address, int syscallId )
{
#ifdef LOGSYSCALLS
	R4000Cpu^ cpu = R4000Cpu::GlobalCpu;

	BiosFunction^ function = cpu->_syscalls[ syscallId ];
	Debug::Assert( function != nullptr );
	if( function != nullptr )
	{
		R4000Ctx* ctx = ( R4000Ctx* )cpu->_ctx;

		String^ args;
		Debug::Assert( function->ParameterCount <= 12 );
		switch( function->ParameterCount )
		{
		case 1:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ] );
			break;
		case 2:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ] );
			break;
		case 3:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ] );
			break;
		case 4:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ] );
			break;
		case 5:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ] );
			break;
		case 6:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ] );
			break;
		case 7:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ], ctx->Registers[ 10 ] );
			break;
		case 8:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ], ctx->Registers[ 10 ], ctx->Registers[ 11 ] );
			break;
		case 9:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ], ctx->Registers[ 10 ], ctx->Registers[ 11 ], -1 );
			break;
		case 10:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ], ctx->Registers[ 10 ], ctx->Registers[ 11 ], -1, -1 );
			break;
		case 11:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ], ctx->Registers[ 10 ], ctx->Registers[ 11 ], -1, -1, -1 );
			break;
		case 12:
			args = String::Format( "{0:X8}, {1:X8}, {2:X8}, {3:X8}, {4:X8}, {5:X8}, {6:X8}, {7:X8}, {8:X8}, {9:X8}, {10:X8}, {11:X8}", ctx->Registers[ 4 ], ctx->Registers[ 5 ], ctx->Registers[ 6 ], ctx->Registers[ 7 ], ctx->Registers[ 8 ], ctx->Registers[ 9 ], ctx->Registers[ 10 ], ctx->Registers[ 11 ], -1, -1, -1, -1 );
			break;
		default:
			args = "";
			break;
		}
		String^ log = String::Format( "{0}::{1}({2}) from 0x{3:X8}",
			function->Module->Name, function->Name, args, address - 4 );
		Debug::WriteLine( log );
	}
	else
	{
		String^ log = String::Format( "Syscall attempt to undefined syscall {0} (0x{0:X8}) from 0x{1:X8}", syscallId, address - 4 );
		Debug::WriteLine( log );
		Debugger::Break();
	}
#endif

#ifdef STATISTICS
	R4000Cpu::GlobalCpu->_stats->ManagedSyscallCount++;
#endif

	BiosShim^ shim = R4000Cpu::GlobalCpu->_syscallShims[ syscallId ];
	Debug::Assert( shim != nullptr );
	if( shim == nullptr )
		return;

#ifdef SYSCALLSTATS
	int currentStat = R4000Cpu::GlobalCpu->_syscallCounts[ syscallId ];
	R4000Cpu::GlobalCpu->_syscallCounts[ syscallId ] = currentStat + 1;
#endif

	shim();
}

GenerationResult SYSCALL( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, byte rd, byte shamt, byte function )
{
	int syscall = ( int )( ( code >> 6 ) & 0xFFFFF );

	BiosFunction^ biosFunction = R4000Cpu::GlobalCpu->_syscalls[ syscall ];
	bool willCall;
	bool canEmit;
	if( biosFunction != nullptr )
	{
		willCall = biosFunction->IsImplemented;

		// Take its word on its statelessness
		context->LastSyscallStateless = biosFunction->IsStateless;
		
		if( biosFunction->IsImplemented == true )
		{
			// If it is implemented we can only emit if it is also stateless
			canEmit = biosFunction->IsStateless;
		}
		else
		{
			// If not implemented we can always emit
			canEmit = true;

			if( pass == 0 )
			{
				Debug::WriteLine( String::Format( "R4000Generator: NID 0x{0:X8} {1} is not implemented",
					biosFunction->NID, biosFunction->Name ) );
			}
		}
	}
	else
	{
		willCall = false;

		// Assume stateless and we can emit
		canEmit = true;
		context->LastSyscallStateless = true;

		if( pass == 0 )
			Debug::WriteLine( String::Format( "R4000Generator: unregistered syscall attempt (at 0x{0:X8})", address ) );
	}

	context->UseSyscalls = true;

	if( pass == 1 )
	{
		// It's important that we save what we think is the current PC
		// If we had an UpdatePc, it means a branch has updated it before us
		// and we need to save it - otherwise, save the PC following us
		if( context->UpdatePC == true )
		{
			// Already changed
		}
		else
		{
			g->mov( MPC( CTX ), address + 4 );
			//g->mov( MPCVALID( CTX ), 1 );
		}

		// Override if we can - we do this regardless of whether or not the BIOS implements it
#ifdef OVERRIDESYSCALLS
		if( canEmit == true )
		{
			// Note we may not emit here!
			bool emitted = R4000Cpu::GlobalCpu->_biosStubs->EmitCall( context, g, address, biosFunction->NID );
			if( emitted == true  )
			{
				// If we emitted then we must be stateless
				context->LastSyscallStateless = true;

#ifdef GENDEBUG
				Debug::WriteLine( String::Format( "Overrode {0} with native method", biosFunction->Name ) );
#endif

				// Everything handled for us by our overrides
				g->mov( MREG( CTX, 2 ), EAX );

#ifdef STATISTICS
				g->inc( g->dword_ptr[ &_nativeSyscallCount ] );
#endif

				return GenerationResult::Syscall;
			}
		}
#endif
		
		if( willCall == true )
		{
			// Couldn't do a native stub, so use the thunk

			g->push( ( uint )syscall );
			// We push $ra as the address cause it is where the stub will go back to
			g->push( MREG( CTX, 31 ) );

			g->call( ( int )__syscallBounce );

			g->add( ESP, 8 );
		}
		else
		{
			// No native stub AND not implemented - uh oh!

			if( biosFunction != nullptr )
			{
				if( biosFunction->HasReturn == true )
				{
					g->mov( MREG( CTX, 2 ), ( int )-1 );
					if( biosFunction->DoubleWordReturn == true )
						g->mov( MREG( CTX, 3 ), ( int )-1 );
				}
			}
			else
			{
				// We don't even have a freaking function - just put -1 in $v0 and call it a day
				g->mov( MREG( CTX, 2 ), ( int )-1 );
			}
		}
	}

	return GenerationResult::Syscall;
}

GenerationResult BREAK( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, byte rd, byte shamt, byte function )
{
	if( pass == 0 )
	{
		//Debug::WriteLine( String::Format( "R4000Generator: BREAK not implemented (at 0x{0:X8})", address ) );
	}
	else if( pass == 1 )
	{
		g->int3();
	}
	return GenerationResult::Success;
}

GenerationResult SYNC( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, byte rd, byte shamt, byte function )
{
	// pg 629 - not needed?
	if( pass == 0 )
	{
		Debug::WriteLine( String::Format( "R4000Generator: SYNC not implemented (at 0x{0:X8})", address ) );
	}
	else if( pass == 1 )
	{
	}
	return GenerationResult::Success;
}

GenerationResult COP1( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, ushort imm )
{
	if( pass == 0 )
	{
	}
	else if( pass == 1 )
	{
	}
	return GenerationResult::Invalid;
}

GenerationResult COP2( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, ushort imm )
{
	if( pass == 0 )
	{
	}
	else if( pass == 1 )
	{
	}
	return GenerationResult::Invalid;
}

GenerationResult HALT( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, byte rd, byte shamt, byte function )
{
	if( pass == 0 )
	{
		Debug::WriteLine( String::Format( "R4000Generator: HALT not implemented (at 0x{0:X8})", address ) );
	}
	else if( pass == 1 )
	{
	}
	return GenerationResult::Success;
}

GenerationResult MFIC( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, byte rd, byte shamt, byte function )
{
	if( pass == 0 )
	{
		Debug::WriteLine( String::Format( "R4000Generator: MFIC not implemented (at 0x{0:X8})", address ) );
	}
	else if( pass == 1 )
	{
	}
	return GenerationResult::Success;
}

GenerationResult MTIC( R4000GenContext^ context, int pass, int address, uint code, byte opcode, byte rs, byte rt, byte rd, byte shamt, byte function )
{
	if( pass == 0 )
	{
		Debug::WriteLine( String::Format( "R4000Generator: MTIC not implemented (at 0x{0:X8})", address ) );
	}
	else if( pass == 1 )
	{
	}
	return GenerationResult::Success;
}
