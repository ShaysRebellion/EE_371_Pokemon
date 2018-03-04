#include "auxillary_functions.h"
#include "game_structs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <altera_avalon_pio_regs.h>


int main() {

  attack* allAttacks = defineAttacks();

	pokemon* allPokemon = definePokemon(allAttacks);
	player whoAmI;
	whoAmI = definePlayer(allPokemon, rand() % 8, rand() % 8);

	printf("%s\n", whoAmI.pokemonParty[0].name);

	// intializeConnection();

	player rival = sendInfoToOppo(&whoAmI, allPokemon);
	printf("Rival: %s  %s\n", rival.pokemonParty[0].name, rival.pokemonParty[1].name);

	bool myturn = RPS();

	while (1) {
		bool gameover = false;
		if (myturn) {
			alt_putstr("Rival: pokemon: %s  hp: %d\n", rival.pokemonParty[rival.whichPokemon].name, rival.hp);
			alt_putstr("Me: pokemon: %s  hp: %d\n", whoAmI.pokemonParty[whoAmI.whichPokemon].name, whoAmI.hp);
			alt_putstr("Attack Moves: 0 %s   1 %s   2 %s  3 %s\n", whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[0], whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[1], whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[2], whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[3]);
			int whichAttack = atl_getchar();
			while(1) {
				send((char)whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[whichAttack].numValue);
				if (receive() == -2) { // Opponent received attack.
					myturn = false;
					gameover = attackMove(&rival, whoAmI.pokemonParty[whoAmI.whichPokemon].numValue, whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[whichAttack].numValue, allAttacks, allPokemon);
					if (gameover) {
						alt_putstr("I won. I am so good.");
						gameover = true;
					}
					break;
				}
			}
		} else {
			while (1) {
				int received = receive();
				if (received == -1) continue;
				myturn = true;
				int whichAttack = received;
				gameover = attackMove(&whoAmI, rival.pokemonParty[rival.whichPokemon].numValue, rival.pokemonParty[rival.whichPokemon].attacks[whichAttack].numValue, allAttacks, allPokemon);
				if (gameover) {
					alt_putstr("I lost.");
					gameover = true;
				}
				send(-2);
				break;
			}
		}
		if (gameover) {
			break;
		}

	}




	/* printf("%s\n", allPokemon[0].name);
	printf("%s\n", allPokemon[0].attacks[0].name);
	printf("%s\n", allAttacks[0].name); */
}
