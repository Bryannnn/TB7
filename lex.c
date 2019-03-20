#include<stdio.h>
#include<conio.h>
#include<math.h>
#include "jeton.h"

int main() {

	char expression[100]; //Expression mathématique entrée par l'utilisateur
	int length; //longueur de l'expression
	int i; //compteur
	int imax; //nombre total d'éléments dans l'expression
	int s; //Résultat de l'addition pour le cas des REEL
	typejeton jeton[200]; //Sortie de l'AL

printf("Rentrer la fonction ");
	scanf("%s", &expression);
	printf("%s\n", expression);


	length = strlen(expression);
	printf("longueur : %d\n", length);

	for (i = 0; i <= length; i++) { //Detection de chaque élément de l'expression
		
		//Detection des lexèmes OPERATEURS 
		
		if (expression[i] == '+') {
			printf("+\n");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = PLUS;
		}
		 else if (expression[i] == '-') {
			printf("-");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = MOINS;
		}
		else if (expression[i] == '*') {
			printf("*");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = FOIS;
		}
		else if (expression[i] == '/') {
			printf("/");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = DIV;
		}
		else if (expression[i] == '^') {
			printf("^");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = PUIS;
		}

		//Detection des lexèmes DIVERS

		else if (expression[i] == '(') {
			printf("(");
			jeton[i].lexem = PAR_OUV;
		}
		else if (expression[i] == ')') {
			printf(")");
			jeton[i].lexem = PAR_FERM;
		}
		else if (expression[i] == 'x') {
			printf("x");
			jeton[i].lexem = VARIABLE;
		}
		else if (expression[i] == NULL ) {
			printf("fin\n");
			jeton[i].lexem = FIN;
		}
		else if (expression[i] == ')') {
			printf(")");
			jeton[i].lexem = PAR_FERM;
		}

		//Detection  du lexème REEL

		else if (expression[i]>='0' && expression[i] <= '9') {
			int j = 0; //compteur 
			int temp[100]; //tableau temporaire (1 case = un chiffre)
			temp[j]= (expression[i]-'0'); //remplissage du tableau

			while (expression[i] >= '0' && expression[i] <= '9') { //Si le 
				j++;
				temp[j] = (expression[i] - '0'); //remplissage du tableau
				i++;
			}
			
			i = i - 1; 
			int k = j; //k est la longueur totale du nombre 
			printf("longueur du nombre = %d\n", k);
			j = 0;
			s = 0;

			while (temp[j]>=0 && temp[j]<=9) {
				j++;
				int p = pow(10, k - j);
				s += temp[j] * p;
				
			}
			printf("s=%d\n", s);
			jeton[i].lexem = REEL;
			jeton[i].valeur.reel = s;
			printf("jeton=%f\n", jeton[i].valeur.reel);
		}
		else{
			printf("erreur\n");
			jeton[i].lexem = ERREUR;
		}
	}

	i = 0;
	for (i = 0; i < length; i++) {
		printf("lexeme = %d\n", jeton[i].lexem);
		printf("valeur reelle = %f\n", jeton[i].valeur.reel);
		printf("valeur operateur = %d\n", jeton[i].valeur.operateur);
		printf("valeur fonction = %d\n", jeton[i].valeur.fonction);
	}

	_getch();

	return 0;

}
