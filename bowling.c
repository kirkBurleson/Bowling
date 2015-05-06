#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

void initBowlingState(struct BowlingState *state) {
	int i;
	
	state->curFrame = 1;
	state->frameThrow = 0;
	state->curThrow = 0;
	
	// zero out throws
	for (i = 0; i < MAX_THROWS; i++)
		state->throws[i] = 0;

	// zero out frame values
	for (i = 0; i < MAX_FRAMES; i++) {
		state->frames[i].start = 0;
		state->frames[i].end = 0;
	}
}

void pinsKnockedDown(int pins, struct BowlingState *state) {
	int i;

	if (pins < 0 || pins > 10)
		return;

	state->curThrow++;
	state->frameThrow++;	

	state->throws[state->curThrow] = pins;

	// first throw of frame
	if (state->frameThrow == 1) {

		//strike
		if (pins == 10) {
			saveFrame(2, 1, state);
		}
		else {
			state->frames[0].start = state->curThrow;
		}
	}
	// second throw of frame
	else if (state->frameThrow == 2) {
		// spare
		if (state->throws[state->curThrow] + state->throws[state->curThrow - 1] == 10) {
			saveFrame(1, 0, state);
		}

		// less than 10 pins knocked down this frame
		else {
			saveFrame(0, 0, state);			
		}
	}	
}

void saveFrame(int futureIndex, int isStrike, struct BowlingState *state) {
	if (isStrike)
		state->frames[state->curFrame].start = state->curThrow;
	else
		state->frames[state->curFrame].start = state->frames[0].start;

	state->frames[state->curFrame].end = futureIndex + state->curThrow;
	state->frameThrow = 0;
	state->curFrame++;
}

int getScoreForFrame(int frame, int prevScore, struct BowlingState *state) {
	int i;
	int score = prevScore;

	if (frame < 1 || frame > 10)
		return score;	
	
	// calculate all frame scores up to and including frame		
	for (i = state->frames[frame].start; i <= state->frames[frame].end; i++)
		score += state->throws[i];

	return getScoreForFrame(--frame, score, state);
}

struct BowlingState* createBowlingState() {
	struct BowlingState *state = (struct BowlingState*) malloc(sizeof(struct BowlingState));
	return state;
}

void destroyBowlingState(struct BowlingState *state) {
	free(state);
}