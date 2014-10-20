#ifndef PENTO_H_INCLUDED
#define PENTO_H_INCLUDED
#include "structure.h"
#include "pieces.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 640
#define SPRITE_SIZE 16
#define img_path "bloc.bmp"
int gameover;
int mouseleft;
// Screen
SDL_Surface* screen;
// Pieces list

void init(object_list * L);
void main_loop(object_list * L);
void handle_events(object_list * L);
void draw_piece(object);
void draw_all_pieces(object_list * L);
object_list * checkCollide(int x, int y, object_list * L);
void handlePieceMov(object_list * p, SDL_Event * event);
void draw_corners(void);
int checkWin(object_list * L);
void initPiecesCoord(object_list * L);
void initPiecesColor(object_list * L);
#endif
