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
    int tour,valeur_a_trouver,essaie,choix_joueur,nj,mode,score_j1 = 0,score_j2 = 0;

    printf("Entrer le nombre de joueur (1/2): ");
    scanf("%d",&nj);

    switch(nj)
    {
        case 1:
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
        case 2:

                printf("Veuillez inserer le nombre de tour : ");
	            scanf("%d",&tour);
            
                do
                {
                    printf("\nJoueur 1, Entrer le nombre d'essaie maximum pour le Joueur 2 (au moins 10): ");
	            	scanf("%d",&essaie);
            
                    if(essaie<10)
                    {
                        printf("La valeur minimal est 10");
                        return 1;
                    }
            
                    srand(time(NULL));
                    valeur_a_trouver = rand() % 100 + 1;
            
                    do
	            	{            
	            		printf("\nJoueur 2, essayez de trouver le numéro caché: ");
	            		scanf("%d",&choix_joueur);
	            		plus_moins(choix_joueur,valeur_a_trouver);
            
	            		if(choix_joueur!=valeur_a_trouver)
	            			essaie = essaie - 1;
            
	            	}while(choix_joueur!=valeur_a_trouver && essaie>0);
                    score_j2 = score_j2 + essaie;
            
                    printf("\nJoueur 2, Entrer le nombre d'essaie maximum pour le Joueur 1 (au moins 10): ");
	            	scanf("%d",&essaie);
            
                    if(essaie<10)
                    {
                        printf("La valeur minimal est 10");
                        return 1;
                    }
            
                    srand(time(NULL));
                    valeur_a_trouver = rand() % 100 + 1;
            
                    do
                    {
                        printf("\nJoueur 1, essayez de trouver le numéro caché: ");
	            		scanf("%d",&choix_joueur);
	            		plus_moins(choix_joueur,valeur_a_trouver);
            
	            		if(choix_joueur!=valeur_a_trouver)
	            			essaie = essaie - 1;
                    }while(choix_joueur!=valeur_a_trouver && essaie>0);
                    score_j1 = score_j1 + essaie;
            
                    tour = tour - 1;
                }while(tour>0);
            
                printf("\nScore du Joueur 1 : %d",score_j1);
	            printf("\nScore du Joueur 2 : %d",score_j2);
            
	            if(score_j1>score_j2)
	            	printf("\nLe Joueur 1 a gagné!\n");
                    
	            if(score_j1<score_j2)
	            	printf("\nLe Joueur 2 a gagné!\n");
            
	            if(score_j1==score_j2)
                    printf("\nMatch Nul\n");

        default:
            printf("Error: Entrer 1 ou 2");
            return 1;
    }

        return 0;
}