#include "arena.h"

int main(int argc, char* argv[])
{
	ARENA* baseArena = {0};
	u32 arenaSize = 4096 * 2;	//8KB
	if(!arenaInit(baseArena, arenaSize))
	{
		printf("Allocation failed\n");
	}

	float* array = arenaAlloc(baseArena, 100 * sizeof(float));
	if(array == NULL)
	{
		printf("Failed to allocate memory");
	}
}