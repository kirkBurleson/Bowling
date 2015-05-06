#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

int main()
{
	struct BowlingState *state = createBowlingState();
	if (state == NULL) {
		printf("Failed to create a bowling state.\n");
		exit(1);
	}

	initBowlingState(state);

	
	destroyBowlingState(state);	
	return 0;
}