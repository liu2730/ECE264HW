// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
//        1                      '-'
//        2                      '*'
//        3                      '('
//        4                      ')'
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
bool convert(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
  if(isOperator((arithlist->head)->word) != -1)
  {
    return false;
  }

  List* opList;
  opList = malloc(sizeof(List));
  opList->head = NULL;
  opList->tail = NULL;

  List* outList;
  outList = malloc(sizeof(List));
  outList->head = NULL;
  outList->tail = NULL;

  ListNode* temp = arithlist->head;
  ListNode* opTemp = opList->tail;
  int flag = 0;

  while(temp != NULL)
  {
    if(isOperator(temp->word) == -1)
    {
      addNode(outList, temp->word);
    }
    else
    {
      if(opList->head == NULL)
      {
        addNode(opList, temp->word);
        opTemp = opList->tail;
      }
      else
      {
        if(isOperator(temp->word) == 3)
        {
          flag = 1;
        }
        if(isOperator(temp->word) == 4)
        {
          flag = 0;
          addNode(outList, opTemp->word);
          deleteNode(opList, opTemp);
          opTemp = opList->tail;
          deleteNode(opList, opTemp);
          opTemp = opList->tail;
        }
        if(((isOperator(temp->word) > isOperator(opTemp->word) && (isOperator(temp->word) != 1))|| (flag == 1))  && (isOperator(temp->word) != 4))
        {
          addNode(opList, temp->word);
          opTemp = opList->tail;
        } 
        if(((isOperator(temp->word) < isOperator(opTemp->word)) && (isOperator(temp->word) != 4)) || (isOperator(temp->word) == 1 && isOperator(opTemp->word) == 0))
        {
          addNode(outList, opTemp->word);
          deleteNode(opList, opTemp);
          addNode(outList, temp->word);
          opTemp = opList->tail;
        }
      }
    }
    temp = temp->next;
  }

  while(opTemp != NULL)
  {
    addNode(outList, opTemp->word);
    deleteNode(opList, opTemp);
    opTemp = opList->tail;
  }

  ListNode* temp2 = outList->tail;
  temp = outList->head;
  outList->head = arithlist->head;
  outList->tail = arithlist->tail;
  arithlist->head = temp;
  arithlist->tail = temp2;
  deleteList(outList);
  deleteList(opList);
  return true;
}
#endif
