/*************************************************************************
presentation.cpp  -  Fonctions de gestion de l'affichage, de l'interface utilisateur et de l'interaction avec l'utilisateur.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

// presentation.cpp - Fonctions de gestion de l'affichage et de l'interface utilisateur

//---------- Réalisation de la classe <Presentation> (fichier Presentation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "presentation.h"
#include "statistiques.h"
#include "analyse.h"
#include "PointsUtilisateurs.h"
#include "Administration.h"
#include "../couche_metier/User.h"

//----------------------------------------------------------------- FONCTIONS D'AFFICHAGE
// Chaque fonction gère une partie de l'affichage ou de l'interface utilisateur.

//--- Méthodes publiques

void Presentation::Menu_principal()
/**
 * @brief Affiche le menu principal de l'application AirWatcher et gère les interactions utilisateur.
 *
 * Cette méthode permet à l'utilisateur de sélectionner son type (Agence gouvernementale, Individu, ou Fournisseur),
 * puis d'accéder au menu principal correspondant. Les options disponibles dans le menu principal varient en fonction
 * du type d'utilisateur sélectionné. L'utilisateur peut naviguer entre différentes fonctionnalités ou quitter
 * l'application.
 *
 * @details
 * - Le menu de sélection du type d'utilisateur propose trois choix :
 *   1. Agence gouvernementale
 *   2. Individu
 *   3. Fournisseur
 * - Une fois le type d'utilisateur sélectionné, le menu principal propose les options suivantes :
 *   - Analyse de données
 *   - Statistiques
 *   - Points utilisateurs
 *   - Administration (uniquement pour les agences gouvernementales)
 *   - Quitter
 * - Les entrées invalides sont gérées avec des messages d'erreur et une demande de réessai.
 *
 * @note Les options spécifiques au menu principal sont conditionnées par le type d'utilisateur.
 *       Par exemple, l'option "Administration" est uniquement accessible aux agences gouvernementales.
 *
 * @warning L'utilisateur doit entrer un nombre entier valide pour naviguer dans les menus.
 */
{
	// choix de l'utilisateur
	unsigned char userType = 0;
	do
	{
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "\033[1;34m|          Sélection du type d'utilisateur   |\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "\033[1;32m|[1] -------- Agence gouvernementale --------|\033[0m\n";
		cout << "\033[1;32m|[2] -------- Individu ----------------------|\033[0m\n";
		cout << "\033[1;32m|[3] -------- Fournisseur -------------------|\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: " << endl;

		int choix;
		while (!(cin >> choix))
		{
			cout << "Entrée invalide. Veuillez entrer un nombre entier.\n";
			cin.clear();			// Réinitialise le statut d'erreur
			cin.ignore(1000, '\n'); // Ignore les caractères restants dans le flux
		}

		if (choix < 1 || choix > 3)
		{
			cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
			continue; // Redemande le choix
		}
		else
		{
			userType = choix;
			User::SetGlobalUserType(userType);
		}

	} while (userType == 0);

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
		if (userType != 3) // Fournisseur n'a pas accès aux points utilisateurs
		{
			cout << "\033[1;32m|[3] -------- Points utilisateurs -----------|\033[0m\n";
			if (userType == 1)
			{
				cout << "\033[1;32m|[4] -------- Administration ----------------|\033[0m\n";
			}
		}
		cout << "\033[1;31m|[0] -------- Quitter -----------------------|\033[0m\n";
		cout << "\033[1;34m|============================================|\033[0m\n";
		cout << "Veuillez choisir une valeur parmi celles proposées: " << endl;

		while (!(cin >> choix))
		{
			cout << "Entrée invalide. Veuillez entrer un nombre entier.\n";
			cin.clear();			// Réinitialise le statut d'erreur
			cin.ignore(1000, '\n'); // Ignore les caractères restants dans le flux
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
			if (userType == 3)
			{
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				continue; // Redemande le choix
			}
			Menu_points_utilisateurs();
			break;
		case 4:
			if (userType != 1)
			{
				cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
				continue; // Redemande le choix
			}
			Menu_administration();
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

void Presentation::Menu_analyse()
/**
 * @brief Affiche le menu d'analyse de données et gère les interactions utilisateur.
 *
 * Cette méthode affiche un menu interactif permettant à l'utilisateur de choisir parmi
 * différentes options d'analyse de données. Les options incluent :
 * - Analyse des données des capteurs.
 * - Identification des capteurs non fiables.
 * - Analyse de l'impact des purificateurs.
 *
 * L'utilisateur peut également revenir au menu principal en sélectionnant l'option correspondante.
 * La méthode gère les entrées invalides et invite l'utilisateur à réessayer en cas d'erreur.
 *
 * @note Cette méthode utilise une boucle do-while pour maintenir le menu actif jusqu'à ce que
 *       l'utilisateur choisisse de revenir au menu principal.
 */
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
		cout << "Veuillez choisir une valeur parmi celles proposées: " << endl;

		while (!(cin >> choix))
		{
			cout << "Entrée invalide. Veuillez entrer un nombre entier.\n";
			cin.clear();			// Réinitialise le statut d'erreur
			cin.ignore(1000, '\n'); // Ignore les caractères restants dans le flux
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

void Presentation::Menu_statistiques()
/**
 * @brief Affiche le menu des statistiques et gère les interactions utilisateur.
 *
 * Cette méthode affiche un menu permettant à l'utilisateur de choisir parmi plusieurs
 * options liées aux statistiques de qualité de l'air. Les options incluent :
 * - Calcul de la qualité moyenne de l'air par zone.
 * - Calcul de la qualité moyenne de l'air par point.
 * - Classement des capteurs similaires.
 *
 * L'utilisateur peut également choisir de revenir au menu principal.
 *
 * @details
 * - Le menu est affiché dans une boucle do-while, permettant à l'utilisateur de faire
 *   plusieurs choix jusqu'à ce qu'il décide de revenir au menu principal.
 * - Les entrées utilisateur sont validées pour s'assurer qu'elles sont des entiers.
 * - Les choix invalides sont gérés avec un message d'erreur.
 *
 * @note Les fonctions suivantes sont appelées en fonction du choix de l'utilisateur :
 * - `calculQualiteAirZone()`: Calcule la qualité moyenne de l'air par zone.
 * - `calculQualiteAirPos()`: Calcule la qualité moyenne de l'air par point.
 * - `classerCapteursSimilaires()`: Classe les capteurs similaires.
 *
 * @warning Assurez-vous que les fonctions appelées dans les cases du switch sont correctement
 * implémentées et gèrent leurs propres erreurs.
 */
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
		cout << "Veuillez choisir une valeur parmi celles proposées: " << endl;

		while (!(cin >> choix))
		{
			cout << "Entrée invalide. Veuillez entrer un nombre entier.\n";
			cin.clear();			// Réinitialise le statut d'erreur
			cin.ignore(1000, '\n'); // Ignore les caractères restants dans le flux
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
			cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
		}
	} while (choix != 0);
}

void Presentation::Menu_points_utilisateurs()
/**
 * @brief Displays the "Menu Points Utilisateurs" interface and handles user input.
 *
 * This function presents a menu to the user with options to either consult the points
 * of a specific user or return to the main menu. It validates user input to ensure
 * it is an integer and provides feedback for invalid choices. The menu remains active
 * until the user chooses to return to the main menu.
 *
 * Menu options:
 * - [1] Consult the points of a user.
 * - [0] Return to the main menu.
 *
 * Input validation:
 * - Ensures the user enters a valid integer.
 * - Prompts the user to re-enter a value if the input is invalid.
 *
 * @note The actual functionality for consulting user points is not implemented in this function.
 */
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
		cout << "Veuillez choisir une valeur parmi celles proposées: " << endl;

		while (!(cin >> choix))
		{
			cout << "Entrée invalide. Veuillez entrer un nombre entier.\n";
			cin.clear();			// Réinitialise le statut d'erreur
			cin.ignore(1000, '\n'); // Ignore les caractères restants dans le flux
		}

		switch (choix)
		{
		case 1:
			consulter_points();
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

void Presentation::Menu_administration()
/**
 * @brief Displays the administration menu and handles user input for various administrative actions.
 *
 * This function provides a menu interface for administrative tasks, such as:
 * - Viewing faulty sensors.
 * - Marking a sensor as unreliable.
 * - Marking a user as malicious.
 *
 * The menu is displayed in a loop until the user chooses to return to the main menu.
 * Input validation is performed to ensure the user enters a valid integer choice.
 *
 * @note The actual functionality for each menu option is not implemented in this function.
 */
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
		cout << "Veuillez choisir une valeur parmi celles proposées: " << endl;

		while (!(cin >> choix))
		{
			cout << "Entrée invalide. Veuillez entrer un nombre entier.\n";
			cin.clear();			// Réinitialise le statut d'erreur
			cin.ignore(1000, '\n'); // Ignore les caractères restants dans le flux
		}

		switch (choix)
		{
		case 1:
			consulter_capteurs_defaillants();
			break;
		case 2:
			marquer_capteur_non_fiable();
			break;
		case 3:
			marquer_user_malicieux();
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

Presentation::Presentation(const Presentation &unPresentation)
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Presentation>" << endl;
#endif
} //----- Fin de Presentation (constructeur de copie)

Presentation::Presentation()
{
#ifdef MAP
	cout << "Appel au constructeur de <Presentation>" << endl;
#endif
} //----- Fin de Presentation

Presentation::~Presentation()
{
#ifdef MAP
	cout << "Appel au destructeur de <Presentation>" << endl;
#endif
} //----- Fin de ~Presentation

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
