#include "game_structs.h"
#include <string.h>
#include <stdio.h>
pokemon* definePokemon(attack* allAttacks){
	static pokemon allPokemon[NUMPOKEMON];

	pokemon charmander;
	strcpy(charmander.name, "CHARMANDER");
	attack moveSet[4] = {allAttacks[0], allAttacks[1], allAttacks[2], allAttacks[3]};
	charmander.attacks = moveSet;
	charmander.health = 15;
	charmander.PP = 10;
	charmander.numValue = 0;
	allPokemon[charmander.numValue] = charmander;
	printf("%s\n", allPokemon[0].attacks[0].name);
	return allPokemon;
}