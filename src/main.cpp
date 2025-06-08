#include <iostream>
#include "couche_presentation/presentation.h"
#include "test/tests.h"
#include "couche_acces_aux_donnees/CSVHandler.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1 && string(argv[1]) == "test")
    {
        CSVHandler::extractAll("CSV_Tests");
        Tests test;
        test.runTests();
    }
    else
    {
        CSVHandler::extractAll("CSV");
        Presentation presentation;
        presentation.Menu_principal();
    }

    return 0;
}