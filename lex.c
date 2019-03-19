#include<stdio.h>
#include<conio.h>
#include<math.h>
#include "jeton.h"


int main() {

	char expression[100]; //Expression mathématique entrée par l'utilisateur
	int length; //longueur de l'expression
	int i; //compteur
	int s;
	typejeton jeton[200]; //Sortie de l'AL

printf("Rentrer la fonction ");
	scanf("%s", &expression);
	printf("%s\n", expression);


	length = strlen(expression);
	printf("longueur : %d\n", length);

	for (i = 0; i <= length; i++) {
		if (expression[i] == '+') {
			printf("+");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = PLUS;
		}
		if (expression[i] == '-') {
			printf("-");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = MOINS;
		}
		if (expression[i] == '*') {
			printf("*");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = FOIS;
		}
		if (expression[i] == '/') {
			printf("/");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = DIV;
		}
		if (expression[i] == '^') {
			printf("^");
			jeton[i].lexem = OPERATEUR;
			jeton[i].valeur.operateur = PUIS;
		}
		if (expression[i] == '(') {
			printf("(");
			jeton[i].lexem = PAR_OUV;
		}
		if (expression[i] == ')') {
			printf(")");
			jeton[i].lexem = PAR_FERM;
		}
		if (expression[i] == 'x') {
			printf("x");
			jeton[i].lexem = VARIABLE;
		}
		if (expression[i] == NULL ) {
			printf("fin");
			jeton[i].lexem = FIN;
		}
		if (expression[i] == ')') {
			printf(")");
			jeton[i].lexem = PAR_FERM;
		}
		if (expression[i]>='0' && expression[i] <= '9') {
			int j = 0;
			int temp[100];
			temp[j]= (expression[i]-48);

			while (expression[i] >= '0' && expression[i] <= '9') {
				j++;
				temp[j] = (expression[i] - 48);
				i++;
			}
			
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
		}
	}

	_getch();

	return 0;

}
