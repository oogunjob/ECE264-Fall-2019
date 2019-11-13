// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
TreeNode * buildStructure(int * inArray, int * postArray, int start, int end, int * index);
int nodeSearch(int * array, int start, int value);
TreeNode * newNode(int value);

Tree * buildTree(int * inArray, int * postArray, int size)
{
  int index; // index in the array
  index = size - 1;
  
  Tree * X = newTree(); // creates a new tree
  
  X -> root = buildStructure(inArray, postArray, 0, size - 1, &index); // returns the index 
  
  return X;
}  

TreeNode * buildStructure(int * inArray, int * postArray, int start, int end, int * index)
{
  // starting test case, for if start is greater than the end
  if(start > end)
  {
	return NULL;
  }
  
  // creates new node using index
  TreeNode * Node = newNode(postArray[*index]); // creates the new node
  *index = *index - 1; // updates the index
  
  // if the node doesn't have any children, return the node
  if(start == end)
  {
	return Node;
  }
	
  // finds the correct index
  int nodeIndex = nodeSearch(inArray, start, Node -> value); // finds the index of the node
  
  Node -> right = buildStructure(inArray, postArray, nodeIndex + 1, end, index); // updates the right of the node
  Node -> left = buildStructure(inArray, postArray, start, nodeIndex - 1, index); // updates the left of the node
	
  return Node; // returns the node
}

int nodeSearch(int * array, int start, int value)
{
  int count; // counter variable for while loop
  count = start;
  
  // finds index that corresponds to the value
  while(array[count] != value)
  {
    count++; // updates count
  }	  

  return count; // returns the index	
}

TreeNode * newNode(int value)
{
  TreeNode * Node = malloc(sizeof(*Node)); // creates space for the new node
  Node -> value = value; // updates the value of the node
  Node -> right = NULL;
  Node -> left = NULL;
  
  return Node; // returns the new node
}	
#endif

#ifdef TEST_PRINTPATH
bool hasPath(TreeNode * node, int val)
{
  if(node == NULL)
  {
	return false;
  }
  
  printf("%d\n", node -> value);
  
  if(node -> value == val)
  {
	return true;
  }
  
  if(hasPath(node -> left, val) || hasPath(node -> right, val))
  {
	return true;
  }

  return false;

}

void printPath(Tree * tr, int val)
{
  bool rtv;
  rtv = hasPath(tr -> root, val);
  
  return;
 
}
#endif























