/******************************************************
This is the unit test for the function buyCard in
dominion.c



*****************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"




int main(int argc, char** argv){

	struct gameState Game;

	Game.coins = 3;
	Game.numBuys = 1;
	Game.supplyCount[gold] = 10;
	Game.supplyCount[smithy] = 10;
	Game.supplyCount[adventurer] = 0;
	Game.supplyCount[curse] = 20;

	int count = 0;

	if(buyCard(gold, &Game) == -1){
		printf("Not enough coins! \n");
		count++;
	}

	Game.coins = 10;
	Game.numBuys = 0;

	if(buyCard(smithy, &Game) == -1){
		printf("No more buy actions! \n");
		count++;
	}

	Game.numBuys = 1;

	if(buyCard(adventurer, &Game) == -1){
		printf("No card of that type! \n");
		count++;
	}

	buyCard(curse, &Game);

	if(Game.numBuys == 0){
		printf("Buy amount is correct at %d \n", Game.numBuys);
		count++;
	}

	if(Game.coins == 10){
		printf("Coins amount is correct at %d \n", Game.coins);
		count++;
	}

	if(count == 5){
		printf("Test successful! \n");
	}
	else{
		printf("Test failed! \n");
	}






	return 0;
}