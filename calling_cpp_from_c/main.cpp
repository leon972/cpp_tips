/**
 * Questo esempio mostra come chiamare funzioni definite in un modulo C++ da codice C
 * Le funzioni chiamabili da C possono al loro interno riferirsi a classi C++
 * Questo file main è compilato in C e non C++
 * In Netbens cliccare con il DX sul file main.cpp ->properties ->General e lì scegliere il C compiler invece del C++ compiler
 */

#include <stdio.h>
#include "mylib.h"

using namespace std;

/*
 * Il file main.cpp è compilato con gcc e non g++
 */
int main(int argc, char** argv) {
    
    printf("This main in C code\n");
    
    //dal C si può invocare questa funzione definita in un file c++ perché è linkata come extern "C"
    process_data(1,2);
    
    return 0;
}

