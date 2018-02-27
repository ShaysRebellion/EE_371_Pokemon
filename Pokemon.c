void main() {

}

struct PokemonRoster {
  // Need to change syntax
  struct Pokemon *pokemon1;
  struct Pokemon *pokemon2;
  struct Pokemon *pokemon3;
  struct Pokemon *pokemon4;
  struct Pokemon *pokemon5;
}

struct Pokemon {
  char string[] name;
  int level;
  int HP;
  int Atk;
  int Def;
  int SpAtk;
  int SpDef;
  int Spd;
  char Type;
  bool Fainted;
  // Need to change syntax
  int (*calculateHpPtr)() = &calculateHp;
  int (*calculateStatsPtr)() = &calculateStats;
  int (*calculateModifierPtr)() = &calculateModifier;
  int (*calculateReceivedDamagePtr)() = &calculateREceivedDamage;
}

int calculateHp(int base, int level) {
  int hp;
  hp = (base * 2 * level / 100) + level + 10;
  return hp;
}

int calculateStats(int base, int level) {
  int stat;
  stat = (base * 2 * level / 100) + 5;
  return stat;
}

double calculateModifier(char selfType, char opponentType) {
  double modifier;
  /* If/else statements or case statments */
  return modifier;
}

int calculateReceivedDamage(int level, int atk, int def, double modifier) {
  int damage;
  damage = (((((2 * level / 5) + 2) * atk / def) / 50) + 2) * modifier;
  return damage;
}

int calculateRemainingHP(int hp, int damage) {
  int remainingHp;
  remainingHp = hp - damage;
  return remainingHp;
}
