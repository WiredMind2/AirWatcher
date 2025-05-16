/*************************************************************************
                           Individual  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Individual> (fichier Individual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Individual.h"

Individual::Individual(const string &id, int points) : User(id, points) {}
Individual::~Individual() {}