#include "database.h"

void Data::Init(){
    loadData();
}

std::vector<std::string> Data::loadData(){
    std::vector<std::string> data;
	file.open(filePath, std::fstream::in);
	std::string a;
	//Get contents of member filePath
	while (getline(file, a)) {
		data.push_back(a);
	}
	file.close();
	file.clear(); 
	//Save contents to member dataSave
    dataSave = data;
	//Return contents for use
	return data;
}

void Data::saveAlgo(int line, std::string replacement) {
    line = line - 1;
	std::vector<std::string> data;
	//Get content list of member filePath
	data = loadData();
	file.open(filePath, std::fstream::in);
	//If line is higher than list length resize the list
	if(data.size() < line){
		data.resize(line + 1);
	}
	file.open(filePath, std::fstream::out);
	//Replace chosen line with replacement
	data[line] = replacement;
	int i=0;
	//Save file from list
	for (; i < static_cast<int>(data.size()-1); i++) {
		file << data[i] << "\n";
	}
	file << data[i];
	file.close();
}

void Data::printList(){
	loadData();
	//Loop through list and print every value
	for(const std::string& i : dataSave){
		std::cout << i << '\n';
	}
};
