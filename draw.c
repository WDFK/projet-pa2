#include "draw.h"
#include "structure.h"
#include "SDL.h"
#include "init.h"
#include "math.h"

void drawPlayer(obj * player){
  int i, j;
  for (i = 0; i < 4; ++i){
    for (j = 0; j < 8; ++j){
      drawPixel(player->renderPos.x+i, player->renderPos.y+j);
    }
  }
}

void drawPixel(int x, int y){
  Uint32 colour;
  colour = SDL_MapRGB(screen->format, 255, 255, 255);
  Uint32 *pixmen32;
  pixmen32 = (Uint32*) screen->pixels + x + y*SCREEN_WIDTH;
  *pixmen32 = colour;
}

void drawGround(void){
  int i, j;
  for (i=0; i < SCREEN_WIDTH; ++i){
    for(j=0; j < SCREEN_HEIGHT; ++j){
      if((pow(i - 320,2) + pow(j - 480, 2) > pow(150,2)-100) && pow(i - 320,2) + pow(j - 480,2) < pow(150,2)+100){
	drawPixel(i, j);
      }
    }
  }
}
