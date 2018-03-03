#include "game_structs.h"

int receive() {
	while (!*CHAR_RECEIVED) { // Potential infinite loop
		continue;
	}

	return *PARALLEL_RECEIVE;
}
