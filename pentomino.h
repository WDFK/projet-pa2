#ifndef PENTO_H_INCLUDED
#define PENTO_H_INCLUDED
#include "structure.h"
#include "pieces.h"
int gameover;
int mouseleft;
// Screen
SDL_Surface* screen;
// Pieces list

void init(object_list * L);
void main_loop(object_list * L);
void handle_events(object_list * L);
void draw_piece(int x, int y, object);
void draw_all_pieces(object_list * L);
object_list * checkCollide(int x, int y, object_list * L);
void handlePieceMov(object_list * p, SDL_Event * event);
#endif
