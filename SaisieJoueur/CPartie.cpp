#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "CPartie.h"
using namespace std;

CPartie::CPartie(CJoueur* lesJoueurs[]) 
{
	for (int i = 0; i < 4; i++)
	{
		this->lesJoueurs[i] = lesJoueurs[i];
	}
	nbDonne = 0;
	lesDonnes = new CDonne*[100];

}
CPartie::~CPartie()
{
	for (int i = 0; i < nbDonne; i++)
		delete lesDonnes[i];
	delete[] lesDonnes;
}

void CPartie::creerDonnes(CJoueur * leDonneur)
{
	lesDonnes[nbDonne] = new CDonne(leDonneur);
	nbDonne++;
}


void CPartie::setPreneur(CJoueur * lePreneur)
{

	lesDonnes[nbDonne - 1]->setPreneur(lePreneur); // set du preneur de la donne
	CJoueur* lesDefenseur[3];
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		if (lesJoueurs[i] != lePreneur)
		{
			lesDefenseur[k] = lesJoueurs[i];
			k++;
		}
	}
	lesDonnes[nbDonne - 1]->setDefenseurs(lesDefenseur);
}

void CPartie::setPoint(int points, int nbBouts)
{
	lesDonnes[nbDonne - 1]->setPoint(points, nbBouts);
}

void CPartie::setPoingnee(Poignee typePoingnee)
{
	lesDonnes[nbDonne - 1]->setPoingnee(typePoingnee);
}

void CPartie::setCampPetit(Camp campPetitAuBout)
{
	lesDonnes[nbDonne - 1]->setCampPetit(campPetitAuBout);
}

void CPartie::calculerDonne()
{
	lesDonnes[nbDonne - 1]->calculpoints();
}

void CPartie::setTypeContrat(Contrat typeContrat)
{
	lesDonnes[nbDonne - 1]->setTypeContrat(typeContrat);
}
