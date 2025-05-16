/*************************************************************************
                           presentation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <presentation> (fichier presentation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "presentation.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type presentation::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

#include <iomanip> // For text formatting

void presentation::Menu_principal ( )
// Algorithme :
//
{
    int choix;
    do
    {
        cout << "\033[1;34m|============================================|\033[0m\n";
        cout << "\033[1;34m|          Menu Principal AirWatcher         |\033[0m\n";
        cout << "\033[1;34m|============================================|\033[0m\n";
        cout << "\033[1;32m|[1] -------- Analyse de données ------------|\033[0m\n";
        cout << "\033[1;32m|[2] -------- Statistiques ------------------|\033[0m\n";
        cout << "\033[1;32m|[3] -------- Points utilisateurs -----------|\033[0m\n";
        cout << "\033[1;32m|[4] -------- Administration ----------------|\033[0m\n";
        cout << "\033[1;31m|[5] -------- Quitter -----------------------|\033[0m\n";
        cout << "\033[1;34m|============================================|\033[0m\n";
        cout << "Veuillez choisir une valeur entre 1 et 5 : "<< endl;

        cin >> choix;

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
                Menu_administration();
                break;
            case 5:
                cout << "\033[1;31mAu revoir !\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
                break;
        }
    } while (choix != 5);
}

void presentation::Menu_analyse ( )
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
        cout << "\033[1;31m|[4] -------- Retour au menu principal -------------|\033[0m\n";
        cout << "\033[1;34m|===================================================|\033[0m\n";
        cout << "Veuillez choisir une valeur entre 1 et 4 : " << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
                break;
        }
    } while (choix != 4);
}

void presentation::Menu_statistiques ( )
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
        cout << "\033[1;31m|[3] ---- Retour au menu principal -----------------|\033[0m\n";
        cout << "\033[1;34m|===================================================|\033[0m\n";
        cout << "Veuillez choisir une valeur entre 1 et 3 : " << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m"<< endl;
                break;
        }
    } while (choix != 3);
}

void presentation::Menu_points_utilisateurs ( )
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
        cout << "\033[1;31m|[2] ---- Retour au menu principal -----------------|\033[0m\n";
        cout << "\033[1;34m|===================================================|\033[0m\n";
        cout << "Veuillez choisir une valeur entre 1 et 2 : " << endl;

        cin >> choix;

        switch(choix)
        {
            case 1:
                break;
            case 2:
                cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
                break;
        }
    } while (choix != 2);
}

void presentation::Menu_administration ( )
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
        cout << "\033[1;31m|[4] ---- Retour au menu principal -----------------|\033[0m\n";
        cout << "\033[1;34m|===================================================|\033[0m\n";
        cout << "Veuillez choisir une valeur entre 1 et 4 : " << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "\033[1;31mRetour au menu principal.\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mChoix invalide, veuillez réessayer.\033[0m" << endl;
                break;
        }
    } while (choix != 4);
}


//------------------------------------------------- Surcharge d'opérateurs
presentation & presentation::operator = ( const presentation & unpresentation )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
presentation::presentation ( const presentation & unpresentation )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <presentation>" << endl;
#endif
} //----- Fin de presentation (constructeur de copie)


presentation::presentation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <presentation>" << endl;
#endif
} //----- Fin de presentation


presentation::~presentation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <presentation>" << endl;
#endif
} //----- Fin de ~presentation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

