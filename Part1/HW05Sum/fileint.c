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
  {
    return false;
  }
  
  //finds the sum of the numbers in the file
  while(fscanf(file, "%d", &num) != EOF)
  {
    sum += num; // increments the value of sum
  }

  fclose(file); // closes the file

  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  //local variables
  FILE * file; // the storage variable for the file being opened
    
  file = fopen(filename, "w"); // opens the file up to be written
  
  if(file == NULL) // checks if the file can be opened
  {
    return false;
  }
  
  fprintf(file, "%d\n", sum); // if the file can be opened, writes the sum to the file

  fclose(file); //closes the file  
    
  return true;
}
#endif
