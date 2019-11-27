// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

void replaceAll(char * str, const char * oldWord, const char * newWord); // replaces the occurences of the old word with new word
int fillSudoku(int puzzle[][9], int row, int col);
int isAvailable(int puzzle[][9], int row, int col, int num);

int main(int argc, char * * argv)
{
  // argv[1]: input file
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }

  // 1. Replace all the '-' with 0's
  
 // File pointer to hold reference of input file
  FILE * fPtr; // initial state of the file
  FILE * fTemp; // final state of the file
    
  char buffer[BUFFER_SIZE]; // the buffer
  char oldWord[2]; // old word, "-"
  char newWord[2]; // new word, "0"
    
  char dash[] = "-";
  char zero[] = "0";

  strcpy(oldWord, dash); // stores old word with '-'
  strcpy(newWord, zero); // stores new word with '0'

  // Opens all required files
  fPtr  = fopen(argv[1], "r");
  fTemp = fopen(argv[1], "r+"); 

  // if either file cannot be opened, returns EXIT_FAILURE
  if (fPtr == NULL || fTemp == NULL)
  {
	fprintf(stderr, "Error: File could not be opened.");
	return EXIT_FAILURE;
  }

  while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
  {
    // Replace all occurrence of word from current line
    replaceAll(buffer, oldWord, newWord);

    // After replacing write it to temp file.
    fputs(buffer, fTemp);
  }

  fclose(fPtr); // closes the file
  fclose(fTemp); // closes the file

  // 2. Store the integers into a 2D array

  int soduku[9][9]; // the 2D array that holds the soduku board

  int i; // index for rows in array
  int j; // index for columns in array


  FILE * file = fopen(argv[1], "r"); // reopens the file

  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      char c;
      if (fscanf(file, " %c", &c) != 1)
	  {
		fprintf(stderr, "File could not be read");
		return 0;
	  }
      
	  else if (isdigit((unsigned char)c))
	  {
        soduku[i][j] = c - '0';
	  }
        
	  else
	  {
        soduku[i][j] = 0;
	  }
    }
  }
  
  fclose(file); // closes the file



  //3. Find and print solution to soduku board
  if(fillSudoku(soduku, 0, 0))
  {
    for(i = 1; i < 10; ++i)
    {
      for(j = 1; j < 10; ++j)
	  {
	    printf("%d", soduku[i - 1][j - 1]);
	  }
      
	  printf("\n");
    }
  }
	
  else 
  {
    fprintf(stderr,"Error: Solution could not be determined.\n");
	return EXIT_FAILURE;
  }
 
 
  return EXIT_SUCCESS;
}



void replaceAll(char *str, const char *oldWord, const char *newWord)
{
  char * pos; // current position
  char temp[BUFFER_SIZE];
  int index; // index in the file
  int owlen; // length of the old word

  owlen = strlen(oldWord); 
  index = 0;

  // repeat till all occurrences are replaced. 
  while ((pos = strstr(str, oldWord)) != NULL)
  {
    // Backup current line
    strcpy(temp, str);

    // Index of current found word
    index = pos - str;

    // Terminate str after word found index
    str[index] = '\0';

    // Concatenate str with new word 
    strcat(str, newWord);
        
    // Concatenate str with remaining words after 
    // oldword found index.
    strcat(str, temp + index + owlen);
  }
}

int fillSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i, j;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}