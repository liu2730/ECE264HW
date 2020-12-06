// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hw17.h"

int main (int argc, char * * argv)
{
  // argv[1]: input file
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }

  List * compressList;
  compressList = malloc(sizeof(List));
  compressList->head = NULL;
  compressList->tail = NULL;

  if (readList(argv[1], compressList) == false)
  {
    return EXIT_FAILURE;
  }

  Tree* compressTree = newTree();
  compressTree->root = (compressList->head)->tnode;

  int maxLevel = 0;
  if(encodeTree(compressTree->root, 1, &maxLevel) == false)
  {
    return EXIT_FAILURE;
  }

  int numElem = totalPrint(compressTree->root);
  int index = 0;
  char * chWant = malloc(sizeof(char) * numElem);
  chBook(compressTree->root, chWant, &index);

  index = 0;
  //for(index; index < numElem; index++)
  {
    printf("%c %d ", chWant[index], chWant[index]);
    printPath(compressTree, chWant[index]);
    printf("\n");
  }
  
  freeTree(compressTree);
  deleteList(compressList);
  free(chWant);

  return EXIT_SUCCESS;
}
