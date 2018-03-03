#include "game_structs.h"
#ifndef AUXILLARY_FUNCTIONS
#define AUXILLARY_FUNCTIONS

int initialize();

void send(char data);

char receive();

int attackCalculate(int attackDamage, int target);

int updateHealth(pokemon* target);

attack* defineAttacks();

pokemon* definePokemon(attack* allAttacks);

#endif
