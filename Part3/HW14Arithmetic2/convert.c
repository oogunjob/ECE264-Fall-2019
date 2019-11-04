// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// return 2 if the word contains '*'
// return 3 if the word contains '('
// return 4 if the word contains ')'

int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
void copyList(char * array, List * arithlist);
void push(char word, char stack[], int * element, int size);
char pop(char stack[], int * element);
int precedence(char operator);

bool convert(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
	
  int size; // the size of the linked list
  size = 0;
  
  ListNode * p; // the current position in the list
  p = arithlist -> head; // p points the beginning of the list
  
  // counts the number of characters in the list
  while(p != NULL)
  {
	size += strlen(p -> word) - 1;
	p = p -> next; // changes to the next position
  }

  char stack[10000]; // the stack that will hold operations
  char * InfixExpression; // creates a character array that will store the words in the linked list
  
  
  InfixExpression = malloc(sizeof(char) * (size + 1)); 
  
  copyList(InfixExpression, arithlist); // copies the contents of the linked list to the character array
  
  
  /* CONVERSION FUNCTION BEGINS */
  
  int count; // counter variable
  char word; // the number or operator in the linked list
  char * wordPointer;
  char * rtvPointer;
  char rtv; // return value
  int element; // keeps track of the element in the stack
  
  int answer;
  int precedenceRTV;
  int precedenceWORD;
  
  wordPointer = &word;
  
  
  rtvPointer = &rtv;
  
  element = -1; // initializes element as -1

  push('(', stack, &element, size); // pushes '(' to the stack
	
  InfixExpression[size] = ')'; // adds ')' to the end of the infix array

  count = 0;
  p = arithlist -> head; // reinitializes p to start at the head of the list 
  
  word = InfixExpression[count]; // sets the word equal to the first word in the list
  
  int temp; // the temporary index of the array
  
  while(word != '\0') // runs until the NULL terminating character
  {
	printf("The current word is %c.\n", word);
	answer = isOperator(wordPointer); // determines what the current word is
	
	if(answer == 3 && !(isdigit(word))) 
	{
	  push(word, stack, &element, size);
	}
	
	// checks if the word is a number
	else if(isdigit(word)) 
    {
	  temp = 0;
	  
	  while(isdigit(word))
	  {
		p -> word[temp++] = word;
		word = InfixExpression[++count];
	  }
	  
	  temp++;
	  count--;
	  
	  p = p -> next;
	}
	
	// checks if the word is an operator
	else if(answer == 0 || answer == 1 || answer == 2)
    {  
	  rtv = pop(stack, &element);
	  
	  answer = isOperator(rtvPointer);
	  precedenceRTV = precedence(rtv);
	  precedenceWORD = precedence(word);
	  
	  while(answer != -1 && precedenceRTV >= precedenceWORD)
	  {
		// ISSUE OCCURS HERE
		p -> word[0] = rtv;
		p = p -> next;
		rtv = pop(stack, &element);
		
		answer = isOperator(rtvPointer);
	    precedenceRTV = precedence(rtv);
	    precedenceWORD = precedence(word);
		
	  }
	  
	  push(rtv, stack, &element, size);
	  push(word, stack, &element, size); // pushes the operator onto the stack
	}
	
	// checks if the word is ')'
	else if(answer == 4) 
	{
	  rtv = pop(stack, &element);
	  while(rtv != '(')
	  {
		// ISSUE OCCURS HERE
		p -> word[0] = rtv;
		printf("The item added to the postfix array is: %c\n", *p -> word);
		p = p -> next;
		rtv = pop(stack, &element);
	  }
	}
	
	count++; // increments to the next word in the character array
	word = InfixExpression[count]; // changes to the next word
  }
  
  
  free(InfixExpression);
 
  return true;
}
// copies the linked list into the character array
void copyList(char * array, List * arithlist)
{

  int count; // index of the array
  int index; // index in the linked list character array
  
  ListNode * p; // positon of the current node
  count = 0;
  
  for(p = arithlist -> head; p; p = p -> next) 
  {
    for(index = 0;  p -> word[index]; index++) 
	{
	  if(p -> word[index] != '\n')
        array[count++] = p -> word[index];
    }

    }
  array[count++] = '\0';
  
  return;	
}

// pushes words to the stack
void push(char word, char stack[], int * element, int size)
{
	if(*element >= size - 1)
	{
	  return;
	}
	
	else
	{
	  *element += 1; // increments the value of the element
	  stack[*element] = word; 
	}
	
	return;
}

// returns the item back in the stack
char pop(char stack[], int * element)
{
  char item; // the item being returned

  item = stack[*element];
  *element -= 1;
	
  return item; // returns the item

}

// determines the precedence of the operator being used
int precedence(char operator)
{
  // checks for multiplication operation
  if(operator == '*') 
  {
	return 2;
  }

  // checks for addition or subtraction
  else if(operator == '+' || operator == '-') 
  {
	return 1;
  }
	
  // checks for numbers or paranthesis	
  else 
  {
    return 0;
  }

}

#endif