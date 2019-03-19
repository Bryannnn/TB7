#include<stdio.h>
#include<conio.h>
#include<math.h>


int main() {

	char expression[100];
	int length=0;
	int i;

	printf("Rentrer la fonction ");
	scanf("%s", &expression);
	printf("%s\n", expression);


	length = strlen(expression);
	printf("longueur : %d", length);

	for (i = 0; i <= length; i++) {
		if (expression[i] == '+') {
			printf("lol");
		}
	}

	_getch();

	return 0;

}
