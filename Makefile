game: simplifiedPokemon.o defineAttacks.o definePokemon.o
	gcc -o game simplifiedPokemon.o defineAttacks.o definePokemon.o game_structs.h auxillary_functions.h

simplifiedPokemon.o: simplifiedPokemon.c game_structs.h auxillary_functions.h
	gcc -c simplifiedPokemon.c

defineAttacks.o: defineAttacks.c game_structs.h
	gcc -c defineAttacks.c

definePokemon.o: definePokemon.c game_structs.h
	gcc -c definePokemon.c