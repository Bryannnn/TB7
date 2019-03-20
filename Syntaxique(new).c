#include "syntaxique.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Création d'un arbre vide
Arbre creer_arbre (){
	return NULL;
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

		default: printf("Ceci n'est pas un operateur defini\n");
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
//Gestion du cas : fonction
Arbre par_ouv(typejeton Tab[], int* i){

	Arbre A, fg, fd = NULL;
	typejeton racine;

	*i = *i + 1;
	fg = AS(Tab, i);

	if(Tab[*i].lexem == OPERATEUR){
		racine.lexem = Tab[*i].lexem;
		racine.valeur = Tab[*i].valeur;
		*i = *i + 1;
	}
	fd = AS(Tab, i);
	A = creer_noeud(racine,fg,fd);
	*i = *i + 1;
	if(Tab[*i].lexem == PAR_FERM){
		*i = *i + 1;
	}
	return A;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Remplissage de l'arbre
Arbre AS(typejeton Tab[], int* i){

	Arbre A = NULL;

			switch(Tab[*i].lexem){
				//------------------------------------------------------------------		
				case PAR_OUV:
					A = par_ouv(Tab, i);
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
				printf("erreur\n");
		}
	return A;
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

		default: printf("Affichage impossible\n");
	}
	}

	afficher(a->fils_gauche);
	afficher(a->fils_droit);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){

int i = 0;
int* p = &i;

typejeton tab_test[100];

Arbre A;

	tab_test[0].lexem = PAR_OUV;

	tab_test[1].lexem = FONCTION;
	tab_test[1].valeur.fonction = SIN;


	tab_test[2].lexem = VARIABLE;

	tab_test[3].lexem = OPERATEUR;
	tab_test[3].valeur.operateur = PLUS;

	tab_test[4].lexem = REEL;
	tab_test[4].valeur.reel = 2;

	tab_test[5].lexem = PAR_FERM;

	tab_test[6].lexem = FIN;

A = AS(tab_test, p);
afficher(A);

return 0;
}
