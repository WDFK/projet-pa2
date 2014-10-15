#include <stdio.h>
#include <stdlib.h>
#include "pentomino.h"
#include "pieces.h"
#include "structure.h"


object_list *  object_list_cons(object p, object_list * L)
{
  int i, j;
  object_list * new = NULL;
  new = (object_list*)malloc(sizeof(object_list));
  for (i = 0; i < 5; i++){
    for(j=0; j < 5; j++){
      new->data = p;
    }
  }
  printf("new : %p\n", new);
  afficherPiece(&p);
  new->next = L;
  return new;
}
