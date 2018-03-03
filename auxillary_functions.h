#include "game_structs.h"
#ifndef AUXILLARY_FUNCTIONS
#define AUXILLARY_FUNCTIONS

void send(char data) {
	*PARALLEL_SEND = data;
	*LOAD = 1;
	*TRANSMIT = 1;
	*LOAD = 0;

	while (!*CHAR_SENT) { // Potential infinite loop?
		continue;
	}

	*TRANSMIT = 0;
}

int receive() {
	while (!*CHAR_RECEIVED) { // Potential infinite loop?
		continue;
	}

	return *PARALLEL_RECEIVE;
}

void intializeConnection() {
	bool connected;
	connected = false;
	while(!connected) {
		send(1);
		if (receive() == 1) {
			break;
		}
	}
}

int attackCalculate(int attackDamage, int target) {

};

int updateHealth(pokemon* target) {

};

attack* defineAttacks() {

};

pokemon* definePokemon(attack* allAttacks) {

};

#endif
