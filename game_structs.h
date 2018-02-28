#ifndef GAME_STRUCTS
#define MAXATTACKNAMESIZE 100
#define MAXPOKEMONNAMESIZE
#define NUMATTACKS 2
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
	int heatlh;
	int PP;
	int numValue;
}; typedef struct pokemonStruct pokemon;

#endif