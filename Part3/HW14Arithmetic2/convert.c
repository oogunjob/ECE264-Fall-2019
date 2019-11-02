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
  count = 0;
  
  ListNode * p; // the current position in the list
  p = arithlist -> head;
  
  // counts the number of nodes in the list
  while(p != NULL)
  {
	size++;
	p = p -> next;  
  }
  
  char * InfixExpression; // creates a character array that will store the words in the linked list
  infixExpression = malloc(sizeof(char) * size); // creates space for the character array
  
  copyList(infixExpression, arithlist); // copies the contents of the linked list to the character array
  
  
  /* CONVERSION FUNCTION BEGINS */
  
  int i; // counter variable
  int j; // counter variable
  
  char word; // the number or operator in the linked list
  char rtv; // return value
  int element; // keeps track of the element in the stack
  char * stack; // the stack that hold operations * NEED TO MALLOC THE SIZE
  
  stack = malloc(sizeof(char) * (size + 1)); // creates space to hold the stack
  
  element = -1; // initializes element as -1

  push('(', stack, &element, size); // pushes '(' to the stack
	
  infixExpression[size - 1] = ")"; // adds ')' to the end of the infix array

  i = 0;
  p = arithlist -> head; // reinitializes p to start at the head of the list 
	
  word = infixExpression[i]; // sets the word equal to the first word in the list
  // CHECK THAT THE FIRST WORD ISN'T AN OPERATOR
  
  while(word != '\0') // runs until the NULL terminating character
  {
	// checks if the word is '('
	if(isOperator(word) == 3) 
	{
	  push(word, &element, stack);
	}
	
	// checks if the word is a number
	else if(isOperator(word) == -1) 
    {
	  p -> word = word;
	  p = p -> next;
	}
	
	// checks if the word is an operator
	else if(isOperator(word) == 0 || isOperator(word) == 1 || isOperator(word) == 2)
    {
	  rtv = pop(stack, &element);
	  while(is_operator(rtv) != -1 && precedence(rtv) >= precedence(word))
	  {
				
				
				
				
				
				
				
				
				
				
			// USE THE LINKED LIST FOR THIS PART
			// JUST CHANGE THE POSITION
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have
			oppped one extra word
			for which condition fails and loop terminates, so that one*/

			push(word);                 /* push current oprerator symbol onto stack */
		}
		
		
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
void push(char word, char * stack, int * element, size)
{
	if(*element >= size - 1)
	{
	  return false;
	}
	
	else
	{
	  *element += 1;
	  stack[element] = word;
	}
	
	return;
}

// returns the item back in the stack
char pop(char * stack, int * element)
{
  char item; // the item being returned

  item = stack[*element];
  *element--;
	
  return item; // returns the item

}

// determines the precedence of the operator being used
int precedence(char operator)
{
  if(operator == '*') // checks for multiplication operation
  {
	return 2;
  }
	
  else if(operator == '+' || operator == '-') // checks for addition or subtraction
  {
	return 1;
  }
	
  else 
  {
    return 0;
  }

}



#endif