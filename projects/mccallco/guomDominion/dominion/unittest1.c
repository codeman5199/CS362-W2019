/******************************************************
This is the unit test for the function getCost in
dominion.c



*****************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int main(int argc, char** argv){

int count = 0;

if(!getCost(curse)){
	printf("curse card good! \n");
	count++;
}

if(getCost(estate) == 2){
	printf("estate card good! \n");
	count++;
}

if(getCost(gold) == 6){
	printf("gold card good! \n");
	count++;
}

if(getCost(adventurer) == 6){
	printf("adventurer card good! \n");
	count++;
}

if(getCost(council_room) == 5){
	printf("council room card good! \n");
	count++;
}

if(getCost(smithy) == 4){
	printf("smithy card good! \n");
	count++;
}

if(getCost(remodel) == 4){
	printf("remodel card good! \n");
	count++;
}

if(getCost(village) == 3){
	printf("village card good! \n");
	count++;
}

if(count == 8){
	printf("All tests passed! \n");
}
	





	return 0;
}