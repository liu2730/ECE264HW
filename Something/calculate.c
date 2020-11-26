// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
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
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
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
  // go through the list until there is only node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valud, return true
  ListNode* temp = arithlist->head;
  ListNode* operand1 = NULL;
  ListNode* operand2 = NULL;
  int opValue = 0;
  int op1 = 0;
  int op2 = 0;
  int operators = 0;
  while(temp->next != NULL)
  {
    if (isOperator(temp->word) != -1)
    {
      operators++;
    }
    temp = temp->next;
  }
  if((operators == 0) && (temp->prev != NULL))
  {
    return false;
  }

  temp = arithlist->head;

  while(temp->next != NULL)
  {
    while((isOperator(temp->word) == -1) && (temp->next != NULL))
    {
      temp = temp->next;
    }
    operand2 = temp->prev;
    operand1 = operand2->prev;

    if((operand1 == NULL) || (operand2 == NULL))
    {
      return false;
    }

    sscanf(operand1->word, "%d", &op1);
    sscanf(operand2->word, "%d", &op2);
    if(isOperator(temp->word) == 0)
    {
      opValue = op1 + op2;
      sprintf(operand1->word, "%d\n", opValue);
      deleteNode(arithlist, temp);
      deleteNode(arithlist, operand2);
      temp = operand1;
      operand2 = operand1;
    }
    if(isOperator(temp->word) == 1)
    {
      opValue = op1 - op2;
      sprintf(operand1->word, "%d\n", opValue);
      deleteNode(arithlist, temp);
      deleteNode(arithlist, operand2);
      temp = operand1;
      operand2 = operand1;
    }
    if(isOperator(temp->word) == 2)
    {
      opValue = op1 * op2;
      sprintf(operand1->word, "%d\n", opValue);
      deleteNode(arithlist, temp);
      deleteNode(arithlist, operand2);
      temp = operand1;
      operand2 = operand1;
    }

  }

  if(((arithlist->head)->next != NULL) && ((arithlist->head)->prev != NULL))
  {
    return false;
  }
  if(isOperator((arithlist->head)->word) != -1)
  {
    return false;
  }
  
  // if more than one node left, return false

  // if the remaining node is an operator, return false

  // if everything is OK, return true
  return true;
}
#endif
