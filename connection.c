#include "auxillary_functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void intializeConnection() {
  while (1) {
    send(1);
    if (receive() == 1) break;
  }
}

player sendInfoToOppo(player* me, pokemon* allPokemon) {
  player rival;
  while (1) {
    send((me->pokemonParty[0].numValue) + ((me->pokemonParty[1].numValue) << 3));
    int received = receive();
    if (received == -1) continue;
    int zero = received & 0b111;
    int one = received & 0b111000;
    return definePlayer(allPokemon, zero, one);
  }


  // printf("%s\n", me->pokemonParty[0].name);
}

// rock == 1  papper == 2  scissor == 3
bool RPS() {
  bool done = false;
  while (!done) {
    alt_putstr("Rock Paper Scissor: (rock == 1  papper == 2  scissor == 3)");
    int mine = alt_getchar();
    while (1) {
      send(mine);
      int oppo = receive();
      if (oppo == -1) continue;
      if (mine == oppo) break;
      if (mine == 1 && oppo == 2 || mine == 2 && oppo == 3 || mine == 3 && oppo == 1) {
        return false;
      } else {
        return true;
      }
    }
  }
}

// player p is under attack by pokemon[whichPokemonAttacked] with this attack[whichAttack]
bool attackMove(player* p, int whichPokemonAttacked, int whichAttack, attack* allAttacks, pokemon* allPokemon) {
	p->hp -= allAttacks[whichAttack].damage;
	printf("%s used %s dealt %d damage", allPokemon[whichPokemonAttacked].name, allAttacks[whichAttack].name, allAttacks[whichAttack].damage);
	if (p->hp <= 0) {
		alt_putstr("%s fainted\n", p->pokemonParty[p->whichPokemon].name);
		p->whichPokemon += 1;
		if (p->whichPokemon > 1) { // game over
			return true;
		} else { // switch pokemon
			p->hp = p->pokemonParty[p->whichPokemon].health;
			alt_putstr("%s is up\n", p->pokemonParty[p->whichPokemon].name);
			return false;
		}
	}
}

char receive() {
	if (!*CHAR_RECEIVED) { // Potential infinite loop?
		return -1;
	}
	return *PARALLEL_RECEIVE;
}

void send(char data) {
	*PARALLEL_SEND = data;
	*LOAD = 1;
	*TRANSMIT = 1;
	*LOAD = 0;

	while (!*CHAR_SENT) { // Potential infinite loop?
		continue;
	}

	*TRANSMIT = 0;
}
