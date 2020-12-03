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


void addNode(List * arithlist, char * word)
{
  if(arithlist == NULL)
  {
    return;
  }
  ListNode* temp = malloc(sizeof(ListNode));
  strcpy(temp->word, word);
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
  while((temp != NULL) && (temp->word != ln->word))
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

#ifdef TEST_READLIST
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
  char str[WORDLENGTH];

  FILE * fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return false;
  }
  if(arithlist == NULL)
  {
    return false;
  }

  int elemRead = 0;

  while(elemRead < numElem(filename))
  {
    elemRead = elemRead + fread(str, sizeof(char), 1, fp);
    addNode(arithlist, str);
  }
  

  fclose(fp);
  return true;
}
#endif


#ifdef TEST_BUILDTREE

#endif
