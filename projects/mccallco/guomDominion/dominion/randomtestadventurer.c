//
//  Random tester for adventurer card in Dominion
//  Author: Cody McCall
//

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRINT_ERROR 0
#define ONLY_FAIL_PRINT 0
#define MAX_RUN 500000

void randomizeGameCards(struct gameState* G, int currentPlayer);

int main(){
    int hand1, hand2, i, j, seed;
    int expectedCards;
    int playercount, currentPlayer;
    int treasureCount = 0;
    int temphand[MAX_HAND];
    int z, drawntreasure;
    int failures;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
             sea_hag, tribute, smithy};

    srand(time(NULL));          //seed random function
// adventurer paramerters:
//      state
//      current player
    for(i = 0; i < MAX_RUN; i++){
    #if (PRINT_ERROR)
        printf("\n");
    #endif
        treasureCount = 0;
    //  generate random gamestates
        playercount = (rand() % 3) + 2;
        seed = (rand() % 500) + 1;
        initializeGame(playercount, k, seed, &G);
    //  generate random player within range of max players
        currentPlayer = rand() % playercount;

        randomizeGameCards(&G, currentPlayer);

        drawntreasure = 0;
        z = 0;

    #if (PRINT_ERROR)
            printf("playercount: %d\n seed: %d\n currentPlayer: %d \n handcount: %d\n deckcount: %d\n", playercount, seed, currentPlayer, G.handCount[currentPlayer], G.deckCount[currentPlayer]);
    #endif

    // medthod: count treasure cards in deck. if hand increased by treasurecard count pass
        for(j = 0; j < G.deckCount[currentPlayer];j++){
            if (G.deck[currentPlayer][j] == 4 || G.deck[currentPlayer][j] == 5 || G.deck[currentPlayer][j] == 6) treasureCount++;
        }
    #if (PRINT_ERROR)
            printf("Treasure in deck: %d\n", treasureCount);
    #endif
        if(treasureCount >= 2){
            expectedCards = 2;
        }
        else{
            expectedCards = treasureCount;
        }
        hand1 = G.handCount[currentPlayer];
        adventurerCard(drawntreasure, currentPlayer, &G, z, &temphand);
    #if (PRINT_ERROR)
        printf("adventurer exe\n");
    #endif
        hand2 = G.handCount[currentPlayer];
        if((hand2 - hand1) == expectedCards){
    #if(PRINT_ERROR)
            printf("Test pass\n");
    #endif
        }
        else{
    #if (PRINT_ERROR || ONLY_FAIL_PRINT)
            printf("***Test fail***\n");
            printf("DATA--\n Expected : %d\n Found : %d\n", expectedCards, (hand2 - hand1));
    #endif
            failures++;
        }
    }
    printf("%d failures out of %d\n", failures, MAX_RUN);
}

void randomizeGameCards(struct gameState* G, int currentPlayer){
    int i, randHand;
    int randDeck = rand() % 50;
    if(randDeck == 0)
        randHand = rand() % 5;
    else
        randHand = rand() % randDeck;

    //add random cards to deck
    for(i = 0; i < randDeck; i++){
        G->deck[currentPlayer][G->deckCount[currentPlayer]] = rand() % 26;
        G->deckCount[currentPlayer]++;
    }
    
    //add random cards to hand
    for(i = 0; i < randHand;i++){
        drawCard(currentPlayer, G);
    }
}