// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hw17.h"

int main(int argc, char * * argv)
{
  // argv[1]: input file
  if (argc < 2)
    {
      return EXIT_FAILURE;
    }
  List* compressList;
  compressList = malloc(sizeof(List));
  compressList->head = NULL;
  compressList->tail = NULL;

  deleteList(compressList);
  return EXIT_SUCCESS;
}
