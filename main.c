#include<stdio.h>
#include<stdlib.h>
#include "jeton.h"
#include "syntaxique.c"
#include "lex.c"

int main() {
  //Partie analyse lexicale
  typejeton tab[100];
  detection_fonction(tab);

  //Partie analalyse syntaxique
  //typejeton tab_test[100];
  int i = 0;
  int* p = &i;
  Arbre A;
	A = AS(tab, p);
	//afficher(A);
  return 0;
}
