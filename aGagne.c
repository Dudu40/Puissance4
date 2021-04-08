/*!
\file aGagne.c
\author Ducasse Quentin <ducasseque@eisti.eu>
\date 14 Novembre 2019
\brief 
*/

#include "aGagne.h"

/*!
	\fn int conditionVerticale(int ttint_plateau[N][M],int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Verifie si le joueur a gagne en colonne
 	\param ttint_plateau
 	\param int_joueur
 	\return 1 si on verifie la colonne 0 sinon
*/

int conditionVerticale(int ttint_plateau[N][M],int int_joueur){

	// compteur de pion
	int compteur;
	// coordonee y du pion joué
	int y;
	// coordonne x du pion joué
	int x;
	// coordonnée non fixe de la case de la colonne
	int val;

	compteur=0;
	val=0;
	x=coordX;
	y=coordY;


		
	// parcourt le coté du bas de la colonne a partir du pion joué
	while ((ttint_plateau[y-val][x]==int_joueur) && (y-val<N) && (x<M) && (y-val>=0) && (x>=0)){
		compteur++;
		val++;
	}

	val=1;

	// parcourt le coté du haut de la colonne a partir du pion joué
	while ((ttint_plateau[y+val][x]==int_joueur) && (y+val<N) && (x<M) && (y+val>=0) && (x>=0)){
		compteur++;
		val++;
	}

	if (compteur>=4){
		return(1);
	

	}
	else{
		return(0);
	}

}

/*!
	\fn int conditionHorizontale(int ttint_plateau[N][M],int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Verifie si le joueur a gagne en ligne
 	\param ttint_plateau
 	\param int_joueur
 	\return un boolean : 1 si la colonne est gagnee 0 sinon
*/

int conditionHorizontale(int ttint_plateau[N][M],int int_joueur){
	// compteur de pion
	int compteur;
	// coordonee y du pion joué
	int y;
	// coordonne x du pion joué
	int x;
	// coordonnée non fixe de la case de la colonne
	int val;

	compteur=0;
	val=0;
	x=coordX;
	y=coordY;
	
	// parcourt le coté de gauche de la ligne a partir du pion joué
	while ((ttint_plateau[y][x-val]==int_joueur) && (x-val<M) && (y<N) && (x-val>=0) && (y>=0)){
		compteur++;
		val++;
	}

	val=1;

	// parcourt le coté de droite de la colonne a partir du pion joué
	while ((ttint_plateau[y][x+val]==int_joueur) && (x+val<M) && (y<N) && (x+val>=0) && (y>=0)){
		compteur++;
		val++;
	}

	if (compteur>=4){
		return(1);
	

	}
	else{
		return(0);
	}

}

/*!
	\fn int conditionDiagonaleBas(int ttint_plateau[N][M],int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Verifie si le joueur a gagne la diagonale bas
 	\param ttint_plateau
 	\param int_joueur
 	\return un boolean : 1 si la colonne est gagnee 0 sinon
*/

int conditionDiagonaleBas(int ttint_plateau[N][M],int int_joueur){

	// compteur de pion
	int compteur;
	// coordonee y du pion joué
	int y;
	// coordonne x du pion joué
	int x;
	// coordonnée non fixe de la case de la colonne
	int val;
	compteur=0;
	val=0;
	x=coordX;
	y=coordY;
	
	
	// parcourt le coté du bas de la diagonale 2 a partir du pion joué
	while ((ttint_plateau[y-val][x-val]==int_joueur) && (x-val<M) && (y-val<N) && (x-val>=0) && (y-val>=0)){
		compteur++;
		val++;
	}

	val=1;

	// parcour le coté du haut de la diagonale 2 a partir du pion joué<
	while ((ttint_plateau[y+val][x+val]==int_joueur) && (x+val<M) && (y+val<N) && (x+val>=0) && (y+val>=0)){
		compteur++;
		val++;
	}

	if (compteur>=4){ 
		return(1);
	

	}
	else{
		return(0);
	}

}

/*!
	\fn int conditionDiagonaleHaut(int ttint_plateau[N][M],int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Verifie si le joueur a gagne la diagoanle du haut
 	\param ttint_plateau
 	\param int_joueur
 	\return 1 si la colonne est gagnee 0 sinon
*/

int conditionDiagonaleHaut(int ttint_plateau[N][M],int int_joueur){

	// compteur de pion
	int compteur;
	// coordonee y du pion joué
	int y;
	// coordonne x du pion joué
	int x;
	// coordonnée non fixe de la case de la colonne
	int val;

	compteur=0;
	val=0;
	x=coordX;
	y=coordY;
	
	
	// parcour le coté du haut de la diagonale 1
	while ((ttint_plateau[y-val][x+val]==int_joueur) && (x+val<M) && (y-val<N) && (x+val>=0) && (y-val>=0)){
		compteur++;
		val++;
	}

	val=1;

	// parcour le coté du bas de la diagonale 1
	while ((ttint_plateau[y+val][x-val]==int_joueur) && (x-val<M) && (y+val<N) && (x-val>=0) && (y+val>=0)){
		compteur++;
		val++;
	}

	// si le compteur est egal a 4
	if (compteur>=4){
		return(1);
	

	}
	else{
		return(0);
	}

}

/*!
	\fn int aGagne(int ttint_plateau[N][M],int int_joueur)
 	\author Ducasse Quentin <ducasseque@eisti.eu>
 	\version 0.1
 	\date 14 Novembre 2019
	\brief Verifie si le joueur a gagne la partie
 	\param ttint_plateau
 	\param int_joueur
 	\return 1 si le joueur a gagne la partie 0 sinon
*/

int aGagne(int ttint_plateau[N][M],int int_joueur){
int val=0;
	
	// si le joueur a gagné
	if ((conditionVerticale(ttint_plateau,int_joueur)==1) || (conditionHorizontale(ttint_plateau,int_joueur)==1) || (conditionDiagonaleBas(ttint_plateau,int_joueur)==1) || (conditionDiagonaleHaut(ttint_plateau,int_joueur)==1)){
		val=int_joueur;
	}
	// sinon
	else{

		for(int i=0;i<M;i++){
			// si on peut jouer
			if(ttint_plateau[0][i]==-1){
					val=-1;
				}
			// sinon la valeur reste egale a 0
		}
	}

	return(val);
}