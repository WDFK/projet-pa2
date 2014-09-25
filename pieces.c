#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "pieces.h"

void initTab(object * p)
{
  int i, j;
  for (i = 0; i < 4; ++i)
    {
      for (j = 0; j < 4; ++j)
	{
	  p->tab[i][j] = 0;
	}
    }
}

void lirePiece(object * p)
{
  
  FILE *ptr_file;
  
  ptr_file = fopen("source.txt", "rt");
  char line[5];
  object_list L = NULL;
  object tmp;

  while(fgets(line, 6, ptr_file) != NULL)
    {
      
    }
  
}
