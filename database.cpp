#include "database.h"

void Data::Init(){
    loadData();
}

void Data::loadData(){
    std::vector<std::string>data;
	file.open("data.txt", std::ios::in);
	std::string a;
	while (getline(file, a)) {
		data.push_back(a);
	}
	file.close();
    dataSave = data;
}

void Data::saveAlgo(int line, std::string replacement) {
    line = line - 1;
	std::vector<std::string>data;
	file.open("data.txt", std::ios::in);
	std::string a;
	while (getline(file, a)) {
		data.push_back(a);
	}
	file.close();
	std::ofstream write;
	file.open("data.txt", std::ios::out);
	data[line] = replacement;
	int i=0;
	for (; i < static_cast<int>(data.size()-1); i++) {
		write << data[i] << "\n";
	}
	write << data[i];
	file.close();
}