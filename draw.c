#include "draw.h"
#include "structure.h"
#include "SDL.h"
#include "math.h"
#include "pentomino.h"

void drawPixel(int x, int y, rgb color){
  Uint32 colour;
  colour = SDL_MapRGB(screen->format, color.r, color.g, color.b);
  Uint32 *pixmen32;
  pixmen32 = (Uint32*) screen->pixels + x + y*SCREEN_WIDTH;
  *pixmen32 = colour;
}

void drawLine(int x, int y, int x2, int y2, rgb color){
  if (x != x2 && y != y2)
    return; // on gère pas le cas où la ligne est diago.
  else if (x == x2){
    for (y = y;y <= y2; y++){
      drawPixel(x, y, color);
    }
  }
  else if (y == y2){
    for (x = x; x <= x2; x++){
      drawPixel(x, y, color);
    }
  }
}
