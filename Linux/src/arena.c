#include "arena.h"

int arenaInit(MemoryArena* arena, size_t size)
{
	arena->startAddress = mmap(
		NULL,
		size,
		PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE,
		-1,
		0);

	if(arena->startAddress == NULL)
	{
		perror("Error");
		return -1;
	}

	arena->capacity = size;
	arena->stackTopPtr = 0;
	return 0;
}

void* arenaAlloc(MemoryArena* arena, size_t size)
{
	if(arena == NULL)
	{
		printf("Arena is NULL\n");
		return NULL;
	}

	if(size > arena->capacity - arena->stackTopPtr)
	{
		printf("Not enough memory in arena\n");
		return NULL;
	}

	void* ptr = arena->startAddress + arena->stackTopPtr;
	arena->stackTopPtr += size;
	return ptr;
}

int arenaReset(MemoryArena* arena)
{
	if(arena == NULL)
	{
		printf("Arena is NULL\n");
		return -1;
	}

	arena->stackTopPtr = 0;
	return 0;
}