// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  for (int i = 0; i < n; i++)
  {
    arr[i] = k + 1;
  }
  int counter = 0;
  int j = 1; 

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  while (counter < (n - 1))
  {
    for (int i = 0; i < n; i++)
    {
      if (arr[i] != 0)
      {
        arr[i] = j;
        j++;
        if (j > k)
        {
          arr[i] = 0;
          counter++;
          j = 1;
          fprintf(stdout, "%d\n", i);
        }
      }
    }  
  }

  // print the last one
  
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      fprintf(stdout, "%d\n", i);
    }
  }

  // release the memory of the array
  free (arr);
}
#endif
