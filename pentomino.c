#include "SDL.h"
#include "SDL_draw.h"
#include "pieces.h"
#include "structure.h"
#include "pentomino.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 640
#define SPRITE_SIZE 16
#define img_path "bloc.bmp"

void init(object_list * L){
  int i = 0;
  gameover = 0;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Pentomino", "SDL Animation");
  SDL_EnableKeyRepeat(700, 70);
  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWSURFACE);

  /* Init pieces coord */
  
   do {
     //printf("\n\n%p\n", L);
     L->data.coord.x = 80*i > 480 ? 80*(i-6) : 80*i;
     L->data.coord.y = 80*i > 480 ? 80 : 0;
	 
     L = L->next;
     i++;
   }while (L != NULL);
}

void main_loop(object_list * L){
  object_list * L_tmp = L;
  int i = 0;
  int last_time_ms = 0;

  while(!gameover){
    while (SDL_GetTicks() - last_time_ms < 1000/60);
    last_time_ms = SDL_GetTicks();
    handle_events(L);
  }
}

void handle_events(object_list * L){
  SDL_Event event;
  object_list * piece;
  object_list * L_tmp = L;
  
  do{
    while(SDL_PollEvent(&event) && !gameover){
      if (event.type == SDL_QUIT)
	gameover = 1;
      else if (event.type == SDL_MOUSEBUTTONDOWN){
	switch(event.button.button){
	case SDL_BUTTON_LEFT:
	  if (!mouseleft){
	    piece = checkCollide(event.button.x, event.button.y, L);
	    if (piece){	    
	      mouseleft = 1;
	    }
	  }
	  else{
	    mouseleft = 0;
	  }
	  break;
	case SDL_BUTTON_RIGHT:
	  if(piece)
	    rotatePiece(&piece->data);
	  break;
	default:
	  break;
	}	
      }
    }
    handlePieceMov(piece, &event);    
    draw_all_pieces(L);
  }while(mouseleft);
}
void handlePieceMov(object_list * p, SDL_Event * event)
{
  if (!p)
    return;
  p->data.coord.x = event->button.x/16*16;
  p->data.coord.y = event->button.y/16*16;
  
}

object_list * checkCollide(int x, int y, object_list * L){
  object_list * tmp = L;
  do{
    if (x >= L->data.coord.x && x < L->data.coord.x+80 && y >= L->data.coord.y && y < L->data.coord.y+80){
      if (L->data.tab[(y - L->data.coord.y)/16][(x - L->data.coord.x)/16]){     
	return L;
      }
    }
    L = L->next;
  }while (L != NULL);
  return NULL;
}

void draw_piece(int x, int y, object p){
  SDL_Surface* temp = SDL_LoadBMP(img_path);
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
	  //Draw_Line(screen, x, y, x+16, y, p.rgb);
	}
	x += 16;
      }
      y += 16;
      x = tmp;
    }
}

/* void Draw_Line(SDL_Surface *super, */
/*                Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, */
/*                Uint32 color); */


void draw_all_pieces(object_list * L){  
  int i = 16;
  SDL_FillRect(SDL_GetVideoSurface(), NULL, 0 );
  while(L!=NULL){
    draw_piece(L->data.coord.x, L->data.coord.y, L->data);
    L = L->next;
    
  }
  SDL_Flip(screen);
}
