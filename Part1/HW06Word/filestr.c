// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char * word, char * line, int size)
{
  //local variables
  FILE * file; // storage variable for the file
  int sum; // the amount of times that the word occurs
  char * pointer; // the value that the strstr function returns 
  file = fopen(filename, "r"); // opens up the file to be read
 
  if(file == NULL) // checks if the file can be opened or not
  {
    return (-1);
  }
  
  sum = 0; // initilizes value of sum as 0 if the file was opened
  
  while(fgets(line, size, file) != NULL)
  {
   pointer = strstr(line, word);
   while(pointer != NULL)
   {
    pointer += strlen(word); // sets the pointer equal to full length of the word
    pointer = strstr(pointer, word);  // checks that the pointer is equal to word
    sum++; // increments amount of times word is found
    }
  }
  
  fclose(file); //closes the file
 
  return (sum);
}
#endif
