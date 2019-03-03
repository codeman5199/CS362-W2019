//
//  Random tester for council room card in Dominion
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
#define MAX_RUN 10000

void randomizeGameCards(struct gameState* G, int currentPlayer);

int main(){
    int currentPlayer, playercount, seed, handpos, maxHand, j, i;
    int expectedCards;
    struct gameState G;
    struct gameState tempG;
    int hand1, hand2;
    int numBuys, deckCount;
    long failures = 0;
    long executes = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
             sea_hag, tribute, smithy};
    srand(time(NULL));
    //  councilroom parameters
    //      gamestate
    //      current player
    //      hand pos

    for(i = 0; i < MAX_RUN; i++){
        printf("\n");
    //generate random gamestate
        playercount = (rand() % 3) + 2;
        seed = (rand() % 500) + 1;
        initializeGame(playercount, k, seed, &G);
    //generate random player
        currentPlayer = rand() % playercount;
        randomizeGameCards(&G, currentPlayer);

        maxHand = G.handCount[currentPlayer];
        numBuys = G.numBuys;
        deckCount = G.deckCount[currentPlayer];
    #if (PRINT_ERROR)
        printf("handcount: %d\n deckcount: %d\n buys: %d\n", maxHand, deckCount, numBuys);
        printf("playercount: %d\n seed: %d\n currentPlayer: %d \n ", playercount, seed, currentPlayer);
    #endif

        if(deckCount != 0){
            //generate random handpos for this gamestate
            for(j = 0; j <= maxHand*2; j++){
                if(maxHand == 0){
                    handpos = 0;
                }
                else{
                    handpos = (rand() % maxHand);
                }
        #if (PRINT_ERROR)
            printf("handpos: %d\n", handpos);
        #endif

                tempG = G;
                expectedCards = 3;          //expected = +4 drawn cards -1 from used card
                hand1 = tempG.handCount[currentPlayer];
                switchCouncilRoom(&tempG, currentPlayer, handpos);
                printf("councilroom exe\n");
                hand2 = tempG.handCount[currentPlayer];
                executes++;
                if((hand2 - hand1) == expectedCards && numBuys == tempG.numBuys - 1){
                    printf("Test pass \n");
                }
                else{
                    printf("Test fail \n");
            #if (PRINT_ERROR)
                    printf("DATA--\n Expected cards : %d\n Found cards : %d\n", expectedCards ,(hand2 - hand1));
                    printf(" Expected buys: %d\n Found buys: %d\n", numBuys + 1, tempG.numBuys);
            #endif
                    failures ++;
                }
            }
        }
        else{
            printf("Test fail. Init Error \n");
        }
    
    }
    printf("%li failures out of %li executes\n", failures, executes);
}

void randomizeGameCards(struct gameState* G, int currentPlayer){
    int randDeck = rand() % 50;
    if(randDeck == 0)
        return;
    int randHand = rand() % randDeck;
    int i;
    //add random cards to deck
    for(i = 0; i < randDeck; i++){
        G->deck[currentPlayer][G->deckCount[currentPlayer]] = rand() % 26;
        G->deckCount[currentPlayer]++;
    }
    //add random cards to hand
    if(currentPlayer != 1){
        for(i = 0; i < randHand;i++){
            drawCard(currentPlayer, G);
        }
    }
}