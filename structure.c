#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


object_list object_list_cons(object p, object_list L)
{
  object_list new = NULL;

  new = (object_list)malloc(sizeof(struct object_list_cell));
  new->data = p;
  new->next = L;
  return new;
}
