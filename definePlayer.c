#include "game_structs.h"

player* definePlayer(pokemon* allPokemon, int pokemonOne, int pokemonTwo) {
  static player whoAmI;

  whoAmI.pokemonParty[0] = allPokemon[pokemonOne];
  whoAmI.pokemonParty[1] = allPokemon[pokemonTwo];
  whoAmI.whichPokemon = 0;
  whoAmI.pokemon1HP = allPokemon[pokemonOne].hp;
  whoAmI.pokemon2HP = allPokemon[pokemonTwo].hp;
  whoAmI.whichHP = whoAmI.pokemon1HP;

  return &whoAmI;
}
