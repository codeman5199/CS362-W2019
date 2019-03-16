//
//  unittest4: test of dominion.c fullDeckCount() function
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
    int player, card;
    int count, precount;

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    //create new gamestate
    initializeGame(playercount, k, seed, &G);
    
    //check for invalid number of players
#if (DEBUG_PRINT == 1)
    printf("Testing for invalid player number.\n");
#endif
    player = -4;
    count = fullDeckCount(player, 1, &G);
    if(count  == 0){
        printf("    Player -4 has %d estate cards.      Test pass.\n", count);
    }
    else{
        printf("    Player -4 has %d estate cards.      Test FAILURE.\n", count);
    }
    
    //check for invalid card
#if (DEBUG_PRINT == 1)
    printf("Testing for invalid card.\n");
#endif
    player = 0;
    card = treasure_map + 3;
    count = fullDeckCount(player, card, &G);
    if(count  == 0){
        printf("    Player has %d invalid cards.        Test pass.\n", count);
    }
    else{
        printf("    Player has %d invalid cards.        Test FAILURE.\n", count);
    }

    //check recognizes change to hand
#if (DEBUG_PRINT == 1)
    printf("Testing adding 3 estate cards to hand.\n");
#endif   
    player = 0;
    card = 1;
    precount = fullDeckCount(player, card, &G);
    for(i = 0; i < 3; i++){
        gainCard(card, &G, 2, player);
    }
    count = fullDeckCount(player, card, &G);
    if(count == (3 + precount)){
        printf("    Player had %d estate cards, and now had %d estate cards.        Test pass.\n", precount, count);
    }
    else{
        printf("    Player had %d estate cards, and now has %d estate cards.        Test FAILURE.\n", precount, count);
    }

    //check recognizes change to deck
#if (DEBUG_PRINT == 1)
    printf("Testing adding 3 estate cards to deck.\n");
#endif   
    player = 0;
    card = 1;
    precount = fullDeckCount(player, card, &G);
    for(i = 0; i < 3; i++){
        gainCard(card, &G, 1, player);
    }
    count = fullDeckCount(player, card, &G);
    if(count == (3 + precount)){
        printf("    Player had %d estate cards, and now had %d estate cards.        Test pass.\n", precount, count);
    }
    else{
        printf("    Player had %d estate cards, and now has %d estate cards.        Test FAILURE.\n", precount, count);
    }

    //check recognizes change to discard
#if (DEBUG_PRINT == 1)
    printf("Testing adding 3 estate cards to discard.\n");
#endif   
    player = 0;
    card = 1;
    precount = fullDeckCount(player, card, &G);
    for(i = 0; i < 3; i++){
        gainCard(card, &G, 0, player);
    }
    count = fullDeckCount(player, card, &G);
    if(count == (3 + precount)){
        printf("    Player had %d estate cards, and now had %d estate cards.        Test pass.\n", precount, count);
    }
    else{
        printf("    Player had %d estate cards, and now has %d estate cards.        Test FAILURE.\n", precount, count);
    }
}
