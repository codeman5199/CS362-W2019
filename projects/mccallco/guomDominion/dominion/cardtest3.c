//
//  cardtest3: test of dominion.c Council Room card
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
    int seed = 1000;
    int i, handDiff, buyDiff, handDiff2;
    int player = 0;
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    //create new gamestate
    initializeGame(playercount, k, seed, &G);

    //test with empty deck
#if (DEBUG_PRINT == 1)
    printf("Testing function with empty deck.\n");
#endif
    for(i = 0; i < G.deckCount[player];i++){         //empty deck
        G.deck[player][i] = -1;
    }
    G.deckCount[player] = 0;
    handDiff = G.handCount[player];
    handDiff2 = G.handCount[player + 1];
    buyDiff = G.numBuys;
    council_roomCard(player, &G, G.handCount[player]);
    //printf("%d %d\n",hand1, hand2);
    if(G.handCount[player] - handDiff == 4 && G.numBuys - buyDiff == 1){
        printf("    Number of cards player gained from Councilroom: %d.    Test pass.\n", (G.handCount[player] - handDiff));
    }
    else{
        printf("    Number of cards player gained from Councilroom: %d.    Test FAILURE.\n", (G.handCount[player] - handDiff));
    }
    if(G.numBuys - buyDiff == 1){
        printf("    Number of buys gained: %d    Test pass.\n",(G.numBuys - buyDiff == 1));
    }
    else{
        printf("    Number of buys gained: %d    Test FAILURE.\n",(G.numBuys - buyDiff == 1));
    }
    if(G.handCount[player + 1] - handDiff2 == 1){
        printf("    Number of cards other player gained from Councilroom: %d.   Test pass.\n", (G.handCount[player + 1] - handDiff2));
    }
    else{
        printf("    Number of cards other player gained from Councilroom: %d.   Test FAILURE.\n", (G.handCount[player + 1] - handDiff2));
        
    }

    //test standard
#if (DEBUG_PRINT == 1)
    printf("Testing function with standard starting conditions.\n");
#endif
    initializeGame(playercount, k, seed, &G);
    for(i = 0; i < 5; i++){
        gainCard(1, &G, 1, player);
    }
    handDiff = G.handCount[player];
    handDiff2 = G.handCount[player + 1];
    buyDiff = G.numBuys;
    council_roomCard(player, &G, G.handCount[player]);
    //printf("%d %d\n",handDiff, G.deckCount[player]);
    if(G.handCount[player] - handDiff == 4 && G.numBuys - buyDiff == 1){
        printf("    Number of cards player gained from Councilroom: %d.    Test pass.\n", (G.handCount[player] - handDiff));
    }
    else{
        printf("    Number of cards player gained from Councilroom: %d.    Test FAILURE.\n", (G.handCount[player] - handDiff));
    }
    if(G.numBuys - buyDiff == 1){
        printf("    Number of buys gained: %d    Test pass.\n",(G.numBuys - buyDiff == 1));
    }
    else{
        printf("    Number of buys gained: %d    Test FAILURE.\n",(G.numBuys - buyDiff == 1));
    }
    if(G.handCount[player + 1] - handDiff2 == 1){
        printf("    Number of cards other player gained from Councilroom: %d.   Test pass.\n", (G.handCount[player + 1] - handDiff2));
    }
    else{
        printf("    Number of cards other player gained from Councilroom: %d.   Test FAILURE.\n", (G.handCount[player + 1] - handDiff2));
        
    }

}