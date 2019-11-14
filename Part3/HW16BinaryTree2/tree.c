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
bool countPath(TreeNode * node, int val, int * lcv); // the count of nodes in the path
bool hasPath(TreeNode * node, int val, int * arr, int * lcv); // the addition of nodes in the path

bool countPath(TreeNode * node, int val, int * lcv)
{
  if(node == NULL)
  {
	return false; // returns false if the node doesn't exist
  }
  
  *lcv += 1; // adds to the size of the array
  
  if(node -> value == val)
  {
	return true; // if the node is equal to the desired value, returns value
  }
  
  if(countPath(node -> left, val, lcv) || countPath(node -> right, val, lcv))
  {
	return true; // checks that the path is possible on either side
  }

  return false;
}

bool hasPath(TreeNode * node, int val, int * arr, int * lcv)
{
  if(node == NULL)
  {
	return false; // if the node is equal to the desired value, returns value
  }
  
  arr[*lcv] = node -> value; // adds the node to the array
  *lcv += 1; // incremenets to the size of the array
  
  if(node -> value == val)
  {
	return true; // if the node is equal to the desired value, returns value
  }
  
  if(hasPath(node -> left, val, arr, lcv) || hasPath(node -> right, val, arr, lcv))
  {
	return true; // checks that the path is possible on either side
  }

  return false;
}

void printPath(Tree * tr, int val)
{
  bool rtv; // return value
  int count; // the number of elements in the array
  int index; // the index of the element being printed
  int * array; // the array that will store elements in the array
  
  count = 0; // count of the number of nodes in the path
  index = 0; // the index of the node added to the array

  rtv = countPath(tr -> root, val, &count); // counts how many nodes are in the path
  
  array = malloc(sizeof(*array) * count); // creates space for the array
  
  rtv = hasPath(tr -> root, val, array, &index); // adds the nodes to the array
  
  for(index = count - 1; index >= 0; index--)
  {
	printf("%d\n", array[index]); // prints the value in the tree
  }
  
  free(array);
  
  return;
}
#endif
