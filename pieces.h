#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED

object_list * lirePiece(void);
object initTab(object p);
void afficherPiece(object * L);
void rotatePiece(object * p);
void rognerPiece(object * p);
void rognerLigne(object * p);
void rognerColonne(object * p);

#endif
