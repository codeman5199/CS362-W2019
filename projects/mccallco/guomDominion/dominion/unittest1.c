//
//  unittest1: test of dominion.c shuffle function
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
    int shuffle1[MAX_DECK];
    int shuffle2[MAX_DECK];
    int playercount = 2;
    int seed = 700;
    int player;
    int shuffleMatch;

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(playercount, k, seed, &G);
    //make mock state
    //struct gamestate* testState = newGame();
    //initializeGame(playercount, k, seed, testState);

    //check that doesnt work for 0 or 5 players
    printf("TESTING shuffle(): \n");
#if (DEBUG_PRINT == 1)
    printf("Testing function for player -1:\n");
#endif
    player = -1;
    if(shuffle(player, &G) == -1){
        printf("    Shuffle Failed.     Test pass.\n");
    }
    else{
        printf("    TEST FAILURE. \n");
    }

#if (DEBUG_PRINT == 1)
    printf("Testing function for player 10:\n");
#endif
    player = 10;
    if(shuffle(player, &G) == -1){
        printf("    Shuffle Failed.     Test pass.\n");
    }

    //shuffle player twice and compare decks
    
#if (DEBUG_PRINT == 1)
    printf("Testing double shuffle of player 1:\n");
#endif
    player = 1;
    shuffle(player, &G);
    for(i = 0; i < G.discardCount[player]; i++){
        shuffle1[i] = G.deck[player][i];
    }
    shuffle(player, &G);
    for(i = 0; i < G.discardCount[player]; i++){
        shuffle2[i] = G.deck[player][i];
    }
    for(i = 0; i < G.discardCount[player]; i++){
        if(shuffle1[i] == shuffle2[i]){
            shuffleMatch++;
        }
    }
    if(shuffleMatch == MAX_DECK){
        printf("    Deck was not shuffled.      Test Failure \n");
    }
    else if(shuffleMatch > MAX_DECK/2){
        printf("    Found %d matches out of %d cards.      Test Failure \n", shuffleMatch, MAX_DECK);
    }
    else{
        printf("Found %d matches.    Test PASS.  \n", shuffleMatch);
    }

    //shuffle compare two different player decks.
#if (DEBUG_PRINT == 1)
    printf("Testing shuffle of player 1 vs player 2:\n");
#endif
    shuffleMatch =0;
    shuffle(0, &G);
    for(i = 0; i < G.discardCount[player]; i++){
        shuffle1[i] = G.deck[player][i];
    }
    shuffle(1, &G);
    for(i = 0; i < G.discardCount[player +1]; i++){
        shuffle2[i] = G.deck[player+ 1][i];
    }
    for(i = 0; i < G.discardCount[player]; i++){
        if(shuffle1[i] == shuffle2[i]){
            shuffleMatch++;
        }
    }
    if(shuffleMatch == MAX_DECK){
        printf("    Deck was not shuffled.      Test Failure \n");
    }
    else if(shuffleMatch > MAX_DECK/2){
        printf("    Found %d matches out of %d cards.      Test Failure \n", shuffleMatch, MAX_DECK);
    }
    else{
        printf("Found %d matches.    Test PASS.  \n", shuffleMatch);
    }

    //shuffle with empty deck
#if (DEBUG_PRINT == 1)
    printf("Testing shuffle of player 1 with empty discard:\n");
#endif
    initializeGame(playercount, k, seed, &G);
    player = 0;
    shuffleMatch =0;
    for(i = 0; i < G.discardCount[player]; i++){
        G.discard[player][i] = -1;
    }
    G.discardCount[player] = 0;
    shuffle(0, &G);
    for(i = 0; i < G.deckCount[player]; i++){
        shuffle1[i] = G.deck[player][i];
    }
    for(i = 0; i < G.discardCount[player]; i++){
        G.discard[player][i] = -1;
    }
    G.discardCount[player] = 0;
    shuffle(0, &G);
    for(i = 0; i < G.deckCount[player]; i++){
        shuffle2[i] = G.deck[player][i];
    }
    for(i = 0; i < G.deckCount[player]; i++){
        if(shuffle1[i] == shuffle2[i]){
            shuffleMatch++;
        }
    }
    if(shuffleMatch == MAX_DECK){
        printf("    Deck was not shuffled.      Test Failure \n");
    }
    else if(shuffleMatch > MAX_DECK/2){
        printf("    Found %d matches out of %d cards.      Test Failure \n", shuffleMatch, MAX_DECK);
    }
    else{
        printf("Found %d matches.    Test PASS.  \n", shuffleMatch);
    }
}