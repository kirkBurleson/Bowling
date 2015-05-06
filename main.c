#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_THROWS 21

struct BowlingState {
	int scoreQueue[MAX_FRAMES]; // contents determine at what throw to calculate frame score
	int throws[MAX_THROWS];
	int queueIndex;
	int curFrame;
	int frameThrow; // tracks throw inside current frame
	int gameThrow; // tracks total throws in game
};

void initBowlingState(struct BowlingState *state);
void pinsKnockedDown(int pins);

int main()
{
	struct BowlingState state;

	initBowlingState(&state);

	
	return 0;
}

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

void pinsKnockedDown(int pins) {
	
}