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

  while((fgets(str, WORDLENGTH, fp)) != NULL)
  {
     if((strchr(str, '\0') == NULL) || (strchr(str, '\n') == NULL))
    {
      deleteList(arithlist);
      fclose(fp);
      return false;
    }
    addNode(arithlist, str);
  }

  fclose(fp);
  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
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

