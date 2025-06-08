/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GouvAgency> (fichier GouvAgency.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GouvAgency.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void GouvAgency::classifyUnreliable(User &user)
// Algorithme :
//
{
} //----- Fin de classifyUnreliable

void GouvAgency::classifyReliable(User &user)
// Algorithme :
//
{
} //----- Fin de classifyReliable

list<User> GouvAgency::getUsers()
// Algorithme :
//
{
    list<User> users;
    return users;
} //----- Fin de getUsers

list<User> GouvAgency::findUnreliable()
// Algorithme :
//
{
    list<User> unreliableUsers;
    return unreliableUsers;
} //----- Fin de findUnreliable
