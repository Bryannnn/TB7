#include "Evaluateur.h"


float Evaluateur(Arbre a, float x)
{
    float resultat=0;

    if (a != NULL)
    {
        if(a->jeton.lexem == FONCTION)
        {
            switch (a->jeton.valeur.fonction)
            {

            case ABS:
                resultat= abs(Evaluateur(a->fils_droit,x));
                break;

            case COS:
                resultat= cos(Evaluateur(a->fils_droit,x));
                break;

            case SIN:
                resultat= sin(Evaluateur(a->fils_droit,x));
                break;

            case TAN:
                resultat= tan(Evaluateur(a->fils_droit,x));
                break;

            case SQRT:
            {
                if (Evaluateur(a->fils_droit,x)<0)
                    printf("Erreur valeur négative");
                else
                {
                    resultat= sqrt(Evaluateur(a->fils_droit,x));
                }
            }
            break;


            case LOG:{

                if(Evaluateur(a->fils_droit,x)<=0)
                    printf("Domaine non défini");

                    else

                        resultat= log(Evaluateur(a->fils_gauche,x));
                }
                break;

            case EXP:
                resultat= exp(Evaluateur(a->fils_droit,x));
                break;

            case COSH:{
                if (Evaluateur(a->fils_droit,x)<1)
                    printf("Erreur du domaine");
                else

                resultat= cosh(Evaluateur(a->fils_droit,x));
            }

                break;

            case SINH:
                resultat= sinh(Evaluateur(a->fils_droit,x));
                break;

            case TANH:{
                if (Evaluateur(a->fils_droit,x)<0)
                    printf("Erreur du Domaine");
                else
                resultat= tanh(Evaluateur(a->fils_droit,x));
            }

                break;

            case ACOS:

            {
                if (Evaluateur(a->fils_droit,x)<-1 || Evaluateur(a->fils_droit,x>1))
                    printf("Domaine non défini");

                else
                    resultat= acos(Evaluateur(a->fils_droit,x));
            }

            break;


            case ASIN:
            {

                if (Evaluateur(a->fils_droit,x)<-1 || Evaluateur(a->fils_droit,x>1))
                    printf("Domaine non défini");

                else
                    resultat= asin (Evaluateur(a->fils_droit, x));
            }

            break;

            case ATAN:
                resultat= atan(Evaluateur(a->fils_droit,x));
                break;

            default:
                printf("Erreur");

            }
        }
        else if (a->jeton.lexem==OPERATEUR)
        {
            switch (a->jeton.valeur.operateur)
            {
            case PLUS:
                resultat= (Evaluateur(a->fils_gauche,x)+ Evaluateur(a->fils_droit,x));
                break;

            case MOINS:
                resultat= (Evaluateur(a->fils_gauche,x) - Evaluateur(a->fils_droit,x));
                break;

            case FOIS:

                resultat= (Evaluateur(a->fils_gauche,x) * Evaluateur(a->fils_droit,x));
                break;

            case DIV:
            {
                if (Evaluateur(a->fils_droit,x)==0)
                {
                    printf("Erreur division par");
                }
                else
                {
                    resultat= Evaluateur(a->fils_gauche,x) / Evaluateur(a->fils_droit,x);

                }
                break;
            }

            case PUIS:
                resultat= pow(Evaluateur(a->fils_gauche,x), Evaluateur(a->fils_droit,x));
                break;

            case LN:
                if (Evaluateur(a->fils_droit,x)<=0)
                    printf("Erreur LN non defini \n");
                else
                    resultat= (log(Evaluateur(a->fils_droit,x)))/10;
                break;

            case MOD:
            {
                if (Evaluateur(a->fils_droit,x)==0)
                {
                    printf("Erreur\n");
                }
                else
                {
                    resultat= ((int)Evaluateur(a->fils_gauche,x)%(int)Evaluateur(a->fils_droit,x));

                }
                break;
            }
            default:
                printf("Erreur");
            }
        }

        else if (a->jeton.lexem==REEL)
        {
            resultat= (a->jeton.valeur.reel);
        }
        else if (a->jeton.lexem==VARIABLE)
            resultat= x;

        return resultat;
    }


}
