#include "game_structs.h"
#ifndef AUXILLARY_FUNCTIONS
#define AUXILLARY_FUNCTIONS

int initialize();

void send(int data);

int receive();

int attackCalculate(int attackDamage, int target);

int updateHealth(pokemon* target); 

attack* defineAttacks();

pokemon* definePokemon();

#endif