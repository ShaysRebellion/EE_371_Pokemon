#include "game_structs.h"
#include <string.h>
#include <stdio.h>

//this function defines all of the attacks that will be in the game
//as we develop the game further we can add more attacks and play with
//the values. Follow this format to add an attack, and update NUMATTACKS
//in game_structs.h as we add more attacks.
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
	allAttacks[quickSlash.numValue] = quickSlash;
	allAttacks[2] = quickSlash;
	allAttacks[3] = quickSlash;

	return allAttacks;
}