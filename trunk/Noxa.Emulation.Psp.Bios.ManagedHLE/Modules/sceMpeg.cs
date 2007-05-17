// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

//#define PRETENDVALID

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;

using Noxa.Utilities;
using Noxa.Emulation.Psp;
using Noxa.Emulation.Psp.Bios;
using Noxa.Emulation.Psp.Cpu;

namespace Noxa.Emulation.Psp.Bios.ManagedHLE.Modules
{
	class sceMpeg : Module
	{
		#region Properties

		public override string Name
		{
			get
			{
				return "sceMpeg";
			}
		}

		#endregion

		#region State Management

		public sceMpeg( Kernel kernel )
			: base( kernel )
		{
		}

		public override void Start()
		{
		}

		public override void Stop()
		{
		}

		#endregion

#if PRETENDVALID
		public const int DummyReturn = 0;
#else
		public const int DummyReturn = Module.NotImplementedReturn;
#endif

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x21FF80E4, "sceMpegQueryStreamOffset" )]
		public int sceMpegQueryStreamOffset() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x611E9E11, "sceMpegQueryStreamSize" )]
		public int sceMpegQueryStreamSize() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x682A619B, "sceMpegInit" )]
		public int sceMpegInit() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x874624D6, "sceMpegFinish" )]
		public void sceMpegFinish() { }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xC132E22F, "sceMpegQueryMemSize" )]
		public int sceMpegQueryMemSize() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xD8C5F121, "sceMpegCreate" )]
		public int sceMpegCreate() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x606A4649, "sceMpegDelete" )]
		public int sceMpegDelete() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x42560F23, "sceMpegRegistStream" )]
		public int sceMpegRegistStream() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x591A4AA2, "sceMpegUnRegistStream" )]
		public void sceMpegUnRegistStream() { }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xA780CF7E, "sceMpegMallocAvcEsBuf" )]
		public int sceMpegMallocAvcEsBuf() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xCEB870B1, "sceMpegFreeAvcEsBuf" )]
		public void sceMpegFreeAvcEsBuf() { }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xF8DCB679, "sceMpegQueryAtracEsSize" )]
		public int sceMpegQueryAtracEsSize() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xC02CF6B5, "sceMpegQueryPcmEsSize" )]
		public int sceMpegQueryPcmEsSize() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x167AFD9E, "sceMpegInitAu" )]
		public int sceMpegInitAu() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x234586AE, "sceMpegChangeGetAvcAuMode" )]
		public int sceMpegChangeGetAvcAuMode() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x9DCFB7EA, "sceMpegChangeGetAuMode" )]
		public int sceMpegChangeGetAuMode() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xFE246728, "sceMpegGetAvcAu" )]
		public int sceMpegGetAvcAu() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x8C1E027D, "sceMpegGetPcmAu" )]
		public int sceMpegGetPcmAu() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xE1CE83A7, "sceMpegGetAtracAu" )]
		public int sceMpegGetAtracAu() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x500F0429, "sceMpegFlushStream" )]
		public int sceMpegFlushStream() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x707B7629, "sceMpegFlushAllStream" )]
		public int sceMpegFlushAllStream() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x0E3C2E9D, "sceMpegAvcDecode" )]
		public int sceMpegAvcDecode() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x0F6C18D7, "sceMpegAvcDecodeDetail" )]
		public int sceMpegAvcDecodeDetail() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xA11C7026, "sceMpegAvcDecodeMode" )]
		public int sceMpegAvcDecodeMode() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x740FCCD1, "sceMpegAvcDecodeStop" )]
		public int sceMpegAvcDecodeStop() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x800C44DF, "sceMpegAtracDecode" )]
		public int sceMpegAtracDecode() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xD7A29F46, "sceMpegRingbufferQueryMemSize" )]
		public int sceMpegRingbufferQueryMemSize() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x37295ED8, "sceMpegRingbufferConstruct" )]
		public int sceMpegRingbufferConstruct() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x13407F13, "sceMpegRingbufferDestruct" )]
		public void sceMpegRingbufferDestruct() { }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xB240A59E, "sceMpegRingbufferPut" )]
		public int sceMpegRingbufferPut() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xB5F6DC87, "sceMpegRingbufferAvailableSize" )]
		public int sceMpegRingbufferAvailableSize() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x11CAB459, "sceMpeg_11CAB459" )]
		public int sceMpeg_11CAB459() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x3C37A7A6, "sceMpeg_3C37A7A6" )]
		public int sceMpeg_3C37A7A6() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xB27711A8, "sceMpeg_B27711A8" )]
		public int sceMpeg_B27711A8() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xD4DD6E75, "sceMpeg_D4DD6E75" )]
		public int sceMpeg_D4DD6E75() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xC345DED2, "sceMpeg_C345DED2" )]
		public int sceMpeg_C345DED2() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0xCF3547A2, "sceMpegAvcDecodeDetail2" )]
		public int sceMpegAvcDecodeDetail2() { return DummyReturn; }

#if !PRETENDVALID
		[NotImplemented]
#endif
		[Stateless]
		[BiosFunction( 0x988E9E12, "sceMpeg_988E9E12" )]
		public int sceMpeg_988E9E12() { return DummyReturn; }
	}
}

/* GenerateStubsV2: auto-generated - A5BF8D85 */