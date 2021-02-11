#include "database.h"

void Data::Init(){
    loadData();
}

void Data::loadData(){
    std::vector<std::string> data;
	file.open("data.txt", std::fstream::in);
	std::string a;
	while (getline(file, a)) {
		data.push_back(a);
	}
	file.close();
	file.clear();
    dataSave = data;
}

void Data::saveAlgo(int line, std::string replacement) {
    line = line - 1;
	std::vector<std::string> data;
	file.open("data.txt", std::fstream::in);
	std::string a;
	while (getline(file, a)) {
		data.push_back(a);
	}
	file.close();
	if(data.size() < line){
		data.resize(line + 1);
	}
	file.open("data.txt", std::fstream::out);
	data[line] = replacement;
	int i=0;
	for (; i < static_cast<int>(data.size()-1); i++) {
		file << data[i] << "\n";
	}
	file << data[i];
	file.close();
}