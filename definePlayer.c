#include "game_structs.h"

player definePlayer(pokemon* allPokemon, int pokemonOne, int pokemonTwo) {
  static player whoAmI;

  pokemon pokemonParty[POKEMONPARTYSIZE];
  whoAmI.pokemonParty[0] = allPokemon[pokemonOne];
  whoAmI.pokemonParty[1] = allPokemon[pokemonTwo];
   // = pokemonParty;
  whoAmI.whichPokemon = 0;
  whoAmI.pokemonAlive = true;
  whoAmI.hp = whoAmI.pokemonParty[0].health;

  return whoAmI;
}
