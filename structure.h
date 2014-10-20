#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "SDL.h"

typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  char r;
  char g;
  char b;
}rgb;
  
//typedef struct piece * piece_ptr;

typedef struct {
  int tab[5][5];
  SDL_Rect src_rect;
  pos coord;
  rgb color;
}object;

typedef struct {
  object data;
  struct object_list * next;
}object_list;

/* "constructors" */

object_list * object_list_cons(object p, object_list* L);

/* free function */

//void object_list_free(object_list * L);

#endif
