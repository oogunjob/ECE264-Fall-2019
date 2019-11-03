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
void copyList(char * characterList, List * arithlist);
void push(char word, char * stack, int * element, int size);
char pop(char * stack, int * element);
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
  p = arithlist -> head;
  
  // counts the number of nodes in the list
  while(p != NULL)
  {
	size++; // adds to the size
	p = p -> next; // changes to the next position
  }
  
  char * InfixExpression; // creates a character array that will store the words in the linked list
  InfixExpression = malloc(sizeof(char) * (size + 1)); // creates space for the character array
  
  copyList(InfixExpression, arithlist); // copies the contents of the linked list to the character array
  
  
  /* CONVERSION FUNCTION BEGINS */
  
  int count; // counter variable
  char word; // the number or operator in the linked list
  char * wordPointer;
  char * rtvPointer;
  char rtv; // return value
  int element; // keeps track of the element in the stack
  char * stack; // the stack that hold operations
  
  int answer;
  int precedenceRTV;
  int precedenceWORD;
  
  wordPointer = &word;
  rtvPointer = &rtv;
  
  stack = malloc(sizeof(char) * (size + 1)); // creates space to hold the stack
  
  element = -1; // initializes element as -1

  push('(', stack, &element, size); // pushes '(' to the stack
	
  InfixExpression[size] = ')'; // adds ')' to the end of the infix array

  count = 0;
  p = arithlist -> head; // reinitializes p to start at the head of the list 
	
  word = InfixExpression[count]; // sets the word equal to the first word in the list
  // CHECK THAT THE FIRST WORD ISN'T AN OPERATOR
  
  while(word != '\0') // runs until the NULL terminating character
  {
	// checks if the word is '('
	answer = isOperator(wordPointer);
	if(answer == 3) 
	{
	  push(word, stack, &element, size);
	}
	
	// checks if the word is a number
	else if(answer == -1) 
    {
	  strcpy(p -> word, wordPointer);
	  p = p -> next;
	}
	
	// checks if the word is an operator
	else if(answer == 0 || answer == 1 || answer == 2)
    {
	  rtv = pop(stack, &element);
	  
	  answer = isOperator(rtvPointer);
	  precedenceRTV = precedence(rtv);
	  precedenceWORD = precedence(word);
	  
	  while(answer != -1 && precedence(rtv) >= precedence(word))
	  {
	    strcpy(p -> word, rtvPointer);
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
	else if(word == ')') 
	{
	  rtv = pop(stack, &element);
	  while(rtv != '(')
	  {
		strcpy(p -> word, rtvPointer);
		p = p -> next;
		rtv = pop(stack, &element);
	  }
	}
	
	count++; // increments to the next word in the character array
	word = InfixExpression[count]; // changes to the next word
  }
  
  free(InfixExpression);
  free(p);
 
 
  return true;
}
// copies the linked list into the character array
void copyList(char * characterList, List * arithlist)
{
  int index; // the index of the array
  index = 0; 
  
  ListNode * current = arithlist -> head;
  
  //copies the contents of the linked list into the array
  while(current -> next != NULL)
  {
	characterList[index] = current -> word;
	current = current -> next;
	index++;  
  }
  
  return;	
}

// pushes words to the stack
void push(char word, char * stack, int * element, int size)
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
char pop(char * stack, int * element)
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