// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

#pragma once

#include "VideoCommands.h"
#include "VideoPacket.h"
#include "VideoDisplayList.h"

namespace Noxa {
	namespace Emulation {
		namespace Psp {
			namespace Video {
				namespace Native {

					typedef struct VideoApi_t
					{
						// Enqueue a new display list
						int (*EnqueueList)( VideoDisplayList* list );

						// Dequeue an existing list (abort)
						void (*DequeueList)( int listId );

						// Sync a list
						void (*SyncList)( int listId );

						// Sync the video system
						void (*Sync)();

					} VideoApi;

				}
			}
		}
	}
}
