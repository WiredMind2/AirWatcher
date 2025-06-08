#include <iostream>
#include "processing.h"
#include <vector>
#include "../couche_acces_aux_donnees/CSVHandler.h"
#include "../couche_presentation/analyse.h"

using namespace std;

void consulter_capteurs_defaillants()
{
    double seuil_limite, radius;
    int k;

    cout << "Entrez le rayon de la zone (en degrés): ";
    cin >> radius;
    cout << "Entrez le seuil choisi : ";
    cin >> seuil_limite;
    cout << "Entrez le nombre de voisins (k): ";
    cin >> k;

    time_t start = demander_date("début");
    time_t stop = demander_date("fin");

    vector<const Sensor *> capteurs_defaillants = AirQualityProcessor::TrouverCapteursDetournes(radius, seuil_limite, k, start, stop);
    for (const auto &sensor : capteurs_defaillants)
    {
        cout << "Le capteur" << sensor->GetSensorID() << "est défaillant." << "\n";
    }
}

void marquer_capteur_non_fiable()
{

    // Récupérer la liste des non fiables
    consulter_capteurs_defaillants();

    // Choisir un capteur dans cette liste à marquer comme non fiable
    int sensor_id;
    cout << "Veuillez entrer l'identifiant du capteur à marquer comme non fiable"; // Ajouter gestion de si dans la liste ou non
    cin >> sensor_id;

    // Récupérer le capteur associé à l'id
    Sensor* capteur_non_fiable = CSVHandler::getSensor(sensor_id);

    // TO DO : Marquer le capteur choisi comme non fiable (mettre ses mesures à -1 ? méthode dans GouvAgency?)
    cout << "Le capteur n°" << capteur_non_fiable->GetSensorID() << "a été marqué comme non fiable" << "\n";
}

void marquer_user_malicieux()
{
    int user_id;
    cout << "Veuillez entrer l'identifiant de l'utilisateur à signaler";
    cin >> user_id;

    // Récupérer l'user associé à l'id : chercher dans la liste des unreliable users donnée par findUnreliable
    //User user_malicieux = CSVHandler::getUser(user_id);

    // Le classer comme malicieux
    //GouvAgency(5).classifyUnreliable(user_malicieux); // TO DO : revoir avec le bon id, méthodes GouvAgency en static ?
    cout << "L'utilisateur" << user_id << "a été signalé. Il ne pourra plus accumuler de points" << "\n";
}