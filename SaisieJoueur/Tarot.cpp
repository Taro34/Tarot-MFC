#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "CDonne.h"
#include "CJoueur.h"
#include "CPartie.h"
#include "IHM.h"
using namespace std;

void main() {
	IHM ihm;

	ihm.saisirjoueur();
	ihm.creer_partie();
	ihm.saisie_contrat();
	ihm.lireScoreJoueur();
	
}





