// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

#include "Stdafx.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>
#include "Tracer.h"

using namespace Noxa::Emulation::Psp;

HANDLE Tracer::_file;

void Tracer::OpenFile( const char* fileName )
{
	_file = ::CreateFileA( fileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL );
}

void Tracer::CloseFile()
{
	if( _file != NULL )
		::CloseHandle( _file );
	_file = NULL;
}

#pragma unmanaged
void Tracer::WriteLine( const char* line )
{
	if( _file == NULL )
		return;
	int length = strlen( line );
	int dummy;
	::WriteFile( _file, line, length, ( LPDWORD )&dummy, NULL );
}
#pragma managed
