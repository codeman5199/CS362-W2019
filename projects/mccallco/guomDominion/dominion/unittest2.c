/******************************************************
This is the unit test for the function initializeGame in
dominion.c



*****************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


int main(int argc, char** argv){

	struct gameState Game;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    int numPlayers = 1;
    int count = 0;

   	 if(initializeGame(numPlayers, k, 10, &Game) == -1){
   	 	printf("Correct checking of number of players! \n");
   	 	count++;
   	 }

   	numPlayers = 3;

   	struct gameState Game2;

   initializeGame(numPlayers, k, 10, &Game2);

   if(Game2.supplyCount[estate] == 12){
   		printf("currect number of estate! \n");
   		count++;
   }

   if(Game2.supplyCount[curse] == 20){
   		printf("correct number of curse! \n");
   		count++;
   }

   if(Game2.supplyCount[copper] == 60 - (7*numPlayers)){
   		printf("correct number of copper! \n");
   		count++;
   }

   if(Game2.outpostPlayed == 0){
   		printf("correct outpost number! \n");
   		count++;
   }

   if(count == 5){
   		printf("test successful! \n");
   }
   else{
   		printf("test failed! \n");
   }

    




	return 0;
}