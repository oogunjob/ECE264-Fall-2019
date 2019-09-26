// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  //local variables
  int vectorCount; // the number of vectors in the file
  Vector * vectorArray; // array that holds space for the vectors
  bool rtv; // boolean answer for validation of file success
  
  // argv[1]: name of input file (binary)
  // argv[2]: name of output file (binary)
  
  //check whether there are three arguments.
  // If not, return EXIT_FAILURE. DO NOT print anything
  if(argc != 3)
  {
    return EXIT_FAILURE;
  }
  
  // use argv[1] as the input to countVector, save the result
  vectorCount = countVector(argv[1]);
  
  // if the number of vector is 0 or negative, return EXIT_FAILURE
  if(vectorCount <= 0)
  {
    return EXIT_FAILURE;
  }
  
  // otherwise, allocate memory for an array of vectors
  vectorArray = malloc(sizeof(Vector) * vectorCount);
  
  
  // read the vectors from the file whose name is argv[1]. save the
  // results in the allocated array
  // if reading fails, release memory and return EXIT_FAILURE
  rtv = readVector(argv[1], vectorArray, vectorCount);
  
  if(rtv == false)
  {
    free(vectorArray);
    return EXIT_FAILURE;
  }

#ifdef DEBUG
  printVector(vecArr, numElem);
#endif  


#ifdef DEBUG
  printf("\n");
  printVector(vectorArray, numElem);
#endif  

  // write the sorted array to the file whose name is argv[2]
  // if writing fails, release memory and return EXIT_FAILURE
  
  // NOT YET COMPLETED
  
 
  // release memory, return EXIT_SUCCESS
  free(vectorArray);
  return EXIT_SUCCESS;
}
#endif
