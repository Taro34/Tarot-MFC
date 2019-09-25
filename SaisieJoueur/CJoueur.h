#pragma once
#include "stdafx.h"
#include "string"
using namespace std;
	
class CJoueur
{
private:
	string nom;
	int score;

public:
	string lireNom();
	int lireScore();
	int majScore(int);
	CJoueur(string nom, int score = 0);

};
