game: simplifiedPokemon.c definePokemon.c defineAttacks.c
	gcc -o game simplifiedPokemon.c definePokemon.c defineAttacks.c

clean:
	rm -f *.o game