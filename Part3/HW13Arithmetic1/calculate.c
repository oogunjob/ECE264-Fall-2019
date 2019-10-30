// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// return 2 if the word contains '*'

int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
  {
    char * loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
  }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{	
  if (arithlist == NULL)
    {
      return true;
    }
	
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
	
  // if theres only one number
  // if there are no operators
  
  // go through the list until there is only node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valid, return true
  
  ListNode * p = arithlist -> head; //position of node in the loop (starts from head)
  ListNode * first; // the first number (previous previous)
  ListNode * second; // the second number (previous)
  
  int answer; // the answer after the operation has been applied to the two operands
  int operation; // the operation being carried out
  bool rtv; // return value
  int count; // number of times an operator was found
  
  count = 0; // initializes the amount of times an operator was found
  
  while(p != NULL)
  {
	operation = isOperator(p -> word); //determines if the word is an operation or not
	
	if(operation != -1) // if the word was an operator, finds the two operands and performs calculation based on type of operator
	{
	  count++;
	  
	  if(p == arithlist -> head) // if the first node is an operator, false is returned because it is invalid
		  return false;
	  
	  first = p -> prev -> prev; // finds the first operand
	  second = p -> prev; // finds the second operand
	  
	  // checks if the two operands can be found, if not returns false
	  if(first == NULL || second == NULL) 
	  {
	    return false;
	  }
	  
	  if(operation == 0) // addition
	  {
		answer = atol(first -> word) + atol(second -> word); // finds the sum of the two operands
		sprintf(p -> word, "%d\n", answer); // converts the sum to a character string and puts in place of the operator
	  }
	  
	  else if(operation == 1) // subtraction
	  {
		answer = atol(first -> word) - atol(second -> word); // finds the difference of the two operands
		sprintf(p -> word, "%d\n", answer); // converts the difference to a character string and puts in place of the operator
	  }
	  
	  else if(operation == 2) // multiplication
	  {
		answer = atol(first -> word) * atol(second -> word); // finds the product of the two operands
		sprintf(p -> word, "%d\n", answer); // converts the product to a character string and puts in place of the operator
	  }
		  
	  rtv = deleteNode(arithlist, first); // deletes the first operand
	  rtv = deleteNode(arithlist, second); // deletes the second operand
	}
	
	p = p -> next; // changes the position of the current node to the next node
  }
  
  
  // if more than one node left, return false
  if(arithlist -> head -> next != NULL) // means there are more than one nodes left
  {
	return false; // returns false
  }
  
  
  if(arithlist -> head -> next == NULL) // means there is only one number in the list
  {
	return true; // returns true
  }

  if(count == 0) // if there are no operators found, false is returned
  {
	return false; // returns true
  }
  
  answer = isOperator(arithlist -> head -> word); // determines wheter the head is an operand or not
  
  // if the remaining node is an operator, return false
  if(answer != -1)
  {
	return false;
  }

  // if everything is OK, return true
  return true;
}
#endif
