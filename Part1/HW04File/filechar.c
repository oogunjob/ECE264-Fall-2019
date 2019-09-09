// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  //local variables
  FILE * fileText; // variable for the file being opened
  int onechar; // the index of the charcter
  
  //execution of counting characters
  fileText = fopen(filename, "r");  // opens the file to be read
  
  if(fileText == NULL) // if file cannot be opened, it returns false but does not close
	  return false;
  else
    while((onechar = fgetc(fileText)) != EOF) // if file is opened, reads file character by character until end of file
    {
     if(onechar >= 0 && onechar <= size - 1) // checks if the ASCII value is between 0 and the size of the array
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
  int count; // loop control variable
  
  //prints the value of counts
  for(count = 0; count < size - 1; count++) // checks all index values of the array
  {
	  if(counts[count] != 0 && ((count >= 'a' && count <= 'z') || (count >= 'A' && count <= 'Z'))) // checks if value is a letter
      {		  
	    printf("%d, %c, %d", count, count, counts[count]); // prints the number of times the indexed value occurs in the file
		if(count != size - 1) // determines wheter or not to add new line
          printf("\n");
	  }
	  else if(counts[count] != 0 && (!(count >= 'a' && count <= 'z') || !(count >= 'A' && count <= 'Z'))) // checks if value is not a letter
      {		  
	    printf("%d,  , %d", count, counts[count]); // prints the number of times the index occurs in the file
		if(count != size - 1) // determines wheter or not to add new line
          printf("\n");
	  }	
  }
  
  return;
}
#endif
