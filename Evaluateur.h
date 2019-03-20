#include <math.h>
#include "jeton.h"


float Evaluateur(Arbre a, float x)
{
    if (a != NULL)
    {
        if(a->jeton.lexem == FONCTION)
        {
            switch (a->jeton.valeur.fonction)
            {

            case ABS:
                return abs(Evaluateur(a->fils_gauche,x));
                break;

            case cos:
                return cos(Evaluateur(a->fils_gauche,x));
                break;

            case sin:
                return sin(Evaluateur(a->fils_gauche,x));
                break;

            case tan:
                return tan(Evaluateur(a->fils_gauche,x));
                break;

            case sqrt:
                return sqrt(Evaluateur(a->fils_gauche,x));

            case log:
                return log(Evaluateur(a->fils_gauche,x));
                break;

            case exp:
                return exp(Evaluateur(a->fils_gauche,x));
                break;

            case COSH:
                return cosh(Evaluateur(a->fils_gauche,x));
                break;

            case SINH:
                return sinh(Evaluateur(a->fils_gauche,x));
                break;

            case TANH:
                return tanh(Evaluateur(a->fils_gauche,x));
                break;

            case ACOS:
                return acos(Evaluateur(a->fils_gauche,x));
                break;

            case ASIN:// a verfier
                return asin (Evaluateur (a->fils_gauche, x));
                break;

            case ATAN:
                return atan(Evaluateur(a->fils_gauche,x));
                break;

            default:
                printf("Erreur");

            }
        }


        /* if(a->jeton.valeur.fonction == ABS)
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
         }*/
    }


    else if (a->jeton.lexem==OPERATEUR)
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

        case DIV:
        {
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

        case LN:
            if (Evaluateur(a->fils_gauche,x)<=0)
                printf("Erreur LN non defini \n");
            else
                return (log(Evaluateur(a->fils_gauche,x)));
            break;

        case MODULO:
        {
            if (Evaluateur(a->fils_droit,x)==0)
            {
                printf("Erreur\n");
                break;
            }
            else
            {
                return ((int)Evaluateur(a->fils_gauche,x)%(int)Evaluateur(a->fils_droit,x));
                break;
            }
        }
        default:
            printf("Erreur");
        }
    }

    else if (a->jeton.lexem==REEL)
    {
        return (a->jeton.valeur.reel);
    }
    else if (a->jeton.lexem==VARIABLE)
        return x;
}
}


