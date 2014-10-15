#ifndef PENTO_H_INCLUDED
#define PENTO_H_INCLUDED
#include "structure.h"
#include "pieces.h"
int gameover;
// Screen
SDL_Surface* screen;
// Pieces list

void init(object_list *);
void main_loop(object_list *);
void handle_events(void);
void handle_pieces(int x, int y, object);
#endif
