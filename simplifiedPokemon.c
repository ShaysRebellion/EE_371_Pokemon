// TO DO: CHECK NO REFERENCING ISSUES!!

#include <stdio.h>
#include <stdlib.h>
// #include <altera_avalon_pio_regs.h> // Uncomment later. Caused compiliation errors.
#include "game_structs.h"
#include "auxillary_functions.h"
/* Import any additional necessary libraries here. */

int main() {
  attack* allAttacks = defineAttacks();
  pokemon* allPokemon = definePokemon(allAttacks);

  while (1) {
    player me;
  	player* whoAmI = &me;
    int ran1 = rand() % 8;
    int ran2 = rand() % 8;
    printf("ran1 %d, rand2 %d\n", ran1, ran2);
  	 definePlayerMe(whoAmI, allPokemon, ran1, ran2);

    // Maybe add function to check connection?

    sendInfoToOpponent(whoAmI);
    player oppo;
    player* opponent = & oppo;
    receiveInfoFromOpponent(opponent, allPokemon);

  	bool myTurn = rockPaperScissor();

    bool gameOverForOpponent = false;
    bool gameOverForMe = false;
  	while (!gameOverForOpponent && !gameOverForMe) {
  		if (myTurn) {
        int usrCommand = getCommand(opponent, whoAmI);
        int processedCommand = processCommand(opponent, whoAmI, usrCommand);
        send(processedCommand);
        myTurn = false;
      } else {
        int opponentInformation = receive();
        processInformation(opponent, whoAmI, opponentInformation);
        myTurn = true;
      }
      gameOverForOpponent = checkGameOver(opponent);
      gameOverForMe = checkGameOver(whoAmI);
      if (gameOverForOpponent || gameOverForMe) {
        handleGameOver(gameOverForOpponent, gameOverForMe);
      }
    }
  }
}
