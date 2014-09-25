#include "SDL.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32


int main ( int argc, char *argv[] )
{
  SDL_Surface *ecran = NULL, *rectangle = NULL, *temp, *sprite, *grass;
  SDL_Rect rcSprite, rcGrass, position;
  SDL_Event event;
  Uint8 *keystate;
  
  int colorkey, gameover;


  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("SDL Move", "SDL Move");

  /* create window */
  ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE);

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
 
  position.x = 0;
  position.y = 0;

  SDL_FillRect (rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_BlitSurface(rectangle, NULL, ecran, &position);
  SDL_Flip(ecran);

  pause();

  SDL_FreeSurface(rectangle);
  SDL_Quit(); 
  return 0;
}
