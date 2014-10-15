#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include "pieces.h"
#include "SDL.h"
#include "pentomino.h"

int main(void)
{
  L = lirePiece();
  LL = &L;
  init();
  main_loop();
  return 0;
}
