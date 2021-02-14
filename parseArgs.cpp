#include "parseArgs.h"


bool slib::isDigit(std::string word){
    for(char i : word){
        if(!isdigit(i)) 
            return  false;
    }
    return true;
}

std::vector<std::string> slib::loadTxt(std::string filename)
{
    std::fstream file;
    std::vector<std::string> data;
	file.open(filename, std::fstream::in);
	std::string a;
	while (getline(file, a)) {
		data.push_back(a);
	}
	file.close();
	file.clear();
    return data;
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
            std::cout << "Putting \"" << argv[i + 2] << "\" on line " << argv[i + 1] << "\n";
            j = j + 2;
            database.saveAlgo(atoi(argv[i+1]), std::string(argv[i+2]));
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



