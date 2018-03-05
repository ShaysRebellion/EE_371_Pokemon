#ifndef GAME_STRUCTS
/* Memory Address Definitions for Serial Communications Peripheral */
#define PARALLEL_SEND (volatile char*) 0x00011020 // To change
#define LOAD (volatile char*) 0x00011020 // To change
#define TRANSMIT (volatile char*) 0x00011020 // To change
#define CHAR_SENT (volatile char*) 0x00011010 // To change
#define PARALLEL_RECEIVE (volatile char*) 0x00011010 // To change
#define CHAR_RECEIVED (volatile char*) 0x00011010 // To change
/* Memory Address Definitions for SRAM Peripheral */
#define dataOut (char*) 0x00011050 // To change
#define dataIn (char*) 0x00011040 // To change
#define address (short*) 0x00011030 // To change
#define ramControls (char*) 0x00011020 // To change
/* Constant Definitions */
#define NUM_ATTACKS 50
#define NUM_POKEMON 8
#define MAX_ATTACK_NAME_SIZE 100
#define MAX_POKEMON_NAME_SIZE 100
#define POKEMON_PARTY_SIZE 2
#define GAME_STRUCTS

enum myBool {false = 0, true = 1};
typedef enum myBool bool;

struct attackStruct {
	char name[MAX_ATTACK_NAME_SIZE];
	int power;
	int numValue;
}; typedef struct attackStruct attack;

struct pokemonStruct {
	char name[MAX_POKEMON_NAME_SIZE];
	attack* attacks;
	int hp;
	int atk;
	int def;
	int numValue;
}; typedef struct pokemonStruct pokemon;

struct playerStruct {
	pokemon pokemonParty[POKEMON_PARTY_SIZE];
	int whichPokemon;
	int pokemon1HP;
	int pokemon2HP;
	int whichHP;
}; typedef struct playerStruct player;

#endif
