#include "arena.h"

int arenaInit(ARENA* arena, size_t size)
{
	// ?? Check if the arena passed is not actually NULL?
	if(arena == NULL) return -1;

	arena->startAddress = (LPVOID) VirtualAlloc(
		NULL,						// NO DEFAULT START ADDRESS
		size,						// SIZE TO COMMIT
		MEM_COMMIT | MEM_RESERVE,	// COMMIT & RESERVE THE MEMORY
		PAGE_READWRITE				// ENABLE READ/WRITE ACCESS
		);

	if(arena->startAddress != NULL)
	{
		// Initialise arena
		arena->size = size;
		arena->currentUsed = 0;
		return 0;
	} 
	else
	{
		arena->size = 0;
		arena->currentUsed = 0;
		return -1;	
	}


}

void* arenaAlloc(ARENA* arena, size_t size)
{
	if(arena->size - arena->currentUsed > size)
	{
		// If we have space, give out the start address and
		// increment the used bytes counter
		char* returnAddress = arena->startAddress + arena->currentUsed;
		arena->currentUsed += size;
		return returnAddress;
	}
	else
	{
		// If no space, return NULL
		return NULL;
	}
}