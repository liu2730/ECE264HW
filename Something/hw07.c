// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
  FILE * fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return -1;
  }

  int numInt = 0;
  int val;
  while (fscanf(fp, "%d", &val) == 1)
  {
    numInt = numInt + 1;
  }
  fclose(fp);

  // remember to fclose if fopen succeeds
  return numInt;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  FILE * fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return false;
  }

  int val;
  int numInt = 0;
  while (fscanf(fp, "%d", &val) == 1)
  {
    intArr[numInt] = val;
    numInt++;
  }
  
  if (numInt != size)
  {
    return false;
  }

  fclose(fp);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.

  const int * ptr1 = (const int *) p1;
  const int * ptr2 = (const int *) p2;
  int val1 = *ptr1;
  int val2 = *ptr2;
  if(val1 < val2)
  {
    return -1;
  }
  else if(val1 > val2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true

  FILE * fp = fopen(filename, "w");
  if (fp == NULL)
  {
    return false;
  }
  for(int i = 0; i < size; i++)
  { 
    fprintf(fp, "%d\n", intArr[i]);
  }
  
  fclose(fp);
  return true;
}
#endif
