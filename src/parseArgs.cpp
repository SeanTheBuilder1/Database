#include "parseArgs.h"



void parse(int argc, char* argv[]){
    Data& database = dataGet();
    Auditor& auditor = getAuditor();
    int j = 0;
    for(long i = 1; i < argc; ++i){
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
        else if(strcmp(argv[i], "-p") == 0){
            //Preload all
            auditor.loadAll();
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
            for(auto k : slib::loadTxt("help.txt")){
                std::cout << k << '\n';
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
                    std::deque<std::string>* content;
                    if(item->getContents(content)){
                        for(auto& k : *content){
                            std::cout << k << '\n';
                        }
                    }
                    auditor.addItem(*item);
                    /*  assert(content);
                        Test Case
                        content->emplace_back("hahathisshitworks");
                        auditor.saveItem(*item);*/
                }
            }
        }
        else if(strcmp(argv[i], "-additem") == 0){
            assert(argv[i + 1] != NULL);
            Item temp{argv[i + 1]};
            j = j + 1;
            std::deque<std::string>* content;
            if(temp.getContents(content)){
                for(long k = i + 2; k < argc; ++k){
                    std::string str{argv[k]};
                    if(std::find(str.begin(), str.end(), '-') == str.end()){
                        content->emplace_back(std::string(argv[k]));
                        j = j + 1;
                    }
                    else{
                        break;
                    }
                }
            }
            auditor.addItem(temp);
        }
        else if(strcmp(argv[i], "-clear") == 0){
            database.clearData();
        }
        else if(strcmp(argv[i], "-delitem") == 0){
            assert(argv[i + 1] != NULL);
            auditor.delItem(std::string(argv[i + 1]));
        }
        else if(strcmp(argv[i], "-swap") == 0){
            assert(argv[i + 2] != NULL);
            j = j + 2;
            Item* item;
            Item* destination;
            auditor.getItem(argv[i + 1], item);
            auditor.getItem(argv[i + 2], destination);
            auditor.swapItem(*item, *destination);
        }
        else if(strcmp(argv[i], "-move") == 0){
            assert(argv[i + 2] != NULL);
            j = j + 2;
            Item* item;
            Item* destination;
            auditor.getItem(argv[i + 1], item);
            auditor.getItem(argv[i + 2], destination);
            auditor.moveItem(*item, *destination);
        }
        else if(strcmp(argv[i], "-sortdata") == 0){
            auditor.sort();
        }
        else if(strcmp(argv[i], "-edititem") == 0){
            assert(argv[i + 3] != NULL);
            std::cout << argv[i + 2] << '\n';
            assert(slib::isDigit(std::string(argv[i + 2])));
            j = j + 3;
            long index = atoi(argv[i + 2]) - 1;
            Item* temp = nullptr;
            auditor.openItem(std::string(argv[i + 1]));
            if(auditor.getItem(std::string(argv[i + 1]), temp)){
                temp->editItem(index, argv[i + 3]);
                auditor.saveItem(*temp);
            }
        }
        else if(strcmp(argv[i], "-search") == 0){
            assert(argv[i + 1] != NULL);
            j = j + 1;
            std::vector<std::string> temp = searchItem(argv[i + 1]);
            for(auto& k : temp){
                std::cout << k << '\n';
            }
        }
        else if(strcmp(argv[i], "-psearch") == 0){
            assert(argv[i + 1] != NULL);
            j = j + 1;
            std::vector<std::string> temp = searchItemPreload(argv[i + 1]);
            for(auto& k : temp){
                std::cout << k << '\n';
            }
        }
        else if(strcmp(argv[i], "-sort") == 0){
            assert(argv[i + 1] != NULL);
            j = j + 1;
            Item* item;
            auditor.openItem(argv[i + 1]);
            if(auditor.getItem(std::string(argv[i + 1]), item)){
                item->sort();
                auditor.saveItem(*item);
            }
        }
        else if(strcmp(argv[i], "-editor") == 0){
            assert(argv[i + 1] != NULL);
            j = j + 1;
            if(auditor.openItem(argv[i + 1])){
                Item* item;
                if(auditor.getItem(argv[i + 1], item))
                    editItem(item);
            }
        }
    }
}



