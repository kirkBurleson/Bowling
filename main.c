#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

void runTests(struct BowlingState *state);
void illegalFrameTests(struct BowlingState *state);
void simpleTests(struct BowlingState *state);
void strikeTests(struct BowlingState *state);
void spareTests(struct BowlingState *state);
void sampleGameTest(struct BowlingState *state);

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

void sampleGameTest(struct BowlingState *state) {
	int score, expectedScore;

	initBowlingState(state);
	printf("\n ********** Sample Game **********\n\n");

	pinsKnockedDown(1, state);
	pinsKnockedDown(4, state);

	pinsKnockedDown(4, state);
	pinsKnockedDown(5, state);
	
	pinsKnockedDown(6, state);
	pinsKnockedDown(4, state);

	pinsKnockedDown(5, state);
	pinsKnockedDown(5, state);

	pinsKnockedDown(10, state);
	
	pinsKnockedDown(0, state);
	pinsKnockedDown(1, state);

	pinsKnockedDown(7, state);
	pinsKnockedDown(3, state);

	pinsKnockedDown(6, state);
	pinsKnockedDown(4, state);
	
	pinsKnockedDown(10, state);
	
	pinsKnockedDown(2, state);
	pinsKnockedDown(8, state);

	pinsKnockedDown(6, state);

	expectedScore = 133;

	printf("Test sample game: ");
	score = getScoreForFrame(10, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n", expectedScore, score);
	}

	printf("\n");
}

void spareTests(struct BowlingState *state) {
	int score, expectedScore;
	
	printf("\n********** Spare Tests **********\n\n");

	// TEST
	initBowlingState(state);

	pinsKnockedDown(3, state);
	pinsKnockedDown(7, state);
	pinsKnockedDown(3, state);

	expectedScore = 13;

	// assert
	printf("Test simple spare: ");
	score = getScoreForFrame(1, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n", expectedScore, score);
	}

	// TEST
	initBowlingState(state);
	
	pinsKnockedDown(3, state);
	pinsKnockedDown(7, state);

	pinsKnockedDown(3, state);
	pinsKnockedDown(2, state);

	expectedScore = 18;

	// assert
	printf("Test simple frame after spare: ");
	score = getScoreForFrame(2, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n", expectedScore, score);
	}

	initBowlingState(state);
	// arrange
	pinsKnockedDown(1, state);
	pinsKnockedDown(4, state);

	pinsKnockedDown(4, state);
	pinsKnockedDown(1, state);
	
	pinsKnockedDown(5, state);
	pinsKnockedDown(3, state);

	pinsKnockedDown(0, state);
	pinsKnockedDown(9, state);

	pinsKnockedDown(0, state);
	pinsKnockedDown(9, state);
	
	pinsKnockedDown(5, state);
	pinsKnockedDown(3, state);

	pinsKnockedDown(1, state);
	pinsKnockedDown(5, state);

	pinsKnockedDown(2, state);
	pinsKnockedDown(6, state);
	
	pinsKnockedDown(5, state);
	pinsKnockedDown(3, state);
	
	pinsKnockedDown(4, state);
	pinsKnockedDown(6, state);

	pinsKnockedDown(3, state);

	expectedScore = 79;

	// assert
	printf("Get score for 10th frame spare + 3 pins: ");
	score = getScoreForFrame(10, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n", expectedScore, score);
	}	
}

void strikeTests(struct BowlingState *state) {
	int score, expectedScore;
	
	initBowlingState(state);
	printf("\n********** Strike Tests **********\n\n");

	// arrange
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);
	pinsKnockedDown(10, state);

	expectedScore = 300;

	// assert
	printf("Get score for perfect game: ");
	score = getScoreForFrame(10, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n", expectedScore, score);
	}

	initBowlingState(state);
	// arrange
	pinsKnockedDown(4, state);
	pinsKnockedDown(5, state);

	pinsKnockedDown(10, state);

	pinsKnockedDown(4, state);
	pinsKnockedDown(5, state);

	expectedScore = 28;

	// assert
	printf("Test strike followed by simple frame: ");
	score = getScoreForFrame(2, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n", expectedScore, score);
	}
}

void simpleTests(struct BowlingState *state) {
	int score, expectedScore;

	initBowlingState(state);
	printf("\n********** Simple Tests **********\n\n");

	// arrange
	pinsKnockedDown(2, state);
	pinsKnockedDown(5, state);
	expectedScore = 7;

	// assert
	printf("Get score for frame 1: ");
	score = getScoreForFrame(1, 0, state);

	if (score == expectedScore) printf("PASSED\n");
	else {
		printf("FAILED\n");
		printf(">>>>>>> Expected %d Got %d\n\n", expectedScore, score);
	}
}

void illegalFrameTests(struct BowlingState *state) {
	int score, expectedScore;

	initBowlingState(state);
	printf("\n********** illegalFrameTests **********\n\n");
	
	printf("Get score for frame 99: ");
	score = getScoreForFrame(99, 0, state);
	expectedScore = 0;
	if (score == expectedScore) printf("PASSED\n");
	else printf("FAILED\n");

	printf("Get score for frame -6: ");
	score = getScoreForFrame(-6, 0, state);
	expectedScore = 0;
	if (score == expectedScore) printf("PASSED\n");
	else printf("FAILED\n");

	printf("Get score for frame 0: ");
	score = getScoreForFrame(0, 0, state);
	expectedScore = 0;
	if (score == expectedScore) printf("PASSED\n");
	else printf("FAILED\n");
}