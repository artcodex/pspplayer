using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Noxa.Emulation.Psp.Games;

namespace Noxa.Emulation.Psp.Debugging
{
	class ElfDebugData : IProgramDebugData
	{
		private List<ElfMethod> _methods;
		private Dictionary<int, ElfMethod> _methodLookup;

		public ElfDebugData( Stream source )
		{
			_methods = GetMethods( source );
			if( _methods == null )
				throw new InvalidDataException( "The given ELF program did not contain debugging information or was not valid." );
			_methodLookup = new Dictionary<int, ElfMethod>( _methods.Count );
			foreach( ElfMethod method in _methods )
				_methodLookup.Add( method.EntryAddress, method );
		}

		#region Method detection/etc

		private List<ElfMethod> GetMethods( Stream source )
		{
			ElfFile elf = new ElfFile( source );
			return null;
		}

		#endregion

		public Method FindMethod( int address )
		{
			if( _methodLookup.ContainsKey( address ) == true )
				return _methodLookup[ address ];
			else
			{
				for( int n = 0; n < _methods.Count; n++ )
				{
					ElfMethod method = _methods[ n ];
					if( ( method.EntryAddress <= address ) &&
						( ( method.EntryAddress + method.Instructions.Count ) > address ) )
						return method;
				}
				return null;
			}
		}

		#region ElfMethod

		private class ElfMethod : Method
		{
			public ElfMethod( int entryAddress, string name )
				: base( entryAddress, name )
			{
			}
		}

		#endregion
	}
}