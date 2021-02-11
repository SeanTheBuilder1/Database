#include "parseArgs.h"

void Parser::parse(int argc, char* argv[]){
    for(int i = 1; i < argc; ++i){
        std::cout << argv[i] << '\n';
        if(strcmp(argv[i], "-o") == 0){
            std::cout << "hello\n";
            database.saveAlgo(2, argv[i+1]);
        }
        if(strcmp(argv[i], "-n") == 0){
            std::cout << "lmao\n";
            database.saveAlgo(4, std::string(argv[i+1]));
        }
    }
}