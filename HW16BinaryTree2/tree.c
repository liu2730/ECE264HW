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

#ifdef TEST_PRINTPATH
int max(int num1, int num2)
{
  return(num1 > num2) ? num1 : num2;
}

bool hasPath(TreeNode* root, int path[], int val, int* ind)
{
  if(root == NULL)
  {
    return false;
  }

  path[*ind] = root->value;
  (*ind)++;

  if(root->value == val)
  {
    return true;
  }

  if(hasPath(root->left, path, val, ind) || hasPath(root->right, path, val, ind))
  {
    return true;
  }

  (*ind)--;
  path[*ind] = -1;
  return false;
}

int treeHeight(TreeNode* root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

void printPath(Tree * tr, int val)
{

  int index = 0;
  int size = 0;
  size = treeHeight(tr->root);
  
  int* pathArr = malloc(sizeof(int) * size);


  for(int i=0; i<size; i++)
  {
    pathArr[i] = - 1;
  }

  if (hasPath(tr->root, pathArr, val, &index))
  {
    for(index = size - 1; index >= 0; index--)
    {
      if(pathArr[index] != -1)
      {
        printf("%d\n", pathArr[index]);
      }
    }
  }

  free(pathArr);
}
#endif
