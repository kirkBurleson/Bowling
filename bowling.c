#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

void initBowlingState(struct BowlingState *state) {
	int i;
	
	state->queueIndex = 0;
	state->curFrame = 1;
	state->frameThrow = 0;
	state->gameThrow = 0;
	
	// zero out throws
	for (i = 0; i < MAX_THROWS; i++)
		state->throws[i] = 0;

	// zero out score queue
	for (i = 0; i < MAX_FRAMES; i++)
		state->scoreQueue[i] = 0;
}

void pinsKnockedDown(int pins, struct BowlingState *state) {
	int i;

	state->frameThrow++;
	state->gameThrow++;

	// strike
	if (state->frameThrow == 1 && pins == 10) {
		state->scoreQueue[state->curFrame] = state->gameThrow + 2; // 2 more throws before we can score a strike
		state->curFrame++;
	}

	
}

int getScoreForFrame(int frame, struct BowlingState *state) {
	int i;
	int score = 0;
	
	// frame can't be scored yet
	if (state->gameThrow < state->scoreQueue[frame - 1])
		return -1;

	for (i = 0; i < state->scoreQueue[frame - 1]; i++)
		score += state->throws[i];

	return score
;
}

struct BowlingState* createBowlingState() {
	struct BowlingState *state = (struct BowlingState*) malloc(sizeof(struct BowlingState));
	return state;
}

void destroyBowlingState(struct BowlingState *state) {
	free(state);
}