#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

void runTests(struct BowlingState *state);

int main()
{
	struct BowlingState *state = createBowlingState();
	if (state == NULL) {
		printf("Failed to create a bowling state.\n");
		exit(1);
	}

	initBowlingState(state);
	runTests(state);	
	destroyBowlingState(state);	

	return 0;
}

void runTests(struct BowlingState *state) {
	int i, score;

	illegalFrameTests(state);
	simpleTests(state);
	strikeTests(state);
	spareTests(state);
	sampleGameTest(state);
}
