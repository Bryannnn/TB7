#include<stdio.h>
#include<conio.h>
#include<math.h>

typedef enum
{
	REEL, OPERATEUR, FONCTION, ERREUR, FIN, PAR_OUV, PAR_FERM, VARIABLE, BAR_OUV, BAR_FERM, ABSOLU
}typelexem;

typedef enum
	{
	PLUS, MOINS, FOIS, DIV, PUIS
}typeoperateur;

typedef enum
	{
	ABS, SIN, SQRT, LOG, COS, TAN, EXP, ENTIER, VAL_NEG, SINC
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
    struct Noeud *jeton_preced;
    struct Noeud *jeton_suiv;
} Node;
typedef struct Noeud *Arbre;
