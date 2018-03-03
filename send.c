#include "game_structs.h"

void send(char data) {
	*LOAD = 1;
	*PARALLEL = data;
	*LOAD = 0;
	*CHARSEND = *PARALLEL;
	}
}
