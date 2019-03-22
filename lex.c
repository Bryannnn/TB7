/*#include <stdio.h>
#include <stdlib.h>*/
#include <conio.h>
#include <string.h>
//#include "jeton.h"

// "DETECTION_FONCTION" PERMET D'ASSOCIER A CHAQUE REEL, OPERATEUR, FONCTION, VARIABLE ET PARENTHESE UN JETON COMPORTANT UN LEXEM ET UNE VALEUR EVENTUELLE.
// ELLE GERE AUSSI LES errorS DE FRAPPE ET LA FIN DE L'EXPRESSION.

void detection_fonction(typejeton jeton[]){

  char fonction[100];
  //typejeton jeton[100];
  printf("Entrez votre fonction :\n");
  scanf("%s", &fonction);
  int i=0;
  int j=0;
  int error;

  while(fonction[i] != '\0'){
    error=1;

    // POUR LES OPERATEURS

    if(fonction[i] == ('+')){
      jeton[j].lexem=OPERATEUR;
      jeton[j].valeur.operateur=PLUS;
      error=0;
    }
    else if(fonction[i] == ('-')){
      jeton[j].lexem=OPERATEUR;
      jeton[j].valeur.operateur=MOINS;
      error=0;
    }
    else if(fonction[i] == ('*')){
      jeton[j].lexem=OPERATEUR;
      jeton[j].valeur.operateur=FOIS;
      error=0;
    }
    else if(fonction[i] == ('/')){
      jeton[j].lexem=OPERATEUR;
      jeton[j].valeur.operateur=DIV;
      error=0;
    }
    else if(fonction[i] == ('^')){
      jeton[j].lexem=OPERATEUR;
      jeton[j].valeur.operateur=PUIS;
      error=0;
    }

    // POUR PARENTHESE OUVERTE, PARENTHESE FERMEE ET VARIABLE

    else if(fonction[i] == '('){
      jeton[j].lexem=PAR_OUV;
      error=0;
    }
    else if(fonction[i] == ')'){
      jeton[j].lexem=PAR_FERM;
      error=0;
    }
    else if(fonction[i] == 'x'){
      jeton[j].lexem=VARIABLE;
      error=0;
    }

    // POUR LES FONCTIONS

    char temp[100];
    int itemp=i;
    int jtemp=0;
    // ON ENREGISTRE DANS UN TABLEAU LA SUITE DE LETTRES (LE MOT)
    while(fonction[itemp]>= 'A' && fonction[itemp]<= 'Z'){
      temp[jtemp]=fonction[itemp];
      temp[jtemp+1]='\0';
      itemp++;
      jtemp++;
    }
    // ON COMPARE LE TABLEAU AVEC LES FONCTIONS CONNUES
    if(strcmp(temp, "ABS") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=ABS;
      temp[0]='\0';
      i=i+2;
      error=0;
    }
    else if(strcmp(temp, "SIN") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=SIN;
      temp[0]='\0';
      i=i+2;
      error=0;
    }
    else if(strcmp(temp, "SQRT") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=SQRT;
      temp[0]='\0';
      i=i+3;
      error=0;
    }
    else if(strcmp(temp, "LN") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=LN;
      temp[0]='\0';
      i=i+1;
      error=0;
    }
    else if(strcmp(temp, "COS") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=COS;
      temp[0]='\0';
      i=i+2;
      error=0;
    }
    else if(strcmp(temp, "TAN") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=TAN;
      temp[0]='\0';
      i=i+2;
      error=0;
    }
    else if(strcmp(temp, "EXP") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=EXP;
      temp[0]='\0';
      i=i+2;
      error=0;
    }
    else if(strcmp(temp, "ARCCOS") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=ARCCOS;
      temp[0]='\0';
      i=i+5;
      error=0;
    }
    else if(strcmp(temp, "ARCSIN") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=ARCSIN;
      temp[0]='\0';
      i=i+5;
      error=0;
    }
    else if(strcmp(temp, "ARCTAN") == 0){
      jeton[j].lexem=FONCTION;
      jeton[j].valeur.fonction=ARCTAN;
      temp[0]='\0';
      i=i+5;
      error=0;
    }

    // POUR LES REELS

    if(fonction[i]>='0' && fonction[i]<='9'){
      char temp2[100];
      int itemp2=i;
      int jtemp2=0;
      // ON ENREGISTRE DANS UN TABLEAU LA SUITE DE CHIFFRES
      while(fonction[itemp2]>= '0' && fonction[itemp2]<= '9' || fonction[itemp2]== '.'){
        temp2[jtemp2]=fonction[itemp2];
        temp2[jtemp2+1]='\0';
        itemp2++;
        jtemp2++;
      }
      // ON DONNE A CHAQUE NOMBRE UN JETON
      jeton[j].lexem=REEL;
      jeton[j].valeur.reel=atof(temp2);
      temp2[0]='\0';
      i=i+(jtemp2-1);
      error=0;
    }
    // POUR LES REELS NEGATIFS
    else if(fonction[i]== '_'){
      i++;
      if(fonction[i]>='0' && fonction[i]<='9'){
        char temp2[100];
        int itemp2=i;
        int jtemp2=0;
        while(fonction[itemp2]>= '0' && fonction[itemp2]<= '9' || fonction[itemp2]== '.'){
          temp2[jtemp2]=fonction[itemp2];
          temp2[jtemp2+1]='\0';
          itemp2++;
          jtemp2++;
        }
        jeton[j].lexem=REEL;
        jeton[j].valeur.reel=-atof(temp2);
        temp2[0]='\0';
        i=i+(jtemp2-1);
        error=0;
      }
    }

    // POUR LES errorS

    if(error == 1){
      jeton[j].lexem=error;
      printf("error lexicale\n");
      main();
    }

    i++;
    j++;
  }

  // POUR LA FIN

  jeton[j].lexem=FIN;

}
