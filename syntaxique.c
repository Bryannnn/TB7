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
	resultat->jeton.valeur = jeton.valeur;
	resultat->fils_gauche = fils_gauche;
	resultat->fils_droit = fils_droit;

	return resultat;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : réel
Arbre reel(typejeton Tab[],int i){

	Arbre A;
	A = creer_noeud(Tab[i],NULL,NULL);

	return A;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : opérateur
Arbre operateur(typejeton Tab[],Arbre A,int i){

	int j = i + 1;
	Arbre tmp;

	tmp = AS(Tab, j);
	A = creer_noeud(Tab[i], A, tmp);

	return A;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : opérateur
/*Arbre operateur(typejeton Tab[],int* i){

	int j = *i + 1;
	Arbre A, tmp;

	tmp = AS(Tab, j);
	A = creer_noeud(Tab[*i],A,tmp);

	return A;
}*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Remplissage de l'arbre
Arbre AS(typejeton Tab[], int i){

	Arbre A;
	while(Tab[i].lexem != FIN){
		switch(Tab[i].lexem){

			//Si le jeton actuel est une parenthèse, on passe au jeton suivant
			case REEL: 
			case VARIABLE:
				A = reel(Tab,i);
			break;
			//Si le jeton actuel est un réel, on crée un arbre dans lequel on insère le jeton (fils_gauche et fils_droit égaux à NULL)
			case OPERATEUR:
				A = operateur(Tab, A, i);
			break;

			default:
			printf("erreur");
		}

		i = i + 1;
	}

	return A;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void afficher( Arbre a) {
	if(a == NULL){
		return;
	}
	else{
		printf("%d|%f|\n",a->jeton.lexem,a->jeton.valeur.reel);
	}

	afficher(a->fils_gauche);
	afficher(a->fils_droit);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){

int i = 0;
typejeton tab_test[100];

Arbre A;

	tab_test[0].lexem = REEL;
	tab_test[0].valeur.reel = 1;
	tab_test[1].lexem = OPERATEUR;
	tab_test[1].valeur.operateur = PLUS;
	tab_test[2].lexem = REEL;
	tab_test[2].valeur.reel = 2;
	tab_test[3].lexem = FIN;

	//printf("%d\n",tab_test[0].lexem);
	//printf("%f\n",tab_test[0].valeur.reel);

A = AS(tab_test, i);
afficher(A);

return 0;
}
