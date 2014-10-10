#include "SDL.h"
#include "pentomino.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define img_path "bloc.bmp"

void init(void)
{
  int i;
  
  gameover = 0;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Pentomino", "SDL Animation");
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE);

  /* Init pieces */
  for(i=0;i<12 && L->next != NULL;i++)
    {
      L->data.coord.x = 0;
      L->data.coord.y = i * 50;
    }
}

void main_loop(void)
{
  while(!gameover){
    handle_events();
    handle_pieces();    
  }
}

void handle_events(void)
{
  SDL_Event event;
  object * piece;
  while(SDL_PollEvent(&event) && !gameover){
    if (event.type == SDL_QUIT)
      gameover = 1;
  }
  
}

void handle_pieces(void)
{
  SDL_Surface* temp = SDL_LoadBMP(img_path);
  object * obj;
  while (L->next != NULL){
    obj = &(L->data);
    obj->src_rect.x = 0;
    obj->src_rect.y = 0;
    obj->src_rect.w = 16;
    obj->src_rect.h = 16;
    SDL_BlitSurface(temp, NULL, screen, &(obj->src_rect));
    L = L->next;
    //test
    }
}
