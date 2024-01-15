#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen/screen.h"
#include "common/common.h"

static char *ecran = NULL; // pointeur sur l'ecran
static int nbLig = 0;  // nombre de lignes à l'ecran
static nbCol = 0;  // nombre de colonnes à l'ecran
static int nlc = 0; // numero de ligne du crayon
static ncc = 0;  //numero de colonnes du crayon
static int couleur = 0;  //couleur du crayon



void initialiserEcran(int nl, int nc)
{
	nbLig = nl;
	nbCol = nc;

	ecran = malloc(nbLig * nbCol * sizeof(ecran));
	if (NULL == ecran)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
		return 1;
	}
	effacerEcran();
}

void crayonEn(int nl, int nc)
{
	nlc = nl;
	ncc = nc;
}

void couleurCrayon(int c)
{
	if (c > 15)
	{
		c = c % 16;
		couleur = c;
	}
}

// ecrire un caractere en fonction de la couleur
void ecrirePixel(int nl, int nc)
{
	static char* tabCoul = "123456789ABCDE";
	if ((nl > 0) && (nl < nbLig) && (nc > 0) && (nc < nbCol))
	{
		ecran[nl * nbCol * nc] = tabCoul[couleur];
	}
}

//avancer dans la direction d de lg pixels
void avancer(int d, int n)
{
	int i = 0;
	switch (d) {
	case DROITE:
		for (i = ncc; i < ncc + n; i++) ecrirePixel(nlc, i);
		ncc += n - 1;
		break;
	case HAUT:
		for (i = nlc; i > nlc - n; i--) ecrirePixel(i, ncc);
		nlc += -n + 1;
		break;
	case GAUCHE:
		for (i = ncc; i > ncc - n; i--) ecrirePixel(nlc, i);
		ncc += -n + 1;
		break;
	case BAS:
		for (i = nlc; i < nlc + n; i++) ecrirePixel(i, ncc);
		nlc += n - 1;
		break;
	}
}

//tracer un rectangle defini par 2 points csg cid
void rectangle(int xcsg, int ycsg, int xcid, int ycid)
{
	int longueur = xcid - xcsg + 1;
	int largeur = ycid - ycsg + 1;

	crayonEn(ycsg, xcsg);
	avancer(BAS, largeur);
	avancer(DROITE, longueur);
	avancer(HAUT, largeur);
	avancer(GAUCHE, longueur);
}

//ecrire un message à 