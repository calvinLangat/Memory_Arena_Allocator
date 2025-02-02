#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <inttypes.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;

typedef struct
{
	char* startAddress;		// Mimic rbp
	size_t capacity;
	size_t stackTopPtr;		// Mimic rsp					
} MemoryArena;

int arenaInit(MemoryArena* arena, size_t size);
void* arenaAlloc(MemoryArena* arena, size_t size);
int arenaReset(MemoryArena* arena);

