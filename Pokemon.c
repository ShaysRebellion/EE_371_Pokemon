void main() {

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
