#include "game_structs.h"

player* definePlayer(pokemon* allPokemon) {
  player whoAmI;

  pokemonParty[POKEMONPARTYSIZE];
  pokemonParty[0] = allPokemon[rand() % 2];
  pokemonParty[1] = allPokemon[rand() % 2];
  player1.pokemonParty = pokemonParty1;
  player1.whichPokemon = 0;
  player1.pokemonAlive = true;

  return whoAmI;
}
