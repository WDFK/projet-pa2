#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "pieces.h"

object initTab(object p)
{
  int i, j;
  for (i = 0; i < 5; ++i)
    {
      for (j = 0; j < 5; ++j)
	{
	  p.tab[i][j] = 0;
	}
    }
  return p;
}

object_list * lirePiece(void)
{
  
  FILE * ptr_file;
  
  ptr_file = fopen("source.txt", "r");
  if (ptr_file == NULL){
    printf("Error opening file");
    return NULL;
  }
  int i, j;
  object_list *L;
  
  object tmp;
  char c, d;
  i = 0;
  j = 0;
  c = 'a';
  tmp = initTab(tmp);
    
  do {
    d = c;
    c = fgetc(ptr_file);
    
    if (c == '#'){
      //printf("#");
	tmp.tab[i][j] = 1;
	++j;
      }
    else if (c == '\n' && d == '\n'){
      //printf("\n");
      L = object_list_cons(tmp, L);
      tmp = initTab(tmp);
      i = 0;
      j = 0;
    }
    else if (c == '\n'){
      ++i;
      j = 0;
      //printf("\n");	
    }
    else{
	//printf(" ");
	++j;
      }
  }while (c != EOF);
  fclose(ptr_file);
  return L;
}

void afficherPiece(object * L)
{
  int i, j;  
    for(i=0; i<5; i++){
	for(j=0; j<5; j++){
	  printf("%d ",L->tab[i][j]);
	  }
	printf("\n");
      }
    printf("\n");
}

void rotatePiece(object * p)
{
  object p2 = *p;
  int i, j;
  *p = initTab(*p);
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      if(p2.tab[i][j] == 1){
	p->tab[j][4-i] = 1;
      }
    }
  }
  rognerPiece(p);
}

void rognerPiece(object * p){
  int i, j;
  int b1 = 1;
  int b2 = 1;
  for(i=0;i<5;i++){
    if(p->tab[0][i] == 1)
      b1 = 0;
    if(p->tab[i][0] == 1)
      b2 = 0;
  }
  if(b1){
    rognerLigne(p);
    rognerPiece(p);
  }
  if(b2){
  rognerColonne(p);
  rognerPiece(p);
  }    
}

void rognerLigne(object * p){
  int i, j;
  for(i=0;i<4;i++){
    for(j=0;j<5;j++){
      p->tab[i][j] = p->tab[i+1][j];
    }
  }
  for(i=0;i<5;i++)
    p->tab[4][i] = 0;
  
}

void rognerColonne(object * p){
  int i, j;
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      p->tab[i][j] = p->tab[i][j+1];
    }
  }
  for(i=0;i<5;i++)
    p->tab[i][4] = 0;
}
