#ifndef PENTO_H_INCLUDED
#define PENTO_H_INCLUDED
#include "structure.h"
#include "pieces.h"
#include "SDL.h"

int gameover;
// Screen
SDL_Surface* screen;
// Pieces list
object_list * L;

void init(void);
void main_loop(void);
void handle_events(void);
void handle_pieces(void);
#endif
