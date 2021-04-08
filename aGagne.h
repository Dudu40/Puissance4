

#ifndef __AGAGNE_H_
#define __AGAGNE_H_
#define N 6
#define M 7
int coordX;
int coordY; 

int conditionVerticale(int ttint_plateau[N][M],int int_joueur);

int conditionHorizontale(int ttint_plateau[N][M],int int_joueur);

int conditionDiagonaleBas(int ttint_plateau[N][M],int int_joueur);

int conditionDiagonaleHaut(int ttint_plateau[N][M],int int_joueur);

int aGagne(int ttint_plateau[N][M],int int_joueur);
#endif