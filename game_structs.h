#ifndef GAME_STRUCTS

#define PARALLEL_SEND (volatile char*) 0x00011020 // To change
#define LOAD (volatile char*) 0x00011020 // To change
#define TRANSMIT (volatile char*) 0x00011020 // To change
#define CHAR_SENT (volatile char*) 0x00011010 // To change
#define PARALLEL_RECEIVE (volatile char*) 0x00011010 // To change
#define CHAR_RECEIVED (volatile char*) 0x00011010 // To change

#define MAXATTACKNAMESIZE 100
#define MAXPOKEMONNAMESIZE 100
#define NUMATTACKS 50
#define NUMPOKEMON 8
#define POKEMONPARTYSIZE 2
#define GAME_STRUCTS

enum myBool { FALSE = 0, TRUE = 1};
typedef enum myBool bool;

struct playerStruct{
	pokemon* pokemonParty[POKEMONPARTYSIZE];
	int whichPokemon;
	// char command; ??
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
