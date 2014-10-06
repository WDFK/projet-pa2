#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include "pieces.h"

int main(void)
{
  object_list * L = NULL;

  L = lirePiece();
  L = L->next;
  afficherPiece(&(L->data));
  
  rotatePiece(&(L->data));
  afficherPiece(&(L->data));
  
  rotatePiece(&(L->data));
  afficherPiece(&(L->data));

  rotatePiece(&(L->data));
  afficherPiece(&(L->data));
  return 0;
}
