#ifndef _Bowling
#define _Bowling


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

struct BowlingState* createBowlingState();
void destroyBowlingState();
void initBowlingState(struct BowlingState *state);
void pinsKnockedDown(int pins, struct BowlingState *state);
int getScoreForFrame(int frame, struct BowlingState *state);

#endif