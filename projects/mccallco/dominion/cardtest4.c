//
//  cardtest4: test of dominion.c 
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
    int playercount = 2;
    int seed = 700;
    int i, handDiff;
    int choice = 1;
    int player = 0;
    int temphand[MAX_HAND];
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    //create new gamestate
    initializeGame(playercount, k, seed, &G);

    //test standard
#if (DEBUG_PRINT == 1)
    printf("Testing function with ideal conditions.\n");
#endif
    //printf("Initial Setup: handsize %d, decksize %d, \n",G.handCount[player], G.deckCount[player]);
    handDiff = G.handCount[player];
    switchFeast(&G, player, choice, temphand);
    if(handDiff - G.handCount[player] == 1){
        printf("Gained %d card from Feast.      Test pass.\n", handDiff - G.handCount[player]);
    }
    else{
        printf("Gained %d card from Feast.      Test FAILURE.\n", handDiff - G.handCount[player]);
    }

    //test with empty hand
#if (DEBUG_PRINT == 1)
    printf("Testing function with empty hand.\n");
#endif
    for(i = 0; i < G.handCount[player]; i++){               //empty hand
      G.hand[player][i] = -1;
    }
    G.handCount[player] = 0;
    //printf("Initial Setup: handsize %d, decksize %d, \n",G.handCount[player], G.deckCount[player]);
    handDiff = G.handCount[player];
    switchFeast(&G, player, choice, temphand);
    if(handDiff - G.handCount[player] == 1){
        printf("Gained %d card from Feast.      Test pass.\n", handDiff - G.handCount[player]);
    }
    else{
        printf("Gained %d card from Feast.      Test FAILURE.\n", handDiff - G.handCount[player]);
    }

    //test with empty supply
#if (DEBUG_PRINT == 1)
    printf("Testing function with empty supply.\n");
#endif
    initializeGame(playercount, k, seed, &G);
    G.supplyCount[choice] = 0;
    //printf("Initial Setup: handsize %d, decksize %d, \n",G.handCount[player], G.deckCount[player]);
    handDiff = G.handCount[player];
    switchFeast(&G, player, choice, temphand);
    if(handDiff - G.handCount[player] == 1){
        printf("Gained %d card from Feast.      Test pass.\n", handDiff - G.handCount[player]);
    }
    else{
        printf("Gained %d card from Feast.      Test FAILURE.\n", handDiff - G.handCount[player]);
    }

    //test with too expensive card (buy provice supply3 for 8 coins)
#if (DEBUG_PRINT == 1)
    printf("Testing function with empty supply.\n");
#endif
    initializeGame(playercount, k, seed, &G);
    choice = 3;
    //printf("Initial Setup: handsize %d, decksize %d, \n",G.handCount[player], G.deckCount[player]);
    handDiff = G.handCount[player];
    switchFeast(&G, player, choice, temphand);
    if(handDiff - G.handCount[player] == 1){
        printf("Gained %d card from Feast.      Test pass.\n", handDiff - G.handCount[player]);
    }
    else{
        printf("Gained %d card from Feast.      Test FAILURE.\n", handDiff - G.handCount[player]);
    }
}