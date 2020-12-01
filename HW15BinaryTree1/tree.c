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

int search(int arr[], int strt, int end, int val) 
{ 
  int i = 0; 
  for (i = strt; i <= end; i++) 
  { 
    if (arr[i] == val) 
	  {
      break; 
	  }
  } 
  return i; 
} 

TreeNode * constructNode(int inOrder[], int postOrder[], int inStrt, int inEnd, int* postInd) 
{
	if (inStrt > inEnd) 
	{
    return NULL; 
	}

	TreeNode * node = malloc(sizeof(TreeNode));
	node -> value = postOrder[*postInd];
	node -> left = NULL;	
 	node -> right = NULL;	
	(*postInd)--; 
	
 	if (inStrt == inEnd) 
	{
    return node; 
	}
	
	int inIndex = search(inOrder, inStrt, inEnd, node->value); 
	node->right = constructNode(inOrder, postOrder, inIndex + 1, inEnd, postInd); 
  node->left = constructNode(inOrder, postOrder, inStrt, inIndex - 1, postInd); 
	return node;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
	int postInd = size - 1; 
	Tree * treeRoot = malloc(sizeof(Tree));
	treeRoot -> root = constructNode(inArray, postArray, 0, size - 1, &postInd);
	return treeRoot; 
}

#endif
