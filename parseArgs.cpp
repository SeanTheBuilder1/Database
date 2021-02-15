#include "parseArgs.h"



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
            int x = atoi(argv[i + 1]);
            assert(x > 0);
            database.saveAlgo(x, std::string(argv[i+2]));
        }
        if(strcmp(argv[i], "-n") == 0){
            assert(argv[i + 2] != NULL);
            assert(slib::isDigit(std::string(argv[i + 1])));
            std::cout << "Putting \"" << argv[i + 2] << "\" on line " << argv[i + 1] << "\n";
            j = j + 2;
            int x = atoi(argv[i + 1]);
            assert(x > 0);
            database.saveAlgo(x, std::string(argv[i+2]));
        }

        if(strcmp(argv[i], "-fill") == 0){
            assert(argv[i + 3] != NULL);
            assert(slib::isDigit(std::string(argv[i + 1])) && slib::isDigit(std::string(argv[i + 2])));
            int x = atoi(argv[i + 1]);
            int y = atoi(argv[i + 2]);
            assert(x <= y);
            assert(x > 0);
        }

        if(strcmp(argv[i], "--print") == 0){
            assert(argv[i] != NULL);
            database.printList();
        }
        if(strcmp(argv[i], "--help") == 0){
            assert(argv[i] != NULL);
            for(auto i : slib::loadTxt("help.txt")){
                std::cout << i << '\n';
            }
        }

    }
}



