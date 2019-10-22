// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
  int count; // keeps track of loop and value for current node
  
  ListNode * head = NULL; // beginning of the linked list
  ListNode * temp; // temporary node  
  
  for(count = valn - 1; count >= 0; count--)
  {
	// creates temporary nodes //
	ListNode * tempNode = malloc(sizeof(ListNode));
	tempNode -> value = count;
	tempNode -> next = NULL;
	// creation of node completed
	
	temp = tempNode;
	temp -> next = head;
	head = temp;
  }
  
  return head; // returns the head of the list

}
#endif

#ifdef TEST_ELIMINATE

// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  ListNode * p; // the current position of the last player deleted
  ListNode * resume; // the node to continue resuming the game from
  int count; // used to count the amount of nodes in the list
  count = 0;
  
  p = head; // sets the starting position to the head of the list
  
  while(head != NULL)
  {
	if(count2 % valk == 0) // checks if count is an iteration of valk
	{
	  if(p != NULL)
	  {
		resume = p -> next; // keeps a place holder of where the next person starts
		
	    #ifdef DEBUG
        // this #ifdef ... #endif should be inside the condition *BEFORE* a
        // node' value is printed and it is deleted
        ListNode * todelete = p;
        printListNode (todelete); 
        #endif
		
		deleteNode(head, p); // deletes the node from the list
		p = resume; // sets the position back to the player to start from 
		count = 1;
	  }
	}
	else if(p != NULL)
		count += 1;
  }
	     
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
	
	
	
	
	
	
	
  free(todelete);
  
	
	
	
}
#endif


