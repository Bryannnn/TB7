#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum
{
	REEL, OPERATEUR, FONCTION, ERREUR, FIN, PAR_OUV, PAR_FERM, VARIABLE, BAR_OUV, BAR_FERM, ABSOLU
}typelexem;

typedef enum
	{
	PLUS, MOINS, FOIS, DIV, PUIS, MOD
}typeoperateur;

typedef enum
	{
	ABS, SIN, SQRT, LOG, COS, TAN, EXP, ARCCOS, ARCSIN, ARCTAN, LN
}typefonction;

typedef enum
	{
	LEXICALE, SYNTAXIQUE
}typeerreur;

typedef union {
	float reel;
	typefonction fonction;
	typeoperateur operateur;
	typeerreur erreur;
}typevaleur;

typedef struct {
	typelexem lexem;
	typevaleur valeur;
}typejeton;

struct Noeud {
    typejeton jeton;
    struct Noeud *fils_gauche;
    struct Noeud *fils_droit;
};
typedef struct Noeud *Arbre;
