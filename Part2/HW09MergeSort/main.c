// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // argv[1]: name of input file (binary)
  // argv[2]: name of output file (binary)
  if (argc != 3)
    {
      return EXIT_FAILURE;
    }

  // create a pointer to store the elements read from the input file
  int * arr; // the pointer array that stores the elements
  
  // size of the array
  int size;

  bool rtv; // return value that determines state of function
  
  size = 0;
  
  // read the input file, allocate memory
  
  rtv = readData(argv[1], &arr, &size);
  if (rtv == false)
    {
      free(arr);
      return EXIT_FAILURE;
    }

  // call mergeSort
  
  mergeSort(arr, 0, size - 1);

  // write results to the output file
  
  rtv = writeData(argv[2], arr, size);

  if (rtv == false)
    { 
      free(arr);
      return EXIT_FAILURE;
    }
	
  free(arr);
  return EXIT_SUCCESS;
}
#endif
