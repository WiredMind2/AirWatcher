#include <iostream>
#include "src/couche_presentation/presentation.h"
#include "analyse.h"
#include "tests.h"
using namespace std;

int main( int argc, char* argv[]){
    
    if (argc > 1 && string(argv[1]) == "test"){
        Tests test;
        test.runTests();
    }
    else{
        Presentation pres;
        pres.Menu_principal();
    }
}