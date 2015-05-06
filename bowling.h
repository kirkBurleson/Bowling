#ifndef _Bowling
#define _Bowling


#define MAX_FRAMES 13 // these are 1 over so we can start at index 1
#define MAX_THROWS 22

struct Frame {
	int start;
	int end;
};

struct BowlingState {
	struct Frame frames[MAX_FRAMES];
	int throws[MAX_THROWS];
	int curFrame;
	int frameThrow; // tracks throw inside current frame
	int curThrow; // tracks total throws in game
};

struct BowlingState* createBowlingState();
void destroyBowlingState();
void initBowlingState(struct BowlingState *state);
void pinsKnockedDown(int pins, struct BowlingState *state);
int getScoreForFrame(int frame, int prevScore, struct BowlingState *state);
void saveFrame(int futureIndex, int isStrike, struct BowlingState *state);
#endif