#include <iostream>

#include "parseArgs.h"
#include "database.h"




int main(int argc, char* argv[]){
    Parser parser;
    //Parse command line arguments
    parser.parse(argc, argv);
    std::cout << "Program ended\n";
}
