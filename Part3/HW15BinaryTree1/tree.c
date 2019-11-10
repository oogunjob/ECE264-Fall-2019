// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
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

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
TreeNode * buildStructure(int * inArray, int * postArray, int start, int end, int * index);
int nodeSearch(int * array, int start, int value);
TreeNode * newNode(int value);

Tree * buildTree(int * inArray, int * postArray, int size)
{
  int index;
  index = size - 1;
  
  Tree * X = malloc(sizeof(*X));
  
  X -> root = buildStructure(inArray, postArray, 0, size - 1, &index);
  
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
  TreeNode * Node = newNode(postArray[*index]);
  *index = *index - 1;
  
  // if the node doesn't have any children, return the node
  if(start == end)
  {
	return Node;
  }
	
  // finds the correct index
  int nodeIndex = nodeSearch(inArray, start, Node -> value);
  
  Node -> right = buildStructure(inArray, postArray, nodeIndex + 1, end, index);
  Node -> left = buildStructure(inArray, postArray, start, nodeIndex - 1, index);
	
  return Node;
}

int nodeSearch(int * array, int start, int value)
{
  int count; // counter variable for while loop
  count = start;
  
  while(array[count] != value)
  {
    count++;
  }	  

  return count; // returns the index	
}

TreeNode * newNode(int value)
{
  TreeNode * Node = malloc(sizeof(*Node));
  Node -> value = value;
  Node -> right = NULL;
  Node -> left = NULL;
  
  return Node;
}	
#endif
