/*******
This is the unit test for the card great hall
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

	int great_hallPos = -1;
	Game.coins = 10;

	buyCard(great_hall, &Game);

	for(int i = 0; i < numHandCards(&Game); i++){
		if(handCard(i, &Game) == great_hall){
			great_hallPos = i;
			printf("great hall found! In position: %d \n", great_hallPos);
		}
	}

	int previousHandCount = numHandCards(&Game);
	int previousNumActions = Game.numActions;

	printf("Current number of cards: %d \n", previousHandCount);
	printf("Current number of actions: %d \n", Game.numActions);


	if(handCard(great_hallPos, &Game) == great_hall)
		printf("great hall will be played! \n");

	Game.phase = 0;

	playCard(great_hallPos, -1, -1, -1, &Game);

	if(numHandCards(&Game) == previousHandCount){
		printf("Draw card has been successful! \n");
		count++;
	}
	

	if(Game.numActions == previousNumActions){
		printf("Increase in actions has been successful! \n");
		count++;
	}
	
	if(count == 2){
		printf("Test is successful! \n");
	}
	else{
		printf("Test failed! \n");
	}
	


	return 0;
}