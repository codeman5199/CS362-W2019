//
//  cardtest1: test of dominion.c Smithy card (rewritten to test Matt's code)
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
    int player = 0;
    int handpos = 0;
    int hand1;
    int hand2;

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    //create new gamestate
    initializeGame(playercount, k, seed, &G);

    //check invalid hand position discard
#if (DEBUG_PRINT == 1)
    printf("Testing function with invalid handpos.\n");
#endif
    hand1 = G.handCount[player];
    handpos = G.handCount[player] + 3;
    smithyCard(player, &G, handpos);
    hand2 = G.handCount[player];
    if(hand2 - hand1 == 3){
        printf("    Number of cards gained from Smithy: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from Smithy: %d.    Test FAILURE.\n", (hand2-hand1));
        
    }

    //check that 3 cards are added with valid handpos
#if (DEBUG_PRINT == 1)
    printf("Testing function with invalid handpos.\n");
#endif
    hand1 = G.handCount[player];
    handpos = 1;
    smithyCard(player, &G, handpos);
    hand2 = G.handCount[player];
    printf("%d %d\n",hand1, hand2);
    if(hand2 - hand1 == 3){
        printf("    Number of cards gained from Smithy: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from Smithy: %d.    Test FAILURE.\n", (hand2-hand1));
        
    }

    //check with empty deck
#if (DEBUG_PRINT == 1)
    printf("Testing function with empty deck.\n");
#endif
    for(i = 0; i < G.deckCount[player];i++){  //empty deck
        G.deck[player][i] = -1;
    }
    G.deckCount[player] = 0;
    hand1 = G.handCount[player];
    handpos = 1;
    smithyCard(player, &G, handpos);
    hand2 = G.handCount[player];
    //printf("%d %d\n",hand1, hand2);
    if(hand2 - hand1 == 3){
        printf("    Number of cards gained from Smithy: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from Smithy: %d.    Test FAILURE.\n", (hand2-hand1));
    }
}