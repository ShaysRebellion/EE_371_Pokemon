#include "auxillary_functions.h"
#include <stdio.h>
#include <stdlib.h>

void send(char data) {
  *PARALLEL_SEND = data;
  *LOAD = 1;
  *LOAD = 0; // Maybe too fast? Add delay?
  *TRANSMIT = 1;

  while (!*CHAR_SENT) {
  	continue;
  }

  *TRANSMIT = 0;
}

char receive() {
  bool received;
  received = false;
  while (!received) {
    if (*CHAR_RECEIVED) {
        received = true;
    }
  }
  return *PARALLEL_RECEIVE;
}

player* sendInfoToOpponent(pokemon* allPokemon, player* whoAmI) {
  player thePlayer = *whoAmI;
  int pokemonOne = thePlayer.pokemonParty[0].numValue;
  int pokemonTwo = thePlayer.pokemonParty[1].numValue;
  send((pokemonOne << 3) + (pokemonTwo));

  player* opponent;
  int received = receive();
  int pokeOne = received & 0b00111000;
  int pokeTwo = received & 0b00000111;
  opponent = definePlayer(allPokemon, pokeOne, pokeTwo);
  return opponent;
}

// rock == 1  papper == 2  scissor == 3
bool rockPaperScissor() {
  bool done = false;
  while (!done) {
    alt_putstr("Rock Paper Scissor! (Rock = 1,  Paper = 2,  Scissor = 3)");
    int myAnswer = alt_getchar() - '0';
    if (myAnswer < 1 || myAnswer > 3) {
      alt_putstr("Please enter a valid answer! (Rock = 1,  Paper = 2,  Scissor = 3)");
      continue;
    }

    send(myAnswer);
    int opponentAnswer = receive() - '0';

    if (myAnswer == opponentAnswer) continue; // Automatically start process again.
    if (myAnswer < opponentAnswer) {
      return false;
    } else {
      return true;
    }
  }
}
