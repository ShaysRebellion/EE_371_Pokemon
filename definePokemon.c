#include "game_structs.h"
#include <string.h>
#include <stdio.h>
pokemon* definePokemon(attack* allAttacks){
	static pokemon allPokemon[NUMPOKEMON];

	pokemon charmander;
	strcpy(charmander.name, "CHARMANDER");
	static attack moveSet0[4];
	moveSet0[0] = allAttacks[0];
	moveSet0[1] = allAttacks[1];
	moveSet0[2] = allAttacks[2];
	moveSet0[3] = allAttacks[3];
	charmander.attacks = moveSet0;
	charmander.health = 39;
	charmander.PP = 10;
	charmander.numValue = 0;
	allPokemon[charmander.numValue] = charmander;

	pokemon squirtle;
	strcpy(squirtle.name, "SQUIRTLE");
	static attack moveSet1[4];
	moveSet1[0] = allAttacks[0];
	moveSet1[1] = allAttacks[1];
	moveSet1[2] = allAttacks[2];
	moveSet1[3] = allAttacks[3];
	squirtle.attacks = moveSet1;
	squirtle.health = 44;
	squirtle.PP = 10;
	squirtle.numValue = 1;
	allPokemon[squirtle.numValue] = squirtle;

	pokemon bulbasur;
	strcpy(bulbasur.name, "BULBASUR");
	static attack moveSet2[4];
	moveSet2[0] = allAttacks[0];
	moveSet2[1] = allAttacks[1];
	moveSet2[2] = allAttacks[2];
	moveSet2[3] = allAttacks[3];
	bulbasur.attacks = moveSet2;
	bulbasur.health = 45;
	bulbasur.PP = 10;
	bulbasur.numValue = 2;
	allPokemon[bulbasur.numValue] = bulbasur;



	return allPokemon;
}