#include "parseArgs.h"



void Parser::parse(int argc, char* argv[]){
    int j = 0;
    for(int i = 1; i < argc; ++i){
        //Pauser
        if(j > 0){
            j = j - 1;
            continue;
        }
        std::cout << argv[i] << '\n';
        if(strcmp(argv[i], "-o") == 0){
            //Check if argument actually exists
            assert(argv[i + 2] != NULL);
            //Check if digit
            assert(slib::isDigit(std::string(argv[i + 1])));
            std::cout << "Putting " << argv[i + 2] << " on line " << argv[i + 1] << "\n";
            //Pause parsing for 2 arguments
            j = j + 2;
            int x = atoi(argv[i + 1]);
            assert(x > 0);
            //Replace line's content with given string
            database.saveAlgo(x, std::string(argv[i+2]));
        }
        else if(strcmp(argv[i], "-n") == 0){
            //Check if argument actually exists
            assert(argv[i + 2] != NULL);
            //Check if digit
            assert(slib::isDigit(std::string(argv[i + 1])));
            std::cout << "Putting \"" << argv[i + 2] << "\" on line " << argv[i + 1] << "\n";
            //Pause parsing for 2 arguments
            j = j + 2;
            int x = atoi(argv[i + 1]);
            assert(x > 0);
            //Replace line's content with given string
            database.saveAlgo(x, std::string(argv[i+2]));
        }

        else if(strcmp(argv[i], "-fill") == 0){
            //Check if argument actually exists
            assert(argv[i + 3] != NULL);
            //Check if digit
            assert(slib::isDigit(std::string(argv[i + 1])) && slib::isDigit(std::string(argv[i + 2])));
            int x = atoi(argv[i + 1]);
            int y = atoi(argv[i + 2]);
            assert(x <= y);
            assert(x > 0);
            database.fillData(x, y, argv[i + 3]);
        }

        else if(strcmp(argv[i], "-cell") == 0){
            assert(argv[i + 3] != NULL);
            //Check if digit
            assert(slib::isDigit(std::string(argv[i + 1])) && slib::isDigit(std::string(argv[i + 2])));
            int x = atoi(argv[i + 1]);
            int y = atoi(argv[i + 2]);
            assert(x > 0 && y > 0);
            database.saveCell(x, y, std::string(argv[i + 3]));
        }

        else if(strcmp(argv[i], "-print") == 0){
            database.printList();
        }

        else if(strcmp(argv[i], "-table") == 0){
            database.printTable();
        }

        else if(strcmp(argv[i], "--help") == 0){
            //Check if argument actually exists
            assert(argv[i] != NULL);
            //Load help file content and print
            for(auto i : slib::loadTxt("help.txt")){
                std::cout << i << '\n';
            }
        }
        
        else if(strcmp(argv[i], "-item") == 0){
            assert(argv[i + 1] != NULL);
            Item* item;
            std::string index{argv[i + 1]};
            j = j + 1;
            auditor.openItem(index);
            if(auditor.exist(index)){
                if(auditor.getItem(index, item)){
                    std::vector<std::string> content;
                    if(item->getContents(content)){
                        for(auto& i : content){
                            std::cout << i << '\n';
                        }
                    }
                }
            }
        }
    }
}



