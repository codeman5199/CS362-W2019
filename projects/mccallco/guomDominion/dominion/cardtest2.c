/*******
This is the unit test for the card council_room

********/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main(int argc, char** argv){

	int count = 0;

	struct gameState Game;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	int numPlayer = 3;

	initializeGame(numPlayer, k, 20, &Game);

	int council_roomPos = 0;
	Game.coins = 10;

	buyCard(council_room, &Game);

	for(int i = 0; i < numHandCards(&Game); i++){
		if(handCard(i, &Game) == council_room){
			council_roomPos = i;
			printf("council room found! In position: %d \n", council_roomPos);
		}
	}

	printf("Number of cards in hand right now: %d \n", numHandCards(&Game));
	int previousCardNum = numHandCards(&Game);
	int previousnumBuys = 0;

	printf("Number of buys right now: %d \n", Game.numBuys);
	if(Game.numBuys == 0){
		previousnumBuys = 0;
		printf("The number of buys before is correct. \n");
		count++;
	}

	Game.phase = 0;
	playCard(council_roomPos, -1, -1, -1, &Game);

	printf("Number of buys right now: %d \n", Game.numBuys);

	if(Game.numBuys == (previousnumBuys + 1)){
		printf("After card played, num of buys still correct. \n");
		count++;
	}


	if(numHandCards(&Game) == previousCardNum + 4 - 1){
		printf("After card played, num of cards in hand still correct. \n");
		count++;
	}

	if(count == 3){
		printf("All tests passed! \n");
	}
	else{
		printf("Test failed! \n");
	}
	


	return 0;
}