#include "game_structs.h"
#include <string.h>
#include <stdio.h>
void definePokemon(attack* allAttacks, pokemon* allPokemon){
	static pokemon charmander;
	strcpy(charmander.name, "CHARMANDER");
	attack moveSet[4] = {allAttacks[0], allAttacks[1], allAttacks[2], allAttacks[3]};
	charmander.attacks = moveSet;
	charmander.health = 15;
	charmander.PP = 10;
	charmander.numValue = 0;
	allPokemon[charmander.numValue] = charmander;
}