#include "auxillary_functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void intializeConnection() {
  while (1) {
    send(1);
    if (receive() == 1) break;
  }
}

player sendInfoToOppo(player* me) {
  player rival;
  while (1) {
    send(pokemonParty[0].numValue + pokemonParty[1] << 3);
    int received = receive();
    if (received == 0) continue;
    
  }


  printf("%s\n", me->pokemonParty[0].name);
}

// rock == 1  papper == 2  scissor == 3
// bool RPS() {
//   bool done = false;
//   while (!done) {
//     alt_putstr("Rock Paper Scissor: (rock == 1  papper == 2  scissor == 3)");
//     int mine = alt_getchar();
//     while (1) {
//       send(mine);
//       int oppo = receive();
//       if (oppo == 0) continue;
//       if (mine == oppo) break;
//       if (mine == 1 && oppo == 2 || mine == 2 && oppo == 3 || mine == 3 && oppo == 1) {
//         return false;
//       } else {
//         return true;
//       }
//     }
//   }
// }

int receive() {
	if (!*CHAR_RECEIVED) { // Potential infinite loop?
		return 0;
	}
	return *PARALLEL_RECEIVE;
}

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
