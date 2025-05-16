/*************************************************************************
						   Presentation  -  description
							 -------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Presentation> (fichier Presentation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "presentation.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Presentation::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

#include <iomanip> // For text formatting
#include "statistiques.h"
#include "analyse.h"

void Presentation::Menu_principal ( )
// Algorithme :
//
{
	//choix de l'utilisateur
	string userType;
	do
	{
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "\033[1;34m|          Sélection du type d'utilisateur   |\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "\033[1;32m|[1] -------- Agence gouvernementale --------|\033[0m\n";
		cout << "\033[1;32m|[2] -------- Individu ----------------------|\033[0m\n";
		cout << "\033[1;32m|[3] -------- Fournisseur -------------------|\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: "<< endl;

		int choix;
		while (!(cin >> choix))
        {
            cout << "Entrée invalide. Veuillez entrer un nombre entier.\n\n";
            cin.clear();                // Réinitialise le statut d'erreur
            cin.ignore(1000, '\n');     // Ignore les caractères restants dans le flux
        }

		switch (choix)
		{
			case 1:
				userType = "1";
				break;
			case 2:
				userType = "2";
				break;
			case 3:
				userType = "3";
				break;
			default:
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				break;
		}
	} while (userType.empty());

	cout << "\033[1;32mVous avez sélectionné : " << userType << "\033[0m" << endl;

	// Affichage du menu principal
	int choix;
	do
	{
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "\033[1;34m|          Menu Principal AirWatcher         |\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "\033[1;32m|[1] -------- Analyse de données ------------|\033[0m\n";
		cout << "\033[1;32m|[2] -------- Statistiques ------------------|\033[0m\n";
		cout << "\033[1;32m|[3] -------- Points utilisateurs -----------|\033[0m\n";
		if (userType == "1")
		{
			cout << "\033[1;32m|[4] -------- Administration ----------------|\033[0m\n";
		}
		cout << "\033[1;31m|[0] -------- Quitter -----------------------|\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: "<< endl;

		while (!(cin >> choix))
        {
            cout << "Entrée invalide. Veuillez entrer un nombre entier.\n\n";
            cin.clear();                // Réinitialise le statut d'erreur
            cin.ignore(1000, '\n');     // Ignore les caractères restants dans le flux
        }

		switch (choix)
		{
			case 1:
				Menu_analyse();
				break;
			case 2:
				Menu_statistiques();
				break;
			case 3:
				Menu_points_utilisateurs();
				break;
			case 4:
				if (userType == "1"){
					Menu_administration();
				}
				else{
					cout << "\033[1;31mAccès refusé. Vous n'êtes pas une agence gouvernementale.\033[0m" << endl;
				}
				break;
			case 0:
				cout << "\033[1;31mAu revoir !\033[0m" << endl;
				break;
			default:
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				break;
		}
	} while (choix != 0);
}

void Presentation::Menu_analyse ( )
// Algorithme :
//
{
	int choix;
	do
	{
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;34m|               Menu Analyse de Données             |\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;32m|[1] -------- Analyse des données des capteurs------|\033[0m\n";
		cout << "\033[1;32m|[2] -------- Identifier capteurs non fiables ------|\033[0m\n";
		cout << "\033[1;32m|[3] -------- Analyser impact des purificateurs-----|\033[0m\n";
		cout << "\033[1;31m|[0] -------- Retour au menu principal -------------|\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: "<< endl;

		while (!(cin >> choix))
        {
            cout << "Entrée invalide. Veuillez entrer un nombre entier.\n\n";
            cin.clear();                // Réinitialise le statut d'erreur
            cin.ignore(1000, '\n');     // Ignore les caractères restants dans le flux
        }

		switch (choix)
		{
			case 1:
				analyse_donnees_capteurs();
				break;
			case 2:
				identifier_capteurs_non_fiables();
				break;
			case 3:
				analyser_impact_purificateurs();
				break;
			case 0:
				cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
				break;
			default:
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				break;
		}
	} while (choix != 0);
}

void Presentation::Menu_statistiques ( )
// Algorithme :
//
{
	int choix;
	do
	{
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;34m|               Menu Statistiques                   |\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;32m|[1] ---- Qualité moyenne de l'air par zone --------|\033[0m\n";
		cout << "\033[1;32m|[2] ---- Qualité moyenne de l'air par point -------|\033[0m\n";
		cout << "\033[1;32m|[3] ---- Classer capteurs similaires --------------|\033[0m\n";
		cout << "\033[1;31m|[0] ---- Retour au menu principal -----------------|\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: "<< endl;

		while (!(cin >> choix))
        {
            cout << "Entrée invalide. Veuillez entrer un nombre entier.\n\n";
            cin.clear();                // Réinitialise le statut d'erreur
            cin.ignore(1000, '\n');     // Ignore les caractères restants dans le flux
        }

		switch (choix)
		{
			case 1:
				calculQualiteAirZone();
				break;
			case 2:
				calculQualiteAirPos();
				break;
			case 3:
				classerCapteursSimilaires();
				break;
			case 0:
				cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
				break;
			default:
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m"<< endl;
				break;
		}
	} while (choix != 0);
}

void Presentation::Menu_points_utilisateurs ( )
// Algorithme :
//
{
	int choix;
	do
	{
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;34m|           Menu Points Utilisateurs                |\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;32m|[1] ---- Consulter les points d'un utilisateur ----|\033[0m\n";
		cout << "\033[1;31m|[0] ---- Retour au menu principal -----------------|\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: "<< endl;

		while (!(cin >> choix))
        {
            cout << "Entrée invalide. Veuillez entrer un nombre entier.\n\n";
            cin.clear();                // Réinitialise le statut d'erreur
            cin.ignore(1000, '\n');     // Ignore les caractères restants dans le flux
        }

		switch(choix)
		{
			case 1:
				break;
			case 0:
				cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
				break;
			default:
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				break;
		}
	} while (choix != 0);
}

void Presentation::Menu_administration ( )
// Algorithme :
//
{
	int choix;
	do
	{
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;34m|               Menu Administration                 |\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "\033[1;32m|[1] ---- Consulter capteurs défaillants -----------|\033[0m\n";
		cout << "\033[1;32m|[2] ---- Marquer un capteur comme non fiable ------|\033[0m\n";
		cout << "\033[1;32m|[3] ---- Marquer un utilisateur comme malicieux ---|\033[0m\n";
		cout << "\033[1;31m|[0] ---- Retour au menu principal -----------------|\033[0m\n";
		cout << "\033[1;34m|===================================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: "<< endl;

		while (!(cin >> choix))
        {
            cout << "Entrée invalide. Veuillez entrer un nombre entier.\n\n";
            cin.clear();                // Réinitialise le statut d'erreur
            cin.ignore(1000, '\n');     // Ignore les caractères restants dans le flux
        }

		switch (choix)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
				break;
			default:
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				break;
		}
	} while (choix != 0);
}

//-------------------------------------------- Constructeurs - destructeur
Presentation::Presentation ( const Presentation & unPresentation )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Presentation>" << endl;
#endif
} //----- Fin de Presentation (constructeur de copie)


Presentation::Presentation ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Presentation>" << endl;
#endif
} //----- Fin de Presentation


Presentation::~Presentation ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Presentation>" << endl;
#endif
} //----- Fin de ~Presentation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

