game: simplifiedPokemon.c definePokemon.c defineAttacks.c definePlayer.c connection.c
	gcc -o game simplifiedPokemon.c definePokemon.c defineAttacks.c definePlayer.c connection.c

clean:
	rm -f *.o game
