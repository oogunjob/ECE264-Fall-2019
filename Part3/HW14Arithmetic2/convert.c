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
// ...
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
  int check;
  
  
  while(word != '\0') // runs until the NULL terminating character
  {
	answer = isOperator(wordPointer); // determines what the current word is
	
	if((answer == 3 || word == '(') && !(isdigit(word))) 
	{
	  push(word, stack, &element, size);
	  //printf("Push is called! (push(word))\n");
	}
	
	// checks if the word is a number
	else if(isdigit(word)) 
    {
	  check = isdigit(word);
	  
	  if(word != 0)
	    check = 1;
	
	  else
	    check = 0;
			
	  temp = 0;
	  
	  while(check)
	  {
		p -> word[temp++] = word;
		word = InfixExpression[++count];
		
		check = isdigit(word);
		
		if(check != 0)
	      check = 1;
	
	    else
	      check = 0;	  
	  }
	  
	  p -> word[temp++] = '\n';
	  p -> word[temp] = '\0';
	  
	  count--;
	  
	  p = p -> next;
	}
	
	// checks if the word is an operator
	else if((answer == 0 || answer == 1 || answer == 2) && (word != ')'))
    {  
	  rtv = pop(stack, &element);
	  
	  precedenceRTV = precedence(rtv);
	  precedenceWORD = precedence(word);
	  
	  //printf("THE FIRST RTV is: %c\n", rtv);
	  //printf("The FIRST precedence of RTV: %d\n", precedenceRTV);
	  //printf("The FIRST precedence of Word: %d\n", precedenceWORD);
	  
	  
	  answer = isdigit(rtv);
	  
	  if(answer != 0)
	  {
		answer = -1;
	  }
	 
	  else
	  {
		answer = 0;
	  }
	  
	  while(answer == -1 && precedenceRTV >= precedenceWORD)
	  {
		// ISSUE OCCURS HERE
		// THE LOOP WAS NOT ENTERED
		p -> word[0] = rtv;
		//printf("This loop was entered\n");
		//printf("The word added to the linked list is %c\n", *p -> word);
		
		p = p -> next;
		rtv = pop(stack, &element);
		
	    precedenceRTV = precedence(rtv);
		//printf("The precedence of RTV: %d\n", precedenceRTV);
	    //printf("The precedence of Word: %d\n", precedenceWORD);
		
		answer = isdigit(rtv);
		if(answer != 0)
		{
		  answer = -1;
        }
		 
		else
		{
	      answer = 0;
		}
	  }
	  
	  push(rtv, stack, &element, size);
	  //printf("Push is called! (push(rtv))\n");
	  push(word, stack, &element, size); // pushes the operator onto the stack
	  //printf("THIS 208 Push is called! (push(word))\n");
	}
	
	// checks if the word is ')'
	else if(word == ')') 
	{ 
	  rtv = pop(stack, &element);
	  while(rtv != '(')
	  {
		//printf("The current stack is: %s\n", stack);
		p -> word[0] = rtv;
		p -> word[1] = '\n';
		p -> word[2] = '\0';
		
		p = p -> next;
		rtv = pop(stack, &element);
		//printf("The new RTV is: %c\n", rtv);
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
	*element += 1; // increments the value of the element
	//printf("The value of element in push is %d\n", *element);
	stack[*element] = word; 
	
	return;
}

// returns the item back in the stack
char pop(char stack[], int * element)
{
  char item; // the item being returned
  
  //printf("Element is %d\n", *element);
  item = stack[*element];
  *element = *element - 1;
	
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