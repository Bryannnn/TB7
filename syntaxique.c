#include "syntaxique.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Création d'un arbre vide
Arbre creer_arbre (){
	return NULL;
}

void erreur(typejeton Tab[], int* i, int *e) {
	(*e)++;
	Tab[*i].lexem = ERREUR;
	Tab[*i].valeur.erreur = SYNTAXIQUE;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Insertion d'un noeud
Arbre creer_noeud( typejeton jeton, Arbre fils_gauche, Arbre fils_droit ) {

	Arbre resultat = creer_arbre();
	resultat = (Arbre)malloc( sizeof( struct Noeud ) );

	resultat->jeton.lexem = jeton.lexem;
	switch(jeton.lexem){

		case REEL:
			resultat->jeton.valeur.reel = jeton.valeur.reel;
			break;

		case VARIABLE:
		case PAR_OUV:
		case PAR_FERM:
		case FIN:
		break;

		case FONCTION:
			resultat->jeton.valeur.fonction = jeton.valeur.fonction;
			break;

		case OPERATEUR:
			resultat->jeton.valeur.operateur = jeton.valeur.operateur;
			break;

		case ERREUR:
			resultat->jeton.valeur.erreur = jeton.valeur.erreur;
			break;

		default: break;
	}

	resultat->fils_gauche = fils_gauche;
	resultat->fils_droit = fils_droit;

	return resultat;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : réel
Arbre reel(typejeton Tab[], int* i){
	Arbre A;
	A = creer_noeud(Tab[*i],NULL,NULL);
	*i = *i + 1;
	return A;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : fonction
Arbre fct(typejeton Tab[], int* i){
	typejeton racine;
	racine.lexem = Tab[*i].lexem;
	racine.valeur = Tab[*i].valeur;

	*i = *i + 1;
	Arbre A = creer_noeud(racine, NULL, AS(Tab, i));
	return A;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : parenthèse ouverte
Arbre par_ouv(typejeton Tab[], int* i, int* e){

	Arbre A, fg, fd = NULL;
	typejeton racine;

	*i = *i + 1;

	fg = AS(Tab, i);

	if(Tab[*i].lexem == PAR_FERM) {
		return fg;
	} else if (Tab[*i].lexem == FIN) {
		erreur(Tab, i, e);
		return NULL;
	}

	if(Tab[*i].lexem == OPERATEUR){
		racine.lexem = Tab[*i].lexem;
		racine.valeur = Tab[*i].valeur;
		*i = *i + 1;
	} else {
		erreur(Tab, i, e);
	}
	//Erreur si on a deux opérateurs à la suite
	if(Tab[*i].lexem == OPERATEUR) {
		erreur(Tab, i, e);
	}

	fd = AS(Tab, i);
	A = creer_noeud(racine,fg,fd);
	if(Tab[*i].lexem == PAR_FERM){
		*i = *i + 1;
	} else {
		//Si on a plus de deux réels ou variables dans une parenthèse
		erreur(Tab, i, e);
	}
	return A;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Remplissage de l'arbre
Arbre AS(typejeton Tab[], int* i){

	Arbre A = NULL;
	int erreurs = 0;
	int* e = &erreurs;

			switch(Tab[*i].lexem){
				//------------------------------------------------------------------
				case PAR_OUV:
					A = par_ouv(Tab, i, e);
					break;
				//------------------------------------------------------------------
				case REEL:
				case VARIABLE:
					A = reel(Tab, i);
				break;
				//------------------------------------------------------------------
				case FONCTION:
					A = fct(Tab, i);
				break;
				//------------------------------------------------------------------
				default:
					erreur(Tab, i , e);
		}
	if (*e == 0) {
			return A;
	} else {
		printf("Erreur syntaxique a %d \n", (*i+1));
		return NULL;
		//detection_fonction();
		//relancer la 1er fonction.
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void afficher( Arbre a) {
	if(a == NULL){
		printf("||\n");
		return;
	}
	else{
		switch(a->jeton.lexem){

		case REEL:
			printf("%d|%f\n",a->jeton.lexem, a->jeton.valeur.reel);
			break;

		case VARIABLE:
			printf("%d|%c\n",a->jeton.lexem, 'x');
			break;

		case FONCTION:
			printf("%d|%d\n",a->jeton.lexem, a->jeton.valeur.fonction);
			break;

		case OPERATEUR:
			printf("%d|%d\n",a->jeton.lexem, a->jeton.valeur.operateur);
			break;

		case ERREUR:
			printf("%d|%d\n",a->jeton.lexem, a->jeton.valeur.erreur);
			break;

		default: break;
	}
	}

	afficher(a->fils_gauche);
	afficher(a->fils_droit);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
/*
int i = 0;
int* p = &i;

typejeton tab_test[100];

Arbre A;

	tab_test[0].lexem = PAR_OUV;

	tab_test[1].lexem = REEL;
	tab_test[1].valeur.reel = 2;

	tab_test[2].lexem = OPERATEUR;
	tab_test[2].valeur.reel = PLUS;

	tab_test[3].lexem = REEL;
	tab_test[3].valeur.reel = 2;

	tab_test[4].lexem = PAR_FERM;

	tab_test[5].lexem = FIN;

	A = AS(tab_test, p);

	afficher(A);
*/
	return 0;
}
