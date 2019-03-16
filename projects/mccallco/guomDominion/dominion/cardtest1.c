/*******
This is the unit test for the card Smithy

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
	int smithyPos = 0;

	buyCard(smithy, &Game);

	for(int i = 0; i < numHandCards(&Game); i++){
		if(handCard(i, &Game) == smithy){
			smithyPos = i;
			printf("smithy found! \n");
		}
	}

	if(numHandCards(&Game) == 5){
		printf("Correct number of cards in hand before smithy played \n");
		count++;
	}
	
	Game.phase = 0;
	playCard(smithyPos, -1, -1, -1, &Game);

	if(numHandCards(&Game) == 5 - 1 + 3){
		printf("Correct number of cards in hand after smithy played \n");
		count++;
	}

	if(count == 2){
		printf("Test passed! \n");
	}
	else{
		printf("Test failed! \n");
	}




	return 0;
}