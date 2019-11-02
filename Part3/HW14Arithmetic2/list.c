// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  FILE * file; // variable that holds the file
  char * line = malloc(sizeof(* line) * WORDLENGTH); // space for the lines in the file
  file = fopen(filename, "r"); // opens the file

  // checks if the list and file or NULL
  if(arithlist == NULL || file == NULL)
  {
	return false; // returns false if the list or file is NULL
  }
  
  // checks the the line is shorter than word length
  while(fgets(line, WORDLENGTH, file) != NULL)
  {
	if(line[strlen(line) - 1] != '\n')
	{
	  free(line); // frees memory allocation of the line
	  free(arithlist); // frees memory allocation of the list
	  fclose(file); // closes the file
	  return false;
	}
	
	addNode(arithlist, line); // adds new nodes to the list
  }
  
  free(line); // frees the allocated space for the line
  fclose(file); // closes the file
  
  return true; 
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
  // if arithlist is NULL, returns to calling function
  if(arithlist == NULL)
  {
    return;
  }	  
  
   ListNode * current = arithlist -> head; // sets the current node deleted as the head
   ListNode * resume; // place holder node for where deletion will resume from
  
   while (current != NULL)  // runs through entire list and frees each current node
   { 
     resume = current -> next; 
     free(current); 
     current = resume; 
   } 
  
   arithlist -> head = NULL; // assings the head as NULL
   free(arithlist); // frees the list
  
   return;
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  if(arithlist == NULL) //if arithlist is NULL, do nothing
  {
	return;
  }
	
  ListNode * newNode = malloc(sizeof(ListNode)); // creates memory for a new node
  
  strcpy(newNode -> word, word); //copies the passed word into the new node
  
  newNode -> next = NULL; // assigns the next node after the created node as null
  
  if(arithlist -> head == NULL) // if the list is empty, head and tail are assigned as the newNode
  {
	arithlist -> head = newNode; // heads begins from the new node
	arithlist -> tail = newNode; // head ends at the new node
	arithlist -> head -> prev = NULL; // there is no node before the head
  }
  
  else
  {
	arithlist -> tail -> next = newNode; // the node after the tail is the new node
	newNode -> prev = arithlist -> tail; // the node before the new node is the tail
	newNode -> next = NULL; // the node after the new node is NULL
	arithlist -> tail = newNode; // the new node is now the tail, end of the list
  }

}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  /* If node to be deleted is head node */
    if (arithlist -> head == ln) 
        arithlist -> head = ln -> next; 
  
    /* Change next only if node to be deleted is NOT the last node */
    if (ln -> next != NULL) 
        ln-> next -> prev = ln -> prev; 
  
    /* Change prev only if node to be deleted is NOT the first node */
    if (ln -> prev != NULL) 
        ln -> prev-> next = ln -> next; 
  
    /* Finally, free the memory occupied by del*/
    free(ln); 
	
    return true;
}
#endif

