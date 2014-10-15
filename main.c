#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "structure.h"
#include "pentomino.h"
#include "pieces.h"


int main(void)
{
  object_list * L;
  L = lirePiece(L);
  init(L);
  main_loop(L);
  return 0;
}
