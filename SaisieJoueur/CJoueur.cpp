#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "CJoueur.h"


using namespace std;

string CJoueur::lireNom()
{
	return nom;
}

int CJoueur::lireScore()
{
	return score;
}

int CJoueur::majScore(int nbPoints)
{
	score = score + nbPoints;
	return score;
}

CJoueur::CJoueur(string nom, int score)
{
	this->nom = nom;
	this->score = score;

}

