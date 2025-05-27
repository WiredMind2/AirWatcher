#include <iostream>
#include "couche_presentation/presentation.h"
#include "test/tests.h"
#include "couche_acces_aux_donnees/CSVHandler.h"
using namespace std;

int main( int argc, char* argv[]){
    CSVHandler::extractAll("CSV");

    if (argc > 1 && string(argv[1]) == "test"){
        Tests test;
        test.runTests();
    }
    else{
        Presentation presentation;
        presentation.Menu_principal();
    }

    return 0;
}