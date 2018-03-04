#include "auxillary_functions.h"
#include "game_structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <altera_avalon_pio_regs.h>

int main() {
	attack* allAttacks;
	allAttacks = defineAttacks();
	pokemon* allPokemon;
	allPokemon = definePokemon(allAttacks);
	player whoAmI;
	whoAmI = definePlayer(allPokemon, rand() % 8, rand() % 8);

	printf("%s\n", whoAmI.pokemonParty[0].name);

	// intializeConnection();

	player rival = sendInfoToOppo(&whoAmI);

	// bool myturn = RPS();

	while (1) {

	}



	/* printf("%s\n", allPokemon[0].name);
	printf("%s\n", allPokemon[0].attacks[0].name);
	printf("%s\n", allAttacks[0].name); */
}
