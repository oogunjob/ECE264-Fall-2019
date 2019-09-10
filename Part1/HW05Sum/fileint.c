// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  //local variables
  FILE * file; // the storage variable for the file being opened
  int num; // the value of the number currently being read
  
  sum = 0;
  
  file = fopen(filename, "r"); // opens the file
  
  // checks if the file can be opened or not
  // if not, it returns false
  if(file == NULL)
	  return false;
  
  //finds the sum of the numbers in the file
  while(fscanf(file, "%d", &num) != EOF)
  {
    sum += num;
  }
  
  fclose(file); // closes the file

  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
  return true;
}
#endif
