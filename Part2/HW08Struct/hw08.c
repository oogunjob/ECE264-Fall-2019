// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  //local variables
  FILE * file; // variable that holds the file
  int count; // number of vectors counted in the file
  int fptr[3]; // array for temporary storage of vectors
   
  count = 0; // intializes the value of count as 0
  
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", )
  file = fopen(filename, "r");
  
 // If fopen fails, return -1
  if(file == NULL)
  {
	fclose(file);
	return -1;
  }
  
  // fread ???
  while(fread(fptr , sizeof(int), 3, file))
  {
    count++;
  }

  fprintf(stdout, "Size of vector is %d\n", count);
  return count;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  //local variables
  FILE * file; // variable that holds the file
  
  file = fopen(filename, "r"); 
  
  // if fopen fails, return false
  if(file == NULL)
  {
	fclose(file);
	return false;
  }
  
  // read Vectors from the file ???
  fread(vecArr, sizeof(Vector), size, file);
  
  // if the number of integers is different from size (too
  // few or too many) return false
  
  // NEED TO COUNT THE NUMBER OF INTEGERS FIRST THEN COMPARE IT TO THE SIZE

    /* counts the number of integers in the array
	NOT sure how to account for vecArr.x, vecArr.y, and vecArr.z
    for(count = 0; count < size; count++)
	{
		if(vecArr[count] >= 0)
		  count++;
	}
	*/
	
	/*
    if(count != size)
    {
	   fclose(file);
	   return false;
     }
	 */
  
  // if everything is fine, fclose and return true
  fclose(file);
  
  return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  
  Vector * typecasted_p1 = (Vector *)p1;
  Vector * typecasted_p2 = (Vector *)p2;
	
  // Return comparated value
  return ((typecasted_p1-> x) - (typecasted_p2-> x));
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  //local variables
  FILE * file; // variable that holds the given file
  
  file = fopen(filename, "w"); // opens file to be written
  
  // if fopen fails, return false
  if(file == NULL)
  {
	return false;
  }
  
  // write the array to file using fwrite
  fwrite(vecArr, sizeof(Vector), size, file);
  
  // need to check how many have been written
  // if not all are written, fclose and return false
  
  // NEED TO MAKE SURE THE NUMBER OF WRITTEN ELEMENTS IS EQUAL TO SIZE
  
  fclose(file);
  return true;
  
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
