// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
	
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  //local variables
  int count; // index of the loop
  int leftIndex; // the number of elements in the left deck
  int rightIndex; // the number of elements in the right deck
  
  for(count = 0; count < origDeck.size - 1; count++)
  {
    leftIndex = count + 1; // the index of the left deck
	rightIndex = origDeck.size - count - 1; // the index of the right deck
	
	memcpy(leftDeck[count].cards, origDeck.cards,  leftIndex * sizeof(char)); // orginial deck copies 'left index' amount of cards into the left deck 
	memcpy(rightDeck[count].cards, &origDeck.cards[count + 1], rightIndex * sizeof(char)); // orginial deck copies 'right index' amount of cards into the right deck
	
	rightDeck[count].size = rightIndex; // updates the size of how many cards are in a character array in the left deck
	leftDeck[count].size = leftIndex; // updates the size of how many cards are in a character array in the left deck
  }
 
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
    //local variables
	CardDeck tempDeck;
    tempDeck.size = 0;

    // helper function call
    helperFunction(tempDeck, leftDeck, rightDeck);
	
}

void helperFunction(CardDeck combinedDeck, CardDeck leftDeck, CardDeck rightDeck)
{
	//local variables
	int count; // keeps track of the index
	
	// Makes sure the left deck isn't empty
	if (leftDeck.size == 0)
    {
        // if the deck is empty, adds remaining rightDeck cards
        for(count = 0; count < rightDeck.size; count++)
        {
            // Copies cards into new deck
            memcpy(&combinedDeck.cards[combinedDeck.size], &rightDeck.cards[count], 1);
            
            // Updates the size of combined deck
            combinedDeck.size = combinedDeck.size + 1; 
        }
		
        // prints the deck
        printDeck(combinedDeck);
        
		return;
    }
	
    // Makes sure the right deck isn't empty
	else if (rightDeck.size == 0)
    {
        // if the deck is empty, adds remaining leftDeck cards
        for(count = 0; count < leftDeck.size; count++)
        {
            
            memcpy(&combinedDeck.cards[combinedDeck.size], &leftDeck.cards[count], 1);
           
            // Update the size of combinedDeck
            combinedDeck.size = combinedDeck.size + 1; 
        }
		
        // prints the deck
        printDeck(combinedDeck);
		
        return;
    }

    // Make a new left deck for recursive calling
    CardDeck new_leftDeck;
    
	new_leftDeck.size = 0; 

    // Make a copy of combined deck
    CardDeck combinedDeckA; // a copy of the combined deck
    
	combinedDeckA.size = combinedDeck.size; // sets the size of the new combined deck equal to the orignial combined deck
	
    for(count = 0; count < (combinedDeck.size); count++)
    {  
	  memcpy(&combinedDeckA.cards[count], &combinedDeck.cards[count], 1);  
	}

	// copies from the right deck to add to the new deck
    memcpy(&combinedDeckA.cards[combinedDeckA.size], &leftDeck.cards[0], 1);
    combinedDeckA.size += 1;
    
    // fills the new left deck with cards
    for(count = 1; count < (leftDeck.size); count++)
    {
        memcpy(&new_leftDeck.cards[count - 1], &leftDeck.cards[count], 1);
        new_leftDeck.size += 1;
    }
    
    // calls the function again for the combined deck
    helperFunction(combinedDeckA, new_leftDeck, rightDeck);



    // Make a new right deck for recursive calling
    CardDeck new_rightDeck;
    new_rightDeck.size = 0;
    
    // Make a copy of combined deck
    CardDeck combinedDeckB; // copy of the combined deck
    combinedDeckB.size = combinedDeck.size;
	
    for(count = 0; count < (combinedDeck.size); count++)
    {  
      memcpy(&combinedDeckB.cards[count], &combinedDeck.cards[count], 1);  
	}

	// copies from the right deck to add to the new deck
    memcpy(&combinedDeckB.cards[combinedDeckB.size], &rightDeck.cards[0], 1);
    combinedDeckB.size += 1;
    
    // fills the new left deck with cards
    for(count = 1; count < (rightDeck.size); count++)
    {  
	  memcpy(&new_rightDeck.cards[count - 1], &rightDeck.cards[count], 1); new_rightDeck.size += 1;  
	}
    
    // calls the function again for the combined deck
    helperFunction(combinedDeckB, leftDeck, new_rightDeck);
	
}

#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
  //local variables
  int numCombinations; // the number of possible left and right decks
  int count; // loop control variable for interleave
  
  numCombinations = origDeck.size - 1;
  
  if(numCombinations > 0)
  {
    //memory allocation to store possible left and right decks
    CardDeck * leftDeck; // left deck
    CardDeck * rightDeck; // right deck
  
    leftDeck = malloc(numCombinations * sizeof(CardDeck));
    rightDeck = malloc(numCombinations * sizeof(CardDeck));
  
    //divides the cards
    divide(origDeck, leftDeck, rightDeck);
  
    //send each pair to the interleave function
    for(count = 0; count < numCombinations; count++)
    {
      interleave(leftDeck[count], rightDeck[count]);
    }
  
    //release of allocated memory
    //free(leftDeck);
    //free(rightDeck);
  }
  
  
}
#endif
