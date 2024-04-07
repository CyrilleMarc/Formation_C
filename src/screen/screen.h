#pragma once

#define NOIR 0
#define BLANC 15

#define GAUCHE 1
#define DROITE 2
#define HAUT 3
#define BAS 4

void initialiserEcran(int nl, int nc);
void crayonEn(int nl, int nc);
void couleurCrayon(int c);
void ecrirePixel(int nl, int nc);
void avancer(int d, int lg);
void rectangle(int xcsg, int ycsg, int xcig, int ycid);
void ecrireMessage(int nl, int nc, char *message);
void afficherEcran();
void effacerEcran();
void detruireEcran();
void sauverEcran(char *nom);