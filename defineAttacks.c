#include "game_structs.h"
#include <string.h>
#include <stdio.h>

attack* defineAttacks(){
	static attack allAttacks[NUMATTACKS];
	
	attack scratch;
	strcpy(scratch.name, "SCRATCH");
	scratch.damage = 5;
	scratch.PP = 10;
	scratch.numValue = 0;
	allAttacks[scratch.numValue] = scratch;

	attack quickSlash;
	strcpy(quickSlash.name, "QUICK SLASH");
	quickSlash.damage = 10;
	quickSlash.PP = 15;
	quickSlash.numValue = 1;
	allAttacks[quickSlash.numValue] = scratch;

	return allAttacks;
}