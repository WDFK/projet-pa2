#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  char r;
  char g;
  char b;
}color;

//typedef struct piece * piece_ptr;

typedef struct {
  int tab[5][5];
  pos coord;
  color rgb;
  int entier;
}object;

typedef struct {
  object data;
  struct object_list * next;
}object_list;

/* "constructors" */

object_list * object_list_cons(object p, object_list* L);

/* access functions */

//bool object_list_is_empty(object_list L);
//object object_list_head(object_list L);

/* free function */

//void object_list_free(object_list * L);

#endif
