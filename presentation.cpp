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

void presentation::Menu_principal ( )
// Algorithme :
//
{
        cout << "|============================================|\n";
        cout << "|          Menu Principal AirWatcher         |\n";
        cout << "|============================================|\n";
        cout << "|[1] -------- Analyse de données ------------|\n";
        cout << "|[2] -------- Statistiques ------------------|\n";
        cout << "|[3] -------- Points utilisateurs -----------|\n";
        cout << "|[4] -------- Administration ----------------|\n";
        cout << "|[5] -------- Quitter -----------------------|\n";
        cout << "|============================================|\n";
        cout << "Veuillez choisir une valeur entre 1 et 5 : "<< endl;

        int choix;
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
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer.";
                break;
        }
}

void presentation::Menu_analyse ( )
// Algorithme :
//
{

}

void presentation::Menu_statistiques ( )
// Algorithme :
//
{

}

void presentation::Menu_points_utilisateurs ( )
// Algorithme :
//
{

}

void presentation::Menu_administration ( )
// Algorithme :
//
{

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

