#pragma once
#include "stdafx.h"
#include "CJoueur.h"

using namespace std;
enum Contrat { passe, prise, garde, gardeSans, GardeContre };
enum Camp { preneur, personne, defenseur };
enum Poignee { Sans, Simple, Double, Triple };
enum Chelem { sans, reussi, perdu, sansAnnonce };

class CDonne
{
private:
	Contrat typeContrat;
	Camp campPoignee;
	Camp campPetitAuBout;
	Chelem typeChelem;
	Poignee typePoignee;
	int nbPoints;
	int nbBouts;
	int points;
	int nbpoint_a_faire;
	int nbpoint_en_plus;
	int coef_contrat;
	int pointPoignee;
	CJoueur *leDonneur;
	CJoueur *lePreneur;
	CJoueur *lesDefenseurs[3];

public:
	CDonne();
	CDonne(CJoueur*);
	void setPreneur(CJoueur *);
	void setDefenseurs(CJoueur*[]);
	void setTypeContrat(Contrat typeContrat);
	void setPoint(int points, int nbBouts);
	void setPoingnee(Poignee typePoingnee);
	void setCampPetit(Camp campPetitAuBout);
	void calculpoints();
	};