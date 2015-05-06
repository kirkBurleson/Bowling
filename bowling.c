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
	
	// max 21 throws in a game of bowling
	if (++(state->gameThrow) > 21) 
		return;

	// record this throw
	state->throws[state->gameThrow] = pins;

	// first throw of frame
	if (state->frameThrow == 1) {

		//strike
		if (pins == 10)
			recordFrameScoringThrows(2);
	}
	// second throw of frame
	else if (state->frameThrow == 2) {

		// spare
		if (state->throws[state->gameThrow] + state->throws[state->gameThrow - 1] == 10)
			recordFrameScoringThrows(1);

		// less than 10 pins knocked down this frame
		else {
			recordFrameScoringThrows(0);
		}
		
		state->frameThrow = 0;
	}	
}

void recordFrameScoringThrows(int futureThrows) {
	// record the number of throws to add up to calculate a frame's score
	state->scoreQueue[state->curFrame - 1] = state->gameThrow + futureThrows;

	// There's only 10 frames in bowling
	if (state->curFrame < 10)
		state->curFrame++;
}

int getScoreForFrame(int frame, struct BowlingState *state) {
	int i;
	int score = 0;
	
	// frame can't be scored yet
	if (state->gameThrow < state->scoreQueue[frame - 1])
		return -1;

	for (i = 0; i < state->scoreQueue[frame - 1]; i++)
		score += state->throws[i];

	return score;
}

struct BowlingState* createBowlingState() {
	struct BowlingState *state = (struct BowlingState*) malloc(sizeof(struct BowlingState));
	return state;
}

void destroyBowlingState(struct BowlingState *state) {
	free(state);
}