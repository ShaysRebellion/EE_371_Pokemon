#include "game_structs.h"
#ifndef AUXILLARY_FUNCTIONS
#define AUXILLARY_FUNCTIONS


void send(char data);

char receive();

void intializeConnection();

int attackCalculate(int attackDamage, int target);

int updateHealth(pokemon* target);

bool RPS();

attack* defineAttacks();

pokemon* definePokemon(attack* allAttacks);

player definePlayer(pokemon* allPokemon, int pokemonOne, int pokemonTwo);

player sendInfoToOppo(player*, pokemon*);

bool attackMove(player* p, int whichPokemonAttacked, int whichAttack, attack* allAttacks, pokemon* allPokemon);


#endif
