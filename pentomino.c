#include "SDL.h"
#include "pentomino.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE 16
#define img_path "bloc.bmp"

void init(void)
{
  int i = 0;
  
  gameover = 0;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Pentomino", "SDL Animation");
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

  /* Init pieces */
  while (L->next != NULL)
    {
      L->data.coord.x = 0;
      L->data.coord.y = i+1 * 6;
      L = L->next;
    }
}

void main_loop(void)
{
  while(!gameover){
    handle_events();
    L = *LL;
    printf("%p\n", LL);
    while (L->next != NULL){
      printf("%p\n", L);
      handle_pieces(L->data.coord.x, L->data.coord.y);
      L = L->next;
      }
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

void handle_pieces(int x, int y)
{
  SDL_Surface* temp = SDL_LoadBMP("bloc.bmp");
  object * obj;
  int i, j, tmp;
  tmp = x;
    for(i=0; i<5; i++){
      for(j=0; j<5; j++){
	if(L->data.tab[i][j] == 1){
	  obj = &(L->data);
	  obj->src_rect.x = x;
	  obj->src_rect.y = y;
	  obj->src_rect.w = 32;
	  obj->src_rect.h = 32;
	  SDL_BlitSurface(temp, NULL, screen, &(obj->src_rect));
	}
	x += 16;
      }
      y += 16;
      x = tmp;
    }
  SDL_Flip(screen);
}
