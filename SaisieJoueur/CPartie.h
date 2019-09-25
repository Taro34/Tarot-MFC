#pragma once
#include "stdafx.h"
#include "CJoueur.h"
#include "CDonne.h"

class CPartie
{  
	private:
		CDonne **lesDonnes;
		CJoueur *lesJoueurs[4];
		int nbDonne;
	public:
		CPartie(CJoueur* lesJoueurs[]);
		~CPartie();
		void creerDonnes(CJoueur* leDonneur);
		void setPreneur(CJoueur *lePreneur);
		void setTypeContrat(Contrat typeContrat);
		void setPoint(int points, int nbBouts);
		void setPoingnee(Poignee typePoingnee);
		void setCampPetit(Camp campPetitAuBout);
		void calculerDonne();
	
};