#include "game_structs.h"

void send(char data) {
	*PARALLEL_SEND = data;
	*LOAD = 1;
	*TRANSMIT = 1;
	*LOAD = 0;

	while (!*CHARSENT) { // Potential infinite loop?
		continue;
	}

	*TRANSMIT = 0;
}
