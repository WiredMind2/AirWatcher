/*************************************************************************
main.cpp  -  Point d'entrée principal de l'application AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include "couche_presentation/presentation.h"
#include "test/tests.h"
#include "couche_acces_aux_donnees/CSVHandler.h"
using namespace std;

//----------------------------------------------------------------- FONCTIONS
//----------------------------- Point d'entrée principal
// int main(int argc, char* argv[])
// Algorithme :
// Initialise les composants principaux et lance la boucle principale de l'application.
int main(int argc, char *argv[])
{
    if (argc > 1 && string(argv[1]) == "test")
    {
        CSVHandler::extractAll("CSV_Tests");
        runTests();
    }
    else
    {
        CSVHandler::extractAll("CSV");
        Presentation presentation;
        presentation.Menu_principal();
    }

    return 0;
}