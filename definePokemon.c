#include "game_structs.h"
#include <string.h>
#include <stdio.h>
pokemon* definePokemon(attack* allAttacks){
	static pokemon allPokemon[NUMPOKEMON];

	pokemon charmander;
	strcpy(charmander.name, "CHARMANDER");
	static attack moveSet[4];
	moveSet[0] = allAttacks[0];
	moveSet[1] = allAttacks[1];
	moveSet[2] = allAttacks[2];
	moveSet[3] = allAttacks[3];
	charmander.attacks = moveSet;
	charmander.health = 15;
	charmander.PP = 10;
	charmander.numValue = 0;
	allPokemon[charmander.numValue] = charmander;

	return allPokemon;
}