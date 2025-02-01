#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <inttypes.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t s64;
typedef int32_t s32;


typedef struct arena{
	char* startAddress;	// CHAR* enables us to do pointer arithmetic
	u64 size;
	u64 currentUsed;
}ARENA;

int arenaInit(ARENA* arena, size_t size);
void* arenaAlloc(ARENA* arena, size_t size);