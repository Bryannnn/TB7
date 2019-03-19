#include <math.h>
#include "jeton.h"


float Evaluateur(Arbre a, float x)
{
    if (a != NULL)
    {
        if(a->jeton.lexem == FONCTION)
        {
            if(a->jeton.valeur.fonction == ABS)
            {
                return abs(Evaluateur(a->fils_gauche,x));
            }
            if(a->jeton.valeur.fonction == COS)
            {
                return cos(Evaluateur(a->fils_gauche,x));
            }
            if(a->jeton.valeur.fonction == SIN)
            {
                return sin(Evaluateur(a->fils_gauche,x));
            }
            if (a->jeton.valeur.fonction == TAN)
            {
                return tan(Evaluateur(a->fils_gauche,x));
            }
            if(a->jeton.valeur.fonction == SQRT)
            {
                return sqrt(Evaluateur(a->fils_gauche,x));
            }
            if(a->jeton.valeur.fonction == LOG)
            {
                return log(Evaluateur(a->fils_gauche,x));
            }
            if(a->jeton.valeur.fonction == EXP)
            {
                return exp(Evaluateur(a->fils_gauche,x));
            }
        }


        if (a->jeton.lexem==OPERATEUR)
        {
            switch (a->jeton.valeur.operateur)
            {
            case PLUS:
                return (Evaluateur(a->fils_gauche,x)+ Evaluateur(a->fils_droit,x));
                break;

            case MOINS:
                return (Evaluateur(a->fils_gauche,x) - Evaluateur(a->fils_droit,x));
                break;

            case FOIS:
                return (Evaluateur(a->fils_gauche,x) * Evaluateur(a->fils_droit,x));
                break;

            case DIV:{
                if (a->fils_gauche==0)
                {
                    return printf("Erreur division par 0");
                }
                else
                {
                    return (Evaluateur(a->fils_gauche,x) / Evaluateur(a->fils_droit,x));
                    break;
                }
            }

            case PUIS:
                return pow(Evaluateur(a->fils_gauche,x), Evaluateur(a->fils_droit,x));
                break;

            default:
                printf("Erreur");
            }
        }


        else if (a->jeton.lexem==REEL){
            return (a->jeton.valeur.reel);
    }
        else if (a->jeton.lexem==VARIABLE)
            return x;
    }
}


