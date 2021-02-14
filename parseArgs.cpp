#include "parseArgs.h"


bool slib::isDigit(std::string word){
    for(char i : word){
        if(!isdigit(i)) 
            return  false;
    }
    return true;
}

void Parser::parse(int argc, char* argv[]){
    int j = 0;
    for(int i = 1; i < argc; ++i){
        if(j > 0){
            j = j - 1;
            continue;
        }
        std::cout << argv[i] << '\n';
        if(strcmp(argv[i], "-o") == 0){
            assert(argv[i + 2] != NULL);
            assert(slib::isDigit(std::string(argv[i + 1])));
            std::cout << "Putting " << argv[i + 2] << " on line " << argv[i + 1] << "\n";
            j = j + 2;
            database.saveAlgo(atoi(argv[i + 1]), std::string(argv[i + 2]));
        }
        if(strcmp(argv[i], "-n") == 0){
            assert(argv[i + 2] != NULL);
            assert(slib::isDigit(std::string(argv[i + 1])));
            std::cout << "Putting " << argv[i + 2] << " on line " << argv[i + 1] << "\n";
            j = j + 2;
            database.saveAlgo(atoi(argv[i+1]), std::string(argv[i+2]));
        }

    }
}



