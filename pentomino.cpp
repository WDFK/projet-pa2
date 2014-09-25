#include "SDL.h"
#define SCREEN_WIDTH  1300
#define SCREEN_HEIGHT 800
#define BACKGROUND_SPRITE_PATH "background.bmp"


int main(int argc, char* argv[])
{

  SDL_Surface *sprite, *screen, *temp, *background;
  SDL_Rect rcBackground;
  
  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);
  // TTF_Init();
  
  /* set the title bar */
  SDL_WM_SetCaption("Pentomino", "Pentomino");
  
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  
  /* set keyboard repeat */
  
  SDL_EnableKeyRepeat(70, 70);

	/* load sprite */
  //	temp   = SDL_LoadBMP(PLAYER_SPRITE_PATH);
  //	sprite = SDL_DisplayFormat(temp);
  //	SDL_FreeSurface(temp);

	/* load background */
	temp = SDL_LoadBMP(BACKGROUND_SPRITE_PATH);
	background = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);	

	/* draw the background */		
	int x = 0;
	int y = 0;
	rcBackground.x = 0;
	rcBackground.y = 0;

	while (1 == 1){
	SDL_BlitSurface(background, NULL, screen, &rcBackground);
	}
	return 0;
}
