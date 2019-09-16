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
  int count;

  count = 0;  
  file = fopen(filename, "r"); // opens up the file to be read
  char * pointer; // return from strstr


  if(file == NULL) // checks if the file can be opened or not
  {
    return -1;
  }
  
  sum = 0; // initilizes value of sum as 0
  
  while(fgets(line, size, file) != NULL)
  {
   pointer = strstr(line, word);
   while(pointer != NULL)
   {
    pointer += strlen(word); // sets the pointer equal to full length of the word
    pointer = strstr(pointer, word);  // checks that the pointer is equal to word
    count++; // increments amount of times word is found
    }
  }
  
  fclose(file);
 
  return count;
  // filename: name of the input file
  // word: the word to search
  // line: temporary space to store what is read from the file
  // size: size of line
  
  // open a file whose name is filename for reading
  // if fopen fails, return -1. 
  // if fopen succeeds, set sum to zero
  // use fgets to read the file
  // if word appears in a line, add one to sum
  //
  // It is possible that the same word appears multiple times in a line
  // If this word is split in two or more lines, do not count the word.
  //
  // It is also possible that a long line is split by fgets. If this happens,
  // do not count the word.
  //
  // return sum
  //
  // If a line is "aaaaa" and the word is "aa", how is the count defined?
  // In this assignment, the first two letters are consumed when the
  // the first match occurs. Thus, the next match starts at the third
  // character. For this case, the correct answer is 2, not 4.
  
  return 0;
}
#endif
