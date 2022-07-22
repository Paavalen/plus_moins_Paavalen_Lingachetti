#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins(int choix_joueur, int valeur_a_trouver)
{
    if(choix_joueur<valeur_a_trouver)
        {
            printf("plus\n");
        }
    else if(choix_joueur>valeur_a_trouver)
        {
            printf("moins\n");
        }
    else
        {
            printf("bingo\n");
        }
}

int main()
{
    int choix_joueur,essaie,mode,valeur_a_trouver;

    printf("Entrer le mode de difficulter :\n");
    printf("Entrer 1 pour facile (essais illimités)\n");
    printf("Entrer 2 pour moyen (25 essais)\n");
    printf("Entrer 3 pour difficile (10 essais)\n");

    scanf("%d",&mode);

    switch(mode)
    {
        case 1:
            srand(time(NULL));
            valeur_a_trouver = rand() % 100 + 1;

            do
            {    
                printf("Entrer un valeur\n");
                scanf("%d",&choix_joueur);
                plus_moins(choix_joueur, valeur_a_trouver);

                if(choix_joueur==valeur_a_trouver)
                    return 0;
            }while(choix_joueur!=valeur_a_trouver);            
    
    
        case 2:
            srand(time(NULL));
            valeur_a_trouver = rand() % 100 + 1;

            for(int i=0; i<25;i++)
            {
                printf("Entrer un valeur\n");
                scanf("%d",&choix_joueur);
                plus_moins(choix_joueur, valeur_a_trouver);

                if(choix_joueur==valeur_a_trouver)
                    return 0;

                if(i==24)
                {
                    printf("Dommage vous avez perdu");
                    return 0;
                }
            }
        case 3:
            srand(time(NULL));
            valeur_a_trouver = rand() % 100 + 1;

            for(int i=0; i<10;i++)
            {
                printf("Entrer un valeur\n");
                scanf("%d",&choix_joueur);
                plus_moins(choix_joueur, valeur_a_trouver);

                if(choix_joueur==valeur_a_trouver)
                    return 0;

                if(i==9)
                {
                    printf("Dommage vous avez perdu");
                    return 0;
                }
            }

        default:
            printf("Veuillez entrer 1, 2 ou 3");
            return 1;

    }

    return 0;
}