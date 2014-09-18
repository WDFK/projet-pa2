#include "pieces.h"
#include "structure.h"

void main()
{
  pieces_ptr * Pieces;
  
  remiseAZero(Pieces);
  printf("%c",Pieces->tab0[4][4]);
}
