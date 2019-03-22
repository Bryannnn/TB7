#ifndef SYNTAXIQUE_H
#define SYNTAXIQUE_H

#include "jeton.h"
//Fonction de création d'un arbre vide
Arbre creer_arbre();

//Fonction de création d'un noeud
Arbre creer_noeud();

//Fonction de remplissage de l'arbre
Arbre AS(typejeton Tab[], int* i);

//Fonction de traitement d'un réel
Arbre reel(typejeton Tab[], int* i);

//Fonction de traitement d'un opérateur
Arbre operation(typejeton Tab[], int* i);

//Fonction de traitement d'une fonction
Arbre fct(typejeton Tab[], int* i);

//Fonction de traitement d'une parenthèse ouverte
Arbre par_ouv(typejeton Tab[], int* i, int* e);

//Fonction qui est lancée lorsqu'on détecte une erreur
void erreur(typejeton Tab[], int* i, int *e);

void afficher(Arbre a);

#endif //SYNTAXIQUE_H
