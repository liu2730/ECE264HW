// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw17.h"

#ifdef TEST_MODIFYTREE
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
#endif

#ifdef TEST_MODIFYLIST
void deleteList(List * arithlist)
{
  if(arithlist == NULL)
  {
    return;
  }
  ListNode* h = arithlist->head;
  ListNode * temp = NULL;
  while(h != NULL)
  {
    temp = h->next;
    free(h);
    h = temp;
  }
  free(arithlist);
  return;
}

void addNode(List * arithlist, TreeNode * node)
{
  if(arithlist == NULL)
  {
    return;
  }

  ListNode* temp = malloc(sizeof(ListNode));
  temp->tnode = node;
  temp->next = NULL;
  temp->prev = NULL;

  if(arithlist->head == NULL)
  {
    arithlist->head = temp;
    arithlist->tail = temp;
    return;
  }
  temp->prev = arithlist->tail;
  (arithlist->tail)->next = temp;
  arithlist->tail = temp;
  return;
}

bool deleteNode(List * arithlist, ListNode * ln)
{
  if(arithlist == NULL)
  {
    return false;
  }
  if((arithlist->head == NULL) || (arithlist->tail == NULL))
  {
    return false;
  }

  ListNode* temp = arithlist->head;
  while((temp != NULL) && ((temp->tnode)->value != (ln->tnode)->value))
  {
    temp = temp->next;
  }
  if(temp == NULL)
  {
    return false;
  }

  if(temp == (arithlist->head))
  {
    ListNode* temp2 = (arithlist->head)->next;
    if (temp2 != NULL)
    {
      temp2->prev = NULL;
    }
    free(arithlist->head);
    arithlist->head = temp2;
    if(arithlist->head == NULL)
    {
      arithlist->tail = NULL;
    }
    return true;
  }

  if(temp == (arithlist->tail))
  {
    ListNode* temp2 = (arithlist->tail)->prev;
    if(temp2 != NULL)
    {
      temp2->next = NULL;
    }
    free(arithlist->tail);
    arithlist->tail = temp2;
    if(arithlist->tail == NULL)
    {
      arithlist->head = NULL;
    }
    return true;
  }

  (temp->next)->prev = temp->prev;
  (temp->prev)->next = temp->next;
  free(temp);

  return true;
}
#endif

#ifdef TEST_BUILDTREE
TreeNode* newTnode(char word)
{
  TreeNode * node = malloc(sizeof(TreeNode));
	node -> value = word;
	node -> left = NULL;	
 	node -> right = NULL;	
  node -> code = 1;
  return node;
}

int numElem(char* filename)
{
  FILE * fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return -1;
  }

  int numElements = 0;
  fseek(fp, 0, SEEK_END);
  numElements = ftell(fp)/sizeof(char);

  fclose(fp);
  return numElements;
}

bool readList(char * filename, List * arithlist)
{

  FILE * fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return false;
  }
  if(arithlist == NULL)
  {
    return false;
  }

  int numEl = numElem(filename);
  char* str = malloc(sizeof(char) * numEl);

  if(numEl != fread(str, sizeof(char), numElem(filename), fp))
  {
    return false;
  }

  int i = 0;
  
  while(i < numEl)
  {
    if(str[i] == '1')
    {
      i++;
      addNode(arithlist, newTnode(str[i]));
    }
    if(str[i] == '0')
    {
      addNode(arithlist, newTnode(str[i]));
    }
    i++;
  }
  ListNode* temp = arithlist->head;
  ListNode* combine1 = NULL;
  ListNode* combine2 = NULL;
  TreeNode* hold = NULL;
  while(temp->next != NULL)
  {
    while((temp->tnode)->value != '0')
    {
      temp = temp->next;
    }
    combine2 = temp->prev;
    combine1 = combine2->prev;
    hold = combine2->tnode;
    combine1->tnode = newTnode('\0');
    (combine1->tnode)->right = combine2->tnode;
    (combine1->tnode)->left = hold;
    deleteNode(arithlist, combine2);
    deleteNode(arithlist, temp);
    temp = combine1;
    combine2 = combine1;
  }

  if(((arithlist->head)->next != NULL) && ((arithlist->head)->prev != NULL))
  {
    return false;
  }
  if(((arithlist->head)->tnode)->value != '0')
  {
    return false;
  }

  fclose(fp);
  free(str);
  return true;
}

bool encodeTree(TreeNode* root, int level, int* maxlevel)
{
  if(root == NULL)
  {
    return false;
  }

  if(*maxlevel < level)
  {
    root->code = 0;
    *maxlevel = level;
  }

  encodeTree(root->left, level + 1, maxlevel);
  encodeTree(root->right, level + 1, maxlevel);

  return true;
}

int totalPrint(TreeNode* tnode)
{
  if(tnode == NULL)
  {
    return 0;
  }
  if((tnode->left == NULL) && (tnode->right == NULL))
  {
    return 1;
  }
  else
  {
    return totalPrint(tnode->left) + totalPrint(tnode->right);
  }
}

void chBook(TreeNode* tnode, char wantArr[], int * index)
{
  if(tnode == NULL)
  {
    return;
  }
  
  if (tnode->left == NULL && tnode->right == NULL) 
  { 
    wantArr[*index] = tnode->value;
    (*index)++;
  } 
  
  if (tnode->left != NULL)
  {
    chBook(tnode->left, wantArr, index);
  } 

  if (tnode->right != NULL) 
  {
    chBook(tnode->right, wantArr, index);
  }

}
#endif

#ifdef TEST_PRINTPATH
int max(int num1, int num2)
{
  return(num1 > num2) ? num1 : num2;
}

bool hasPath(TreeNode* root, int path[], char want, int* ind)
{
  if(root == NULL)
  {
    return false;
  }

  path[*ind] = root->code;
  (*ind)++;

  if(root->value == want)
  {
    return true;
  }

  if(hasPath(root->left, path, want, ind) || hasPath(root->right, path, want, ind))
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

void printPath(Tree * tr, char val)
{

  int index = 0;
  int size = 0;
  size = treeHeight(tr->root);
  
  int* pathArr = malloc(sizeof(int) * size);


  for(int i=0; i<size; i++)
  {
    pathArr[i] = -1;
  }

  if (hasPath(tr->root, pathArr, val, &index))
  {
    for(index = size - 1; index >= 0; index--)
    {
      if(pathArr[index] != -1)
      {
        printf("%d", pathArr[index]);
      }
    }
  }

  free(pathArr);
}
#endif

