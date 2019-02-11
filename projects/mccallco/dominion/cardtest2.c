//
//  cardtest2: test of dominion.c Adventurer card
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
    int hand1, hand2, i;
    int z = 0;
    int player = 0;
    int temphand[MAX_HAND];
    int drawntreasure = 0;
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    //create new gamestate
    initializeGame(playercount, k, seed, &G);

    //test adventurer with less than 2 treasurecards in deck
#if (DEBUG_PRINT == 1)
    printf("Testing function with no treasure cards in deck.\n");
#endif
    for(i = 0; i < G.deckCount[player];i++){                //remove all treasure cards from deck
        if(G.deck[player][i] >=4 || G.deck[player][i] <=6 ){
            G.deck[player][i] = 8;
        }
    }
    hand1 = G.handCount[player];
    switchAdventurer(&G, player, temphand, &drawntreasure, z);
    hand2 = G.handCount[player];
    //printf("%d %d\n",hand1, hand2);
    if(hand2 - hand1 == 0){
        printf("    Number of cards gained from adventurer: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from adventurer: %d.    Test FAILURE.\n", (hand2-hand1));
    }

    //test with empty deck
#if (DEBUG_PRINT == 1)
    printf("Testing function with empty deck.\n");
#endif
    drawntreasure = 0;
    for(i = 0; i < G.deckCount[player];i++){         //empty deck
        G.deck[player][i] = -1;
    }
    G.deckCount[player] = 0;
    hand1 = G.handCount[player];
    switchAdventurer(&G, player, temphand, &drawntreasure, z);
    hand2 = G.handCount[player];
    //printf("%d %d\n",hand1, hand2);
    if(hand2 - hand1 == 2){
        printf("    Number of cards gained from adventurer: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from adventurer: %d.    Test FAILURE.\n", (hand2-hand1));
    }

#if (DEBUG_PRINT == 1)
    printf("Testing function with appropriate starting position.\n");
#endif
    initializeGame(playercount, k, seed, &G);
    drawntreasure = 0;
    //test standard adventurer
    for(i = 0; i < 3; i++){
      gainCard(silver, &G, 1, player);
    }
    hand1 = G.handCount[player];
    switchAdventurer(&G, player, temphand, &drawntreasure, z);
    hand2 = G.handCount[player];
    //printf("treasure %d\n",drawntreasure);
    if(hand2 - hand1 == 2){
        printf("    Number of cards gained from adventurer: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from adventurer: %d.    Test FAILURE.\n", (hand2-hand1));
    }

#if (DEBUG_PRINT == 1)
    printf("Testing function with empty starting hand.\n");
#endif
    initializeGame(playercount, k, seed, &G);
    drawntreasure = 0;
    for(i = 0; i < 3; i++){
      gainCard(silver, &G, 1, player);
    }
    for(i = 0; i < G.handCount[player]; i++){
      G.hand[player][i] = -1;
    }
    G.handCount[player] = 0;
    hand1 = G.handCount[player];
    switchAdventurer(&G, player, temphand, &drawntreasure, z);
    hand2 = G.handCount[player];
    //printf("treasure %d\n",drawntreasure);
    if(hand2 - hand1 == 2){
        printf("    Number of cards gained from adventurer: %d.    Test pass.\n", (hand2-hand1));
    }
    else{
        printf("    Number of cards gained from adventurer: %d.    Test FAILURE.\n", (hand2-hand1));
    }
 
}