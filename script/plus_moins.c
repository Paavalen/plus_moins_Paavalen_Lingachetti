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
            printf("bingo");
        }
}

void main()
{
    int choix_joueur;
    
    srand(time(NULL));
    int valeur_a_trouver;
    valeur_a_trouver  = rand() % 100 + 1;
    

    do
    {    
        printf("Entrer un valeur\n");
        scanf("%d",&choix_joueur);
        plus_moins(choix_joueur, valeur_a_trouver);
        
    }while(choix_joueur!=valeur_a_trouver);
}