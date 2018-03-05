#include "auxillary_functions.h"

int getCommand(player* opponent, player* whoAmI) {
  player oppo = *opponent;
  player me = *whoAmI;

  char* oppoPokemonName = oppo.pokemonParty[oppo.whichPokemon].name;
  char* mePokemonName = me.pokemonParty[me.whichPokemon].name;
  int oppoPokemonHP = oppo.whichHP;
  int mePokemonHP = me.whichHP;
  char* attack1 = me.pokemonParty[me.whichPokemon].attacks[0].name;
  char* attack2 = me.pokemonParty[me.whichPokemon].attacks[1].name;
  char* attack3 = me.pokemonParty[me.whichPokemon].attacks[2].name;
  char* attack4 = me.pokemonParty[me.whichPokemon].attacks[3].name;

  bool validAnswer;
  validAnswer = false;

  while (!validAnswer) {
    alt_putstr("Opponent Pokemon: %s, HP: %d\n", oppoPokemonName, oppoPokemonHP);
    alt_putstr("Own Pokemon: %s, HP: %d\n", mePokemonName, mePokemonHP);
    alt_putstr("Switch: (0)\n");
    alt_putstr("Attack: \n %s (1) %s (2) \n %s (3) %s (4)\n", attack1, attack2, attack3, attack4);

    int command = atl_getchar() - '0';

    if (command < 0 || command > 4) {
      alt_putstr("Please enter a valid command!");
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
  player thePlayer = *whoAmI;
  int pokemon = thePlayer.whichPokemon;
  if (pokemon == 0) {
    thePlayer.whichPokemon = 1;
    thePlayer.whichHP = thePlayer.pokemon1HP;
  } else {
    thePlayer.whichPokemon = 0;
    thePlayer.whichHP = thePlayer.pokemon2HP;
  }
}

int calculateDamage(player* opponent, player* whoAmI, int usrCommand) {
  player oppo = *opponent;
  player me = *whoAmI;
  int atkIndex = usrCommand - 1;
  int atkStat = me.pokemonParty[me.whichPokemon].attacks[atkIndex].power;
  int defStat = oppo.pokemonParty[oppo.whichPokemon].def;
  int damage;
  damage = (int) ((atkStat - defStat) / 2);
  return damage;
}

void processInformation(player* opponent, player* whoAmI, int opponentInformation) {
  if (opponentInformation == 0) {
    switchPokemon(opponent);
  } else {
    updateHP(whoAmI, opponentInformation);
  }
}

void updateHP(player* whoAmI, int opponentInformation) {
  player thePlayer = *whoAmI;
  thePlayer.whichHP -= opponentInformation;
}

bool checkGameOver(player* whoAmI) {
  player thePlayer = *whoAmI;
  int pokemon1HP = thePlayer.pokemon1HP;
  int pokemon2HP = thePlayer.pokemon2HP;
  int total1 = pokemon1HP + pokemon2HP;
  if (total1 <= 0) {
    return true;
  } else {
    return false;
  }
}

void handleGameOver(bool gameOverForOpponent, bool gameOverForMe) {
  int wins = readSRAM(); // Needs address to read from SRAM
  int losses = readSRAM(); // Needs address to read from SRAM
  if (gameOverForOpponent) {
    wins += 1;
    writeSRAM(wins); // Needs address to write to SRAM
  } else {
    losses += 1;
    writeSRAM(losses); // Needs address to write to SRAM
  }
  alt_putstr("Wins: %d\n", wins);
  alt_putstr("Losses: %d\n", losses);
}

int readSRAM() {

}

void writeSRAM(int info) {

}

/* // player p is under attack by pokemon[whichPokemonAttacked] with this attack[whichAttack]
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
} */
