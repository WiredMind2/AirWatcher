#include <iostream>
#include "src/couche_presentation/presentation.h"
#include "src/test/tests.h"
#include "src/CSVHandler.h"
using namespace std;

int main( int argc, char* argv[]){
    CSVHandler::extractAll("CSV");

    if (argc > 1 && string(argv[1]) == "test"){
        Tests test;
        test.runTests();

    }else{
        Presentation pres;
        pres.Menu_principal();

    }

    return 0;
}