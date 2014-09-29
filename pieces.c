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

object_list lirePiece(void)
{
  
  FILE * ptr_file;
  
  ptr_file = fopen("source.txt", "r");
  if (ptr_file == NULL)
    {
      perror ("Error opening file");
      return;
    }
  int c, i, j;
  object_list L = NULL;
  object tmp;
  
  do {
  initTab(&tmp);
      i = 0;
      j = 0;
      c = fgetc(ptr_file);
      if (c == '#')
	{
	  tmp.tab[i][j] = 1;
	  ++j;
	}
      else if (c == '\n')
	{
	  ++i;
	  j = 0;
	  if (fgetc(ptr_file) == '\n')
	    {
	      object_list_cons(tmp, L);
	    }
	  else
	    fseek ( ptr_file , -1 , SEEK_CUR );
	}
      else if (c == ' ')
	{
	  ++j;
	}
      }while (c != EOF);
    
    return L;
}

void afficherPiece(object_list L)
{
  int i, j;
  for(i=0; i<5; i++)
    {
      for(j=0; j<5; j++)
	{
	  printf("%d", L->data->tab[i][j]);
	}
      printf("\n");
    }
}
