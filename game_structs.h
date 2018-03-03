#ifndef GAME_STRUCTS
#define MAXATTACKNAMESIZE 100
#define MAXPOKEMONNAMESIZE 100
#define NUMATTACKS 4
#define NUMPOKEMON 8
#define GAME_STRUCTS

enum myBool { FALSE = 0, TRUE = 1};
typedef enum myBool bool;

struct playerStruct{
	int pokemon;
	int command;
	bool pokemonAlive;
}; typedef struct playerStruct player;

struct attackStruct{
	char name[MAXATTACKNAMESIZE];
	int damage;
	int PP;
	int numValue;
}; typedef struct attackStruct attack;

struct pokemonStruct{
	char name[MAXPOKEMONNAMESIZE];
	attack* attacks;
	int def;
	int health;
	int PP;
	int numValue;
}; typedef struct pokemonStruct pokemon;

#endif