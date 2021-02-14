#include <iostream>

#include "parseArgs.h"
#include "database.h"


int main(int argc, char* argv[]){
    Parser parser;
    std::cout << "starting parse\n";
    
    parser.parse(argc, argv);
}

