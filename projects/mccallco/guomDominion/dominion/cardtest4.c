/*******
This is the unit test for the card adventurer
********/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main(int argc, char** argv){

	int count = 0;

	struct gameState Game;
	int numPlayers = 3;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(numPlayers, k, 20, &Game);

	int adventurerPos = -1;
	int previousNumTreasure = 0;
	int previousNumHand = 0;
	int newNumTreasure = 0;

	Game.coins = 10;

	buyCard(adventurer, &Game);

	for(int i = 0; i < numHandCards(&Game); i++){
		if(handCard(i, &Game) == adventurer){
			adventurerPos = i;
			printf("adventurer found! At position: %d \n", i);
		}
	}

	if(Game.deckCount[whoseTurn(&Game)] != 0){
		printf("Enough cards to draw \n");
		count++;
	}


	if(numHandCards(&Game) >= 0){
		printf("Current number of cards in hand: %d \n", numHandCards(&Game));
		previousNumHand = numHandCards(&Game);
		count++;
	}
	

	for(int i = 0; i < numHandCards(&Game); i++){
		if(handCard(i, &Game) == copper || handCard(i, &Game) == silver || handCard(i, &Game) == gold)
			previousNumTreasure++;
	}

	printf("Current number of treasure cards: %d \n", previousNumTreasure);
	if(previousNumTreasure <= numHandCards(&Game)){
		printf("Adventure card will now be played \n");
		count++;
	}

	Game.phase = 0;
	playCard(adventurerPos, -1, -1, -1, &Game);

	printf("New number of cards in hand: %d \n", numHandCards(&Game));

	if(numHandCards(&Game) == previousNumHand - 1 + 2){
		printf("Number of total cards correct \n");
		count++;
	}

	for(int i = 0; i < numHandCards(&Game); i++){
		if(handCard(i, &Game) == copper || handCard(i, &Game) == silver || handCard(i, &Game) == gold)
			newNumTreasure++;
	}

	printf("New number of treasure cards: %d \n", newNumTreasure);

	if(newNumTreasure == previousNumTreasure + 2){
		printf("New treasure cards correct amount \n");
		count++;
	}

	if(count == 5){
		printf("Test successful! \n");
	}
	else{
		printf("Test unsuccessful! \n");
	}
	



	return 0;
}