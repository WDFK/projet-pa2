#include "SDL.h"
#include "pieces.h"
#include "structure.h"
#include "pentomino.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 1000
#define SPRITE_SIZE 16
#define img_path "bloc.bmp"

void init(object_list * L)
{
  int i = 0;
  object_list * L_tmp;
  L_tmp = L;
  gameover = 0;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Pentomino", "SDL Animation");
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

  /* Init pieces */
  
   do {
     printf("\n\n%p\n", L);
     L->data.coord.x = 50*i;
     L->data.coord.y = 50*i;
     L = L->next;
     i++;
   }while (L->next != NULL);
     L->data.coord.x = 50*i;
     L->data.coord.y = 50*i;
  L = L_tmp;
}

void main_loop(object_list * L)
{
  object_list * L_tmp = L;
  int i = 0;
  while(!gameover){
    handle_events();
    do{
      handle_pieces(L->data.coord.x, L->data.coord.y, L->data);
      L = L->next;
    } while (L->next != NULL);
    handle_pieces(L->data.coord.x, L->data.coord.y, L->data);
    L = L_tmp;
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

void handle_pieces(int x, int y, object p)
{
  SDL_Surface* temp = SDL_LoadBMP("bloc.bmp");
  object * obj;
  int i, j, tmp;
  tmp = x;
    for(i=0; i<5; i++){
      for(j=0; j<5; j++){
	if(p.tab[i][j] == 1){
	  obj = &p;
	  obj->src_rect.x = x;
	  obj->src_rect.y = y;
	  obj->src_rect.w = 16;
	  obj->src_rect.h = 16;
	  SDL_BlitSurface(temp, NULL, screen, &(obj->src_rect));
	}
	x += 16;
      }
      y += 16;
      x = tmp;
    }
  SDL_Flip(screen);
}
