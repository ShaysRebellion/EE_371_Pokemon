#include "auxillary_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void send(char data) {
  // *PARALLEL_SEND = data;
  // *LOAD = 1;
  // *LOAD = 0;              // Maybe too fast? Add delay?
  // *TRANSMIT = 1;
  //
  // while (!(*CHAR_SENT & 0b1)) {
  // 	continue;
  // }
  //
  // *TRANSMIT = 0;
}

char receive() {
  // bool received;
  // received = false;
  // while (!received) {
  //   if ((*CHAR_RECEIVED & 0b1)) {
  //       received = true;
  //   }
  // }
  // return *PARALLEL_RECEIVE;
  printf("OPPO INPUT:\n");
  int myAnswer;
  do
    myAnswer = getchar();
  while(isspace(myAnswer));
  return  myAnswer - '0';
}

void sendInfoToOpponent(player* whoAmI) {
  player thePlayer = *whoAmI;
  int pokemonOne = thePlayer.pokemonParty[0].numValue;
  int pokemonTwo = thePlayer.pokemonParty[1].numValue;
  send((pokemonOne << 3) + (pokemonTwo));
}

void receiveInfoFromOpponent(player *oppo, pokemon* allPokemon) {
  int received = receive();
  int pokeOne = (received & 0b111000) >> 3;
  int pokeTwo = received & 0b111;
  definePlayerOppo(oppo, allPokemon, pokeOne, pokeTwo);
}

bool rockPaperScissor() {
  bool done = false;
  while (!done) {
    printf("Rock, Paper, Scissor! (Rock = 1,  Paper = 2,  Scissor = 3)\n");
    int myAnswer;
    do
      myAnswer = getchar();
    while(isspace(myAnswer));
    myAnswer -= '0';
    if (myAnswer < 1 || myAnswer > 3) {
      printf("Please enter a valid answer! (Rock = 1,  Paper = 2,  Scissor = 3)\n");
      continue;
    }

    send(myAnswer);
    int opponentAnswer = receive() - '0';

    if (myAnswer == opponentAnswer) {
      printf("Tie.\n");
      continue;
    }

    if (myAnswer % 3 == opponentAnswer % 3 - 1) {
      return false;
    } else {
      return true;
    }
  }
}
