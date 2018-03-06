#include "auxillary_functions.h"
#include <ctype.h>

int getCommand(player* opponent, player* whoAmI) {
  player oppo = *opponent;
  player me = *whoAmI;

  char* oppoPokemonName = oppo.pokemonParty[oppo.whichPokemon].name;
  char* mePokemonName = me.pokemonParty[me.whichPokemon].name;
  int oppoPokemonHP = (oppo.whichPokemon == 0) ? oppo.pokemon1HP : oppo.pokemon2HP;
  int mePokemonHP = (me.whichPokemon == 0) ? me.pokemon1HP : me.pokemon2HP;
  char* attack1 = me.pokemonParty[me.whichPokemon].attacks[0].name;
  char* attack2 = me.pokemonParty[me.whichPokemon].attacks[1].name;
  char* attack3 = me.pokemonParty[me.whichPokemon].attacks[2].name;
  char* attack4 = me.pokemonParty[me.whichPokemon].attacks[3].name;

  bool validAnswer;
  validAnswer = false;

  while (!validAnswer) {
    printf("Opponent Pokemon: %s, HP: %d\n", oppoPokemonName, oppoPokemonHP); // Will print entire string or just one char?
    printf("Own Pokemon: %s, HP: %d\n", mePokemonName, mePokemonHP); // Will print entire string or just one char?
    printf("Switch: (0)\n");
    printf("Attack: \n %s (1) %s (2) \n %s (3) %s (4)\n", attack1, attack2, attack3, attack4);

    int command;
    
    do
      command = getchar();
    while(isspace(command));
    command -= '0';

    if (command < 0 || command > 4) {
      printf("Please enter a valid command!\n");
      continue;
    }

    if (me.whichPokemon == 0 && me.pokemonParty[1].hp <= 0 || me.whichPokemon == 1 && me.pokemonParty[0].hp <= 0) {
      printf("%s already fainted. Unable to battle!\n", me.pokemonParty[me.whichPokemon].name);
      continue;
    }

    return command;
  }
}

int processCommand(player* opponent, player* whoAmI, int usrCommand) {
  if (usrCommand == 0) {
    switchPokemon(whoAmI);
    return 0;
  } else {
    int damage = calculateDamage(opponent, whoAmI, usrCommand);
    updateHP(opponent, damage);
    return damage;
  }
}

void switchPokemon(player* whoAmI) {
  if (whoAmI->whichPokemon == 0) {
    whoAmI->whichPokemon = 1;
  } else {
    whoAmI->whichPokemon = 0;
  }
}

int calculateDamage(player* opponent, player* whoAmI, int usrCommand) {
  player oppo = *opponent;
  player me = *whoAmI;
  int atkIndex = usrCommand - 1;
  int atkStat = me.pokemonParty[me.whichPokemon].attacks[atkIndex].power;
  int defStat = oppo.pokemonParty[oppo.whichPokemon].def;
  int damage;
  damage = (int) (atkStat - defStat/10);
  if (damage < 0) {
    damage = 0;
  }
  printf("damage %d\n", damage);
  return damage;
}

void updateHP(player* whoAmI, int damage) {
  if (whoAmI->whichPokemon == 1) {
    whoAmI->pokemon2HP -= damage;
    if (whoAmI->pokemon2HP < 0) {
      whoAmI->pokemon2HP = 0;
      switchPokemon(whoAmI);
    }
  } else {
    whoAmI->pokemon1HP -= damage;
    if (whoAmI->pokemon1HP < 0) {
      whoAmI->pokemon1HP = 0;
      switchPokemon(whoAmI);
    }
  }
}

void processInformation(player* opponent, player* whoAmI, int opponentInformation) {
  if (opponentInformation == 0) {
    switchPokemon(opponent);
  } else {
    updateHP(whoAmI, opponentInformation);
  }
}

bool checkGameOver(player* whoAmI) {
  player thePlayer = *whoAmI;
  int pokemon1HP = thePlayer.pokemon1HP;
  int pokemon2HP = thePlayer.pokemon2HP;
  int total = pokemon1HP + pokemon2HP;
  if (total <= 0) {
    return true;
  } else {
    return false;
  }
}

void handleGameOver(bool gameOverForOpponent, bool gameOverForMe) {
  // int sramAddressWins = 0;
  // int sramAddressLosses = 1;
  // int wins = readSRAM(sramAddressWins);
  // int losses = readSRAM(sramAddressLosses);
  //
  // if (gameOverForOpponent) {
  //   wins += 1;
  //   writeSRAM(sramAddressWins, wins);
  // } else {
  //   losses += 1;
  //   writeSRAM(sramAddressLosses, losses);
  // }
  //
  // printf("Wins: %d\n", wins);
  // printf("Losses: %d\n", losses);
  if (gameOverForOpponent) {
    printf("\n\n\n\nPlayer won.\n\n\n\n\n");
    
  } else {
    printf("\n\n\n\n\nOpponent won.\n\n\n\n\n");
  }
}

/* Will vary among groups depending on SRAM is connected.
int readSRAM(int sramAddress) {
  *ramControls = 2;
  *address = sramAddress;
  int sramData = *dataOut;
  *ramControls = 1;
  return sramData;
}

// Will vary among groups depending on SRAM is connected.
void writeSRAM(int sramAddress, int sramData) {
  *ramControls = 4;
  *dataIn = sramData;
  *ramControls = 1;
} */

