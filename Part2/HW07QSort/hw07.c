// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // local variables
  FILE * file; // variable that holds file
  int num; // current number that is read from loop
  int count; //number of integers counted
  
  // execution
  file = fopen(filename, "r"); // opens up the file with integers
  
  if(file == NULL) // if the file is not opened, returns false
  {
    return -1;
  }
  
  // keeps track of the numbers found in the file 
  while(fscanf(file, "%d", &num) == 1)
  {
    count++;
  }
  
  fclose(file); //closes the file
  
  return count;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{ 
  //local variables
  FILE * file; // variable that holds file
  int index; // the current index value of the array
  int count; // number of integers counted
  
  //initialization of variables
  index = 0;
  count = 0;
  
  //execution
  file = fopen(filename, "r");
  
  // stores the integers of the file into the array
  while(fscanf(file, "%d", &intArr[index]) == 1)
  {
    count++; // counts the numbers of integers in the array
	index++; // increases the index
  }
  
  // makes sure the number of integers is equal to the size of the array
  if(count != size)
  {
    fclose(file);
    return false;
  }
  
  // closes the file and returns true if everything is fine
  fclose(file);

  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  return (*(const int*)p1 - *(const int*)p2); //comparision equation
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  //local variables
  FILE * file; // variables that holds the file
  int count; // number of integers prints
  
  //execution
  file = fopen(filename, "w"); // opens up the file
  
  if(file == NULL) // checks if the file can be opened or not
  {
    fclose(file);
    return false;
  }
  
  // prints out the integers to the file
  for(count = 0; count < size; count++)
  {
    fprintf(file, "%d\n", intArr[count]);
  }
  
   fclose(file);
   
   return true;
}
#endif