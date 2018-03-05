#include "game_structs.h"
#include "auxillary_functions.h"
#include <stdio.h>
#include <stdlib.h>
// #include <altera_avalon_pio_regs.h>
// #include <string.h>  // Do we need this?

int main() {
  attack* allAttacks = defineAttacks();
  pokemon* allPokemon = definePokemon(allAttacks);

  while (1) {
  	player* whoAmI;
  	whoAmI = definePlayer(allPokemon, rand() % 8, rand() % 8);

  	player* opponent = sendInfoToOpponent(allPokemon, whoAmI);

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

/*
  while (1) {
      send((char)whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[whichAttack].numValue);
      if (receive() == -2) { // Opponent received attack.
        myturn = false;
        gameover = attackMove(&rival, whoAmI.pokemonParty[whoAmI.whichPokemon].numValue, whoAmI.pokemonParty[whoAmI.whichPokemon].attacks[whichAttack].numValue, allAttacks, allPokemon);
        if (gameover) {
          alt_putstr("I won. I am so good.");
          gameover = true;
        }
        break;
      }
    }
  } else {
    while (1) {
      int received = receive();
      if (received == -1) continue;
      myturn = true;
      int whichAttack = received;
      gameover = attackMove(&whoAmI, rival.pokemonParty[rival.whichPokemon].numValue, rival.pokemonParty[rival.whichPokemon].attacks[whichAttack].numValue, allAttacks, allPokemon);
      if (gameover) {
        alt_putstr("I lost.");
        gameover = true;
      }
      send(-2);
      break;
    }
  }
  if (gameover) {
    break;
  }
}
*/
