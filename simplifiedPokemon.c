#include "auxillary_functions.h"
#include "game_structs.h"
#include <stdio.h>
#include <string.h>

int main(){
	attack* allAttacks;
	allAttacks = defineAttacks();
	pokemon* allPokemon;
	allPokemon = definePokemon(allAttacks);
	printf("%s\n", allPokemon[0].name);
	printf("%s\n", allPokemon[0].attacks[0].name);
	printf("%s\n", allAttacks[0].name);
}