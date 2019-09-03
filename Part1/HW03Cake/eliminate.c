// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // local variables
  int tally; // variable used to assign array values as 'A'
  int count; // loop control variable for the outer loop
  int count2; // loop control varibale for the inner loop
  int remaining; // amount of students who have not been eliminated
  
  count2 = 1; // starts inner to begin counting from 1
  remaining = n; // initial amount of students still remaining in the game
  
  // initializes values of the array to alive
  for(tally = 0; tally < n; tally++){
    arr[tally] = 'A';
  }
  
  // finds index values of all students that have been eliminated and marks them as 'X'
  while(remaining > 1)
  {
    for(count = 0; count < n; count++) 
    {
      if(count2 % k == 0) // checks if the count is an iteration of k
      { 
        if(arr[count] == 'A') // if the student is still in the game, he/she is eliminated
        {			
	      arr[count] = 'X'; //eliminates the student
		  printf("%d\n", count); // prints index of eliminated student
          remaining -= 1;
          count2 = 1; // reinitializes the count to begin counting again from 1 	  
		}
	  }
	  else if (arr[count] == 'A') // if the student is has not been eliminated, it continues on to the next student
		count2 += 1;
	}
  }
  
  //finds the index of the remaining student
  count = 0; //reinitializes count as 0
  
  while(arr[count] != 'A')
	  count++;
  
   printf("%d\n", count); // prints the index of the student who gets the cake

  free (arr);
}
#endif
