// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void swap(int * num1, int * num2); // swaps two numbers
void ssort(int * arr, int size) // selection sorting function
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
  
  int count; // counter variable for outer loop
  int lcv; // counter variable for inner loop
  int minimum; // minimum value in array loop
  
  for(count = 0; count < size; count++){
	  minimum = count;
	  for(lcv = count + 1; lcv < size; lcv++){
		  if(arr[lcv] < arr[minimum])
			  minimum = lcv;
	  }
	  if(count != minimum)
		  swap(&arr[count], &arr[minimum]);
  }
  
  return;
}

void swap(int * num1, int * num2)
{
  int temp; // temporary place holder
  
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
  
  return;
}
#endif
