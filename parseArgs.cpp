#include "parseArgs.h"

void Parser::parse(int argc, char* argv[]){
    for(int i = 1; i < argc; ++i){
        std::cout << argv[i] << '\n';
        if(strcmp(argv[i], "-o") == 0){
            std::cout << "hello\n";
            database.saveAlgo(atoi(argv[i+1]), std::string(argv[i+2]));
        }
        if(strcmp(argv[i], "-n") == 0){
            std::cout << "lmao\n";
            database.saveAlgo(atoi(argv[i+1]), std::string(argv[i+2]));
        }
    }
}