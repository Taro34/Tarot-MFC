#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "CDonne.h"


CDonne::CDonne()
{
}


CDonne::CDonne(CJoueur* leDonneur)
{
	this->leDonneur = leDonneur;

}

void CDonne::setPreneur(CJoueur * preneur)
{
	lePreneur = preneur;
}
void CDonne::setDefenseurs(CJoueur * defenseur[])
{
	for (int i = 0; i < 3; i++)
	{
		lesDefenseurs[i] = defenseur[i];
	}
}
void CDonne::setTypeContrat(Contrat typeContrat)
{
	this->typeContrat = typeContrat;
}
void CDonne::setPoint(int points, int nbBouts)
{
	this->points = points;
	this->nbBouts = nbBouts;
}
void CDonne::setPoingnee(Poignee typePoingnee)
{
	this->typePoignee = typePoignee;
}
void CDonne::setCampPetit(Camp campPetitAuBout)
{
	this->campPetitAuBout = campPetitAuBout;
}
void CDonne::calculpoints()
{
	switch (nbBouts)
	{
	case 0:
		nbpoint_a_faire = 56;
		break;
	case 1:
		nbpoint_a_faire = 51;
		break;
	case 2:
		nbpoint_a_faire = 41;
		break;
	case 3:
		nbpoint_a_faire = 36;
		break;
	}
	switch (typeContrat)
	{
	case prise:
		coef_contrat = 1;
		break;
	case garde:
		coef_contrat = 2;
		break;
	case gardeSans:
		coef_contrat = 4;
		break;
	case GardeContre:
		coef_contrat = 6;
		break;
	}
	switch (typePoignee)
	{
	case Sans:
		pointPoignee = 0;
		break;
	case Simple:
		pointPoignee = 20;
		break;
	case Double:
		pointPoignee = 30;
		break;
	case Triple:
		pointPoignee = 40;
		break;
	default:
		break;
	}
	nbpoint_en_plus = points - nbpoint_a_faire;
	if (nbpoint_en_plus >= 0)
		nbPoints = (25 + nbpoint_en_plus) * coef_contrat + pointPoignee;
	else
		nbPoints = (-25 + nbpoint_en_plus) * coef_contrat - pointPoignee;
	switch (campPetitAuBout)
	{
	case preneur:
		lePreneur->majScore(10);
		break;
	case personne:
		break;
	case defenseur:
		for (int i = 0; i < 3; i++)
			lesDefenseurs[i]->majScore(10);
		break;
	default:
		break;
	}
	cout << "point : ";
	cout << nbPoints;
	cout << "\n";
	lePreneur->majScore(nbPoints * 3);
	for (int i = 0; i < 3; i++)
		lesDefenseurs[i]->majScore(-nbPoints);
	
}

