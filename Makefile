game: simplifiedPokemon.c definePokemon.c defineAttacks.c definePlayer.c communications.c gameplayMechanics.c
	gcc -o game simplifiedPokemon.c definePokemon.c defineAttacks.c definePlayer.c communications.c gameplayMechanics.c

clean:
	rm -f *.o game
