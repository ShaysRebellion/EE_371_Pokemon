#include "auxillary_functions.h"
#include "game_structs.h"
#include <stdio.h>
#include <string.h>

int main(){
	attack allAttacks[NUMATTACKS];
	defineAttacks(allAttacks);
	pokemon allPokemon[NUMPOKEMON];
	definePokemon(allAttacks, allPokemon);
	printf("%s\n", allPokemon[0].name);
	printf("%s\n", allPokemon[0].attacks[0].damage);
	printf("%s\n", allAttacks[0].name);
}