/*************************************************************************
PointsUtilisateurs.cpp  -  Affiche les points d'un utilisateur à partir de son ID, en utilisant la classe User.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include "../couche_metier/User.h"
using namespace std;

//----------------------------------------------------------------- FONCTIONS
// Fonction : consulter_points
// Algorithme :
// Demande l'ID d'un utilisateur, crée un objet User correspondant et affiche ses points.
void consulter_points(){
    unsigned int userID;
    cout << "Entrez l'ID de l'utilisateur dont vous souhaitez consulter les points: ";
    cin >> userID;
    User user(userID); // Création d'un objet utilisateur avec l'ID fourni
    std::cout << "Points de l'utilisateur " << userID << ": " << user.getPoints() << std::endl;
}
