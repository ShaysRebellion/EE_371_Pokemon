#include "game_structs.h"
#ifndef AUXILLARY_FUNCTIONS
#define AUXILLARY_FUNCTIONS

void send(char data);

int receive();

void intializeConnection();

int attackCalculate(int attackDamage, int target);

int updateHealth(pokemon* target);

bool RPS();

attack* defineAttacks();

pokemon* definePokemon(attack* allAttacks);

player definePlayer(pokemon* allPokemon, int pokemonOne, int pokemonTwo);

player sendInfoToOppo(player*);
#endif
