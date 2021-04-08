
/*!
\file puissance4.c
\author Ducasse Quentin <ducasseque@eisti.eu>
\date 14 Novembre 2019
\brief Initialise un tableau2D a zero
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aGagne.h"
#include <unistd.h>


/*!
	\fn void init (int ttint_plateau[N][M])
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Initialise un tableau2D a zero
 	\param ttint_plateau
*/


void init (int ttint_plateau[N][M]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			ttint_plateau[i][j]=-1;

		}
	}
}

/*!
	\fn void affichage(int ttint_plateau[N][M],int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief affiche une tableau passé en paramètre
 	\param ttint_plateau 
 	\param int_joueur
*/

// affiche la grille en fonction des valeurs de celle ci
void affichage(int ttint_plateau[N][M],int int_joueur){
		system("clear");
		printf("Au tour du joueur %d\n\n",int_joueur);
		printf("  ");
		

		for (int i=0;i<M;i++){
		printf("%d ",i+1);		
	}
	printf("\n");
	
	for(int i=0;i<N;i++){
		printf("%d",i+1);
		for(int j=0;j<M;j++){
			if (ttint_plateau[i][j]==1){
				printf("|X");
			}

			if (ttint_plateau[i][j]==2){
			printf("|O");
		}

		if (ttint_plateau[i][j]==-1){
			printf("| ");
		}

			if (j==M-1){
				printf("|");
			}

		}
		printf("\n");
	}
	printf("\n");
}


/*!
	\fn int colonneChoisie (int ttint_plateau[N][M])
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief sauvegarde la colonne choisie par l'utilisateur
 	\param ttint_plateau
 	\return x le numero de la colonne choisie
*/

int colonneChoisie (int ttint_plateau[N][M]){
	int x;
	int retour;
	char char_nul; 

	// tant que le numero de la colonne n'est pas valide on demande de saisir un entier
	do{	
		printf("Veuillez entrez le numéro de de votre case\n");
		retour=scanf("%d",&x);

		// tant que la valeur n'est pas un entier on demande de saisir un entier et on vide le buffer
		if (retour==0){

			while(retour==0){
				retour=scanf("%c",&char_nul);
				while(char_nul!='\n'){
					retour=scanf("%c",&char_nul);

		}
		printf("Veuillez saisir un entier !\n");
		retour=scanf("%d",&x);

		}


	}


	}while((x<1) || (x>M));

	

	return(x);

}


/*!
	\fn int jouer(int ttint_plateau[N][M],int int_x,int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief verifie si le joueur peut jouer
 	\param ttint_plateau 
 	\param int_joueur
 	\param int_x
 	\return 1 si on peut jouer 0 sinon
*/

int jouer(int ttint_plateau[N][M],int int_x,int int_joueur){
	// numero de la ligne
	int i;
	// on convertit le numero de la colonne pour que cela correponde au tableau
	int_x=int_x-1;
	i=0;

	// tant que la case est vide et que l'on respecte la limite du tableau
	// on descend de 1 case jusqu'à atteindre un pion
	while ((ttint_plateau[i][int_x]==-1) && (i<N) && (int_x<M) && (i>=0) && (int_x>=0)){
		i++;

		// on donne une valeur temporaire a la case de la grille vide pour ouvoir l'afficher
		// cela simule une chute du pion
		if (i != 0) {
			ttint_plateau[i-1][int_x] = int_joueur; 
		}
		// on redonne la valeur initiale après l'avoir affiché 
		if (i > 1) {
			ttint_plateau[i-2][int_x] = -1; 
		}
		usleep(50000);
		// on affiche la case en question
		affichage(ttint_plateau,int_joueur);

	}
	// si le pion est situé tout en haut de la grille on ne peut pas jouer 
	if (i==0){
		return(0);

	}
	// sinon on peut jouer et on place le pion du joueur sur la case vide au dessus du dernier pion 
	else{
		ttint_plateau[i-1][int_x]=int_joueur;
		// on sauvegarde les coordonnées du pion
		coordX=int_x;
		coordY=i-1;
		return(1);

	}
	
}

/*!
	\fn int changeJoueur(int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Change de joueur 
 	\param int_joueur 
 	\return 1 ou 2 selon le numero du joueur
*/



int changeJoueur(int int_joueur){

	// si le joueur est le joueur 1 ca passe au joueur 2 et inversement
	if (int_joueur==1){
			return(2);
		}
		else{
			return(1);
		}

}


/*!
	\fn void tourDejeu(int ttint_plateau[N][M])
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief lance le jeu jusqu'à ce qu'un joueur gagne
 	\param ttint_plateau la grille de jeu
*/


void tourDejeu(int ttint_plateau[N][M]){
	int int_joueur;
	int_joueur=1;
	
	// on intialise la grille

	init(ttint_plateau);

	//tant que personne a gagné
	while(aGagne(ttint_plateau,int_joueur)==-1){

	
		// on affiche le tour du joueur

		// on affiche le plateau
		affichage(ttint_plateau,int_joueur);
		
		// on lit la colonne
		int n=colonneChoisie(ttint_plateau);

		// si le plateau n'est pas complet
		if (jouer(ttint_plateau,n,int_joueur)==1){
			

  			
			
			// si un joueur a gagne afficher message de win

			if (aGagne(ttint_plateau,int_joueur)==int_joueur){
				affichage(ttint_plateau,int_joueur);
		
				printf("Le joueur %d a gagné la partie !\n",int_joueur);
			}else{

				// si il ya egalite afficher message egalite
				if (aGagne(ttint_plateau,int_joueur)==0){
					affichage(ttint_plateau,int_joueur);
			
					printf("Egalité\n");
				}
				// autre cas on change de joueur
				else{
					if (aGagne(ttint_plateau,int_joueur)==-1){
						int_joueur=changeJoueur(int_joueur);
						

					}
					
				}
			}
			
		}
		else{
			printf("opération impossible car la colonne est pleine\n");
			n=colonneChoisie(ttint_plateau);

		}
			
		
	}

}

/*!
	\fn int main(int argc, char** argv)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief fonction principale
 	\param argc
 	\param argv
 	\return 0
*/

int main(int argc, char** argv){
	int ttint_plateau[N][M];
	
// appel de la fonction
  tourDejeu(ttint_plateau);
  
  return(0);
}