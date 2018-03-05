#include "game_structs.h"

player* definePlayer(pokemon* allPokemon, int pokemonOne, int pokemonTwo) {
  static player whoAmI;

  // Need "static"?
  static pokemon pokeParty[POKEMON_PARTY_SIZE];
  pokeParty[0] = allPokemon[pokemonOne];
  pokeParty[1] = allPokemon[pokemonTwo];
  whoAmI.pokemonParty = pokeParty;
  whoAmI.whichPokemon = 0;
  /* Don't want to modify Pokemon struct HP in case player gets two of the same Pokemon. Copy pokemon HP. */
  whoAmI.pokemon1HP = allPokemon[pokemonOne].hp;
  whoAmI.pokemon2HP = allPokemon[pokemonTwo].hp;
  /* Determine which HP to subtract from when Pokemon takes damage. */
  whoAmI.whichHP = whoAmI.pokemon1HP;

  return &whoAmI;
}
