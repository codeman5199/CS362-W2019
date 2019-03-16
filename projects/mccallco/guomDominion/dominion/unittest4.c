/******************************************************
This is the unit test for the function supplyCount in
dominion.c



*****************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int main(int argc, char** argv){


	struct gameState Game;

	int count = 0;

	Game.supplyCount[gold] = 10;
	Game.supplyCount[smithy] = 10;
	Game.supplyCount[adventurer] = 0;
	Game.supplyCount[curse] = 20;
	Game.supplyCount[council_room] = 45;

	if(supplyCount(gold, &Game) == 10){
		printf("Gold count good at %d \n", Game.supplyCount[gold]);
		count++;
	}
	else{
		printf("Gold count not correct \n");
	}

	if(supplyCount(smithy, &Game) == 10){
		printf("smithy count good at %d \n", Game.supplyCount[smithy]);
		count++;
	}
	else{
		printf("Smithy count not correct \n");
	}

	if(supplyCount(adventurer, &Game) == 0){
		printf("Adventurer count correct at %d \n", Game.supplyCount[adventurer]);
		count++;
	}
	else{
		printf("Adventurer count not correct \n");
	}

	if(supplyCount(curse, &Game) == 20){
		printf("Curse count good at  %d \n", Game.supplyCount[curse]);
		count++;
	}
	else{
		printf("Curse count not correct \n");
	}

	if(supplyCount(council_room, &Game) == 45){
		printf("Council room correct at  %d \n", Game.supplyCount[council_room]);
		count++;
	}
	else{
		printf("Council room count not correct \n");
	}

	if(count == 5){
		printf("Test has passed! \n");
	}
	else{
		printf("Test has failed! \n");
	}


return 0;
}