//
//  unittest3: test of dominion.c buyCard() function
//  Author: Cody McCall
//

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//set to 0 to remove print from output
#define DEBUG_PRINT 1

int main(){
    int i;
    int playercount = 2;
    int seed = 700;
    int cardMatchInit = 0;
    int cardMatchFinal = 0;
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    //create new gamestate
    initializeGame(playercount, k, seed, &G);

    G.whoseTurn = 1;
    G.numBuys = 0;
    //test buying with and without enough buys
#if (DEBUG_PRINT == 1)
    printf("Testing function buy with 0 buys.\n");
#endif
    if(buyCard(0, &G) == -1){
        printf("    No cards bought. %d buys remaining.     Test pass.\n", G.numBuys);
    }
    else{
        printf("    %d buys remaining.      Test FAILURE.\n", G.numBuys);
    }

    G.numBuys = 5;
#if (DEBUG_PRINT == 1)
    printf("Testing function buy with 5 buys.\n");
#endif
    if(buyCard(0, &G) == 0 && G.numBuys == 4){
        printf("    %d buys remaining.      Test pass.\n", G.numBuys);
    }
    else{
        printf("    %d buys remaining.      Test FAILURE.\n", G.numBuys);
    }
    
    //test buying when there isnt enough of the card
    G.supplyCount[estate] = 0;
#if (DEBUG_PRINT == 1)
    printf("Testing estate buy when there are %d estate cards remaining.\n", G.supplyCount[estate]);
#endif   
    if(buyCard(1, &G) == -1){
        printf("    No cards bought. Now %d estates in supply.      Test Pass.\n", G.supplyCount[estate]);
    }
    else{
        printf("    Now %d estates in supply.       Test FAILURE.\n", G.supplyCount[estate]);
    }

    //test buying with estate in supply
    G.supplyCount[estate] = 1;
#if (DEBUG_PRINT == 1)
    printf("Testing estate buy when there are %d estate cards remaining.\n", G.supplyCount[estate]);
#endif   

    for(i = 0; i < MAX_DECK; i++){
        if(G.discard[G.whoseTurn][i] == 1){
            cardMatchInit++;
        }
    }
    //printf("Discovered %d matches.\n", cardMatch);

    if(buyCard(1, &G) == 0){
        printf("    Now %d estates in supply.       Test Pass.\n", G.supplyCount[estate]);
    }
    else{
        printf("    Now %d estates in supply.       Test FAILURE.\n", G.supplyCount[estate]);
    }
#if (DEBUG_PRINT == 1)
    printf("Checking bought card went to discard.\n");
#endif 
    for(i = 0; i < MAX_DECK; i++){
        if(G.discard[G.whoseTurn][i] == 1){
            cardMatchFinal++;
        }
    }
    if(cardMatchFinal == 1 + cardMatchInit){
        printf("    %d estate cards in discard before buy, %d estates after buy.        Test pass.\n", cardMatchInit, cardMatchFinal);
    }
    else{
        printf("    %d estate cards in discard before buy, %d estates after buy.        Test FAILURE.\n", cardMatchInit, cardMatchFinal);
    }

    //test buying without enough money
    G.coins = 0;
#if (DEBUG_PRINT == 1)
    printf("Buying cards with 0 coins.\n");
#endif 
    if(buyCard(1, &G) == -1){
        printf("    No cards bought. %d coins remaining.        Test pass.\n", G.coins);
    }
    else{
        printf("    %d coins remaining.         Test FAILURE.\n", G.coins);
    }

    G.coins = 10;
#if (DEBUG_PRINT == 1)
    printf("Buying cards with 10 coins.\n");
#endif 
    if(buyCard(2, &G) == 0){
        printf("    Bought card for %d. %d coins remaining.         Test pass.\n",getCost(2), G.coins);
    }
    else{
        printf("    %d coins remaining.         Test FAILURE.\n", G.coins);
    }
}