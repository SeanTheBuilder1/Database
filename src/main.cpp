#include <iostream>

#include "parseArgs.h"
#include "database.h"




int main(int argc, char* argv[]){
    //Parse command line arguments
    parse(argc, argv);
    std::cout << "Program ended\n";
}
