#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<math.h>


int main() {

	char* expression;
	int lenght=0;
	int i;

	printf("Rentrer la fonction ");
	scanf("%s", &expression);
	printf("%s\n", &expression);


	lenght = strlen(&expression);
	printf("longueur : %d", lenght);

	for (i = 0; i <= lenght; i++) {
		if (expression[i] == '+') {
			printf("lol");
		}
	}

	_getch();

	return 0;

}