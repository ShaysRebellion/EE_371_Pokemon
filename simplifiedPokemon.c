#include "auxillary_functions.h"
#include "game_structs.h"
#include <stdio.h>
#include <string.h>

int main(){
	attack* attacks;
	attacks = defineAttacks();
	pokemon* pokemen;
	pokemen = definePokemon(attacks);
	printf("%s\n", pokemen[0].name);
	printf("%s\n", pokemen[0].attacks[0].name);
	printf("%s\n", attacks[0].name);
}