//
//  unittest2: test of dominion.c compare function
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

// a > b = 1    a < b = -1   a == b = 0

int main(){
    int i;
    int idata1[3] = {1, 5, 8};
    int idata2[3] = {0, 5, 9};
    char cdata1[3] = {'A', 'a', '+'};
    char cdata2[3] = {'?', 'a', 'z'};
    int result;

    //compare ints
    for(i = 0; i < 3; i++){
#if (DEBUG_PRINT == 1)
        printf("Comparing %d and %d:\n",idata1[i], idata2[i]);
#endif
        result = compare(&idata1[i], &idata2[i]);
        printf("    recieved return %d,", result);
        if(idata1[i] > idata2[i] && result == 1){
            printf(" expected 1.    Test pass.\n");
        }
        else if(idata1[i] < idata2[i] && result == -1){
            printf(" expected -1.   Test pass.\n");
        }
        else if(idata1[i] == idata2[i] && result == 0){
            printf(" expected 0.    Test pass.\n");
        }
        else{
            printf("    Test FAILURE.\n");
        }
    }

    //compare chars
    for(i = 0; i < 3; i++){
#if (DEBUG_PRINT == 1)
        printf("Comparing %c and %c:\n",cdata1[i], cdata2[i]);
#endif
        result = compare(&cdata1[i], &cdata2[i]);
        printf("    Recieved return %d,", result);
        if(cdata1[i] > cdata2[i] && result == 1){
            printf(" expected 1.    Test pass.\n");
        }
        else if(cdata1[i] < cdata2[i] && result == -1){
            printf(" expected -1.   Test pass.\n");
        }
        else if(cdata1[i] == cdata2[i] && result == 0){
            printf(" expected 0.    Test pass.\n");
        }
        else{
            printf("    Test FAILURE.\n");
        }
    }
}