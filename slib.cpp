#include "slib.h"

bool slib::isDigit(std::string word){
    for(char i : word){
        if(!isdigit(i)) 
            return  false;
    }
    return true;
}

std::vector<std::string> slib::loadTxt(std::string filename){
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
