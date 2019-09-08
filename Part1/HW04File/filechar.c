// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  //local variables
  FILE * fileText; //storage variable for the file being opened
  int onechar; //the index of the charcter
  
  //execution
  fileText = fopen(filename, "r");  // opens the file to be read
  
  if(file == NULL) //if file cannot be opened, it returns false but does not close
	  return false;
  else
    while((onechar = fgetc(fileText)) != EOF) //if file is opened, reads file character by character until end of file
    {
     if(onechar > 0 && onechar < size - 1) // checks if the ASCII value is between 0 and the size of the array
       counts[onechar] += 1; // increments index of character in array by one
    }
  	
  fclose(fileText); // closes the file
	
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  //local variables
  int count;
  
  
  
  
  
  
  
  
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
}
#endif
