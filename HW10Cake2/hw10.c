// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

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
ListNode * newNode(int v)
{
  ListNode * p = (ListNode*) malloc(sizeof(ListNode));
  p->value = v;
  p->next = NULL;
  return p;
}

ListNode * createList(int valn)
{
  ListNode* head = newNode(0);
  ListNode* temp = head;
  ListNode* n;
  for (int i = 1; i < valn; i++)
  {
    n = newNode(i);
    temp->next = n;
    temp = n; 
  }
  
  return head;
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
int getCount(ListNode * head)
{
  if (head == NULL)
  {
    return 0;
  }
  return 1 + getCount(head->next);
}

void eliminate(ListNode * head, int valk)
{
  int counter = 0;
  int n = getCount(head);
  int j = 0;
  ListNode * temp;
  ListNode * todelete;

  while (counter < (n - 1))
  {
    temp = head;
    while(temp != NULL)
    {
      if(temp->value != 0)
      {
        temp->value = j;
        j++;
        if (j > valk)
        {
          temp -> value = 0;
          counter++;
          j = 1;
        }
      }
      #ifdef DEBUG
      // this #ifdef ... #endif should be inside the condition *BEFORE* a
      // node' value is printed and it is deleted
      todelete = temp;
      printListNode (todelete); 
      #endif
      temp = temp->next;
    }
  }

  temp = head;
  while(temp != NULL)
  {
    if(temp->value != 0)
    {
      fprintf(stdout, "%d\n", temp->value);
    }
    temp = temp->next;
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
bool nodeSearch(ListNode * head, int x)
{
  ListNode* current = head;
  while (current != NULL)
  {
    if (current->value == x)
    {
      return true;
    }
    current = current->next;
  }
  return false;
}

ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (todelete == NULL)
  {
    return head;
  }
  if (nodeSearch(head, todelete->value) == false)
  {
    return head;
  }
  if (head->value == todelete->value)
  {
    head = head->next;
    return head;
  }
  free(todelete);
  return head;
}
#endif


