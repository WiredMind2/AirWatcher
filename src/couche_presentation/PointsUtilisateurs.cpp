#include <iostream>
#include "../couche_metier/User.h"
using namespace std;


void consulter_points(){
    unsigned int userID;
    cout << "Entrez l'ID de l'utilisateur dont vous souhaitez consulter les points: ";
    cin >> userID;
    User user(userID); // Création d'un objet utilisateur avec l'ID fourni
    std::cout << "Points de l'utilisateur " << userID << ": " << user.getPoints() << std::endl;
}
