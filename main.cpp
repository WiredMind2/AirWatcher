#include <iostream>
#include "src/presentation.h"
#include "analyse.h"
#include "tests.h"
using namespace std;

int main( int argc, char* argv[]){
    
    if (argc > 1 && string(argv[1]) == "test"){
        tests test;
        test.runTests();
    }
    else{
        presentation pres;
        pres.Menu_principal();
    }
}