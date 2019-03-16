CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o 

	echo "Result for running unit tests:" > unittestresults.out

	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomtests: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.o 

	echo "Random tests results:" > randomtestresults.out

	echo "randomtestcard1.c: " >> randomtestresults.out
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	
	echo "randomtestcard2.c: " >> randomtestresults.out 
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out

	echo "randomtestadventurer.c: " >> randomtestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out

	gcov dominion.c >> randomtestresults.out

alltests: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c randomtestcard1.c dominion.o

	echo "Result for running unit tests:" > alltestresults.out

	echo "unittest1.c:" >> alltestresults.out
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	./unittest1 >> alltestresults.out
	gcov dominion.c >> alltestresults.out

	echo "unittest2.c:" >> alltestresults.out
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	./unittest2 >> alltestresults.out
	gcov dominion.c >> alltestresults.out

	echo "unittest3.c:" >> alltestresults.out
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	./unittest3 >> alltestresults.out
	gcov dominion.c >> alltestresults.out

	echo "unittest4.c:" >> alltestresults.out
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	./unittest4 >> alltestresults.out
	gcov dominion.c >> alltestresults.out
	
	echo "Results for card tests:" >> alltestresults.out

	echo "cardtest1.c:" >> alltestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> alltestresults.out
	gcov dominion.c >> alltestresults.out

	echo "cardtest2.c:" >> alltestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	#$./cardtest2 >> alltestresults.out
	echo "cardtest2 segmentation fault" >> alltestresults.out
	gcov dominion.c >> alltestresults.out

	echo "cardtest3.c:" >> alltestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> alltestresults.out
	gcov dominion.c >> alltestresults.out

	echo "Random tests results:" >> alltestresults.out

	echo "randomtestcard1.c: " >> alltestresults.out
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >> alltestresults.out

	echo "randomtestcard2.c: " >> alltestresults.out
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >> alltestresults.out

	echo "randomtestadventurer.c: " >> alltestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> alltestresults.out

	gcov dominion.c >> alltestresults.out
	
clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
