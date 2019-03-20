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
Arbre reel(typejeton Tab[],int i){

	return creer_noeud(Tab[i],NULL,NULL);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : opérateur
Arbre operation(typejeton Tab[],Arbre A,int i){

	int j = i + 1;
	//Arbre tmp;

	//tmp = AS(Tab, j);
	A = creer_noeud(Tab[i], A, creer_noeud(Tab[j],NULL,NULL));

	return A;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : fonction
/*Arbre fct(typejeton Tab[],Arbre A, int i){

	A = creer_noeud(Tab[i], A, NULL);

	return A;
}*/

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Gestion du cas : fonction
Arbre par_ouv(typejeton Tab[],Arbre A, int i){

	int j = i + 1;
	A = creer_noeud(Tab[i-1],A,AS(Tab,j));

	return A;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Remplissage de l'arbre
Arbre AS(typejeton Tab[], int i){

	Arbre A = NULL;
	while(Tab[i].lexem != FIN){
		switch(Tab[i].lexem){

			//Si le jeton actuel est une parenthèse, on passe au jeton suivant
			case REEL: 
			case VARIABLE:
				A = reel(Tab,i);
				i = i + 1;
			break;

			//Si le jeton actuel est un opérateur
			case OPERATEUR:
				if(Tab[i+1].lexem == PAR_OUV){
					return A = creer_noeud(Tab[i],A,AS(Tab, i+1));				
				}
				else{
					A = operation(Tab, A, i);
					i = i + 2;
				}				
			break;

			//Si le jeton actuel est une fonction
			/*case FONCTION:
				A = fct(Tab, A, i);
				i = i + 1;
			break;*/
			
			//Si le jeton actuel est une parenthèse ouverte
			case PAR_OUV:
			case PAR_FERM:
				//A = par_ouv(Tab, A, i);
				i = i + 1;
			break;

			default:
			printf("erreur");
		}

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

		default: printf("Ceci n'est pas un opérateur défini\n");
	}
	}

	afficher(a->fils_gauche);
	afficher(a->fils_droit);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){

int i = 0;
typejeton tab_test[100];

Arbre A;
	
	tab_test[0].lexem = PAR_OUV;

	tab_test[1].lexem = VARIABLE;

	tab_test[2].lexem = OPERATEUR;
	tab_test[2].valeur.operateur = PLUS;

	tab_test[3].lexem = PAR_OUV;

	tab_test[4].lexem = REEL;
	tab_test[4].valeur.reel = 3;

	tab_test[5].lexem = OPERATEUR;
	tab_test[5].valeur.operateur = FOIS;

	tab_test[6].lexem = REEL;
	tab_test[6].valeur.reel = 4;

	tab_test[7].lexem = PAR_FERM;
	tab_test[7].lexem = PAR_FERM;

	tab_test[8].lexem = FIN;

A = AS(tab_test, i);
afficher(A);

return 0;
}
