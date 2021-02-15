#include "database.h"

void Data::Init(){
    loadData();
}

void Data::metaParser(){
	if(dataSave[0] == "//table"){
		std::string col{dataSave[1]};
		assert(col.size() > 2);
		col.erase(0, 2);
		assert(slib::isDigit(col));
		columns = stoi(col);	
	}
}

std::vector<std::string> Data::loadData(){
    std::vector<std::string> data;
	file.open(filePath, std::fstream::in);
	std::string a;
	//Get contents of member filePath
	while (getline(file, a)) {
		data.emplace_back(a);
	}
	file.close();
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
	//If line is higher than list length resize the list
	std::cout << data.size();
	if(data.size() < line){
		data.resize(line);
	}
	//Replace chosen line with replacement
	data[line] = replacement;
	saveData(data);
}

void Data::fillData(int start, int end, std::string replacement){
	start = start - 1;
	end = end;
	std::vector<std::string> data;
	//Get content list of member filePath
	data = loadData();
	
	if(data.size() < end){
		data.resize(end);
	}
	for(int i = start; i < end; ++i){
		data[i] = replacement;
	}
	saveData(data);
}

void Data::saveCell(int x, int y, std::string replacement){
	//Bounds checking
	assert(0 < x && x <= columns);
	//Multidimensional Array Convert
	saveAlgo((columns * (y - 1)) + x + 2, replacement);
}

void Data::saveData(std::vector<std::string>& data){
	file.open(filePath, std::fstream::out);
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
}

void Data::printTable(){
	loadData();
	for(int i = 1; i <= dataSave.size(); ++i){
		std::cout << dataSave[i + 1] << "	";
		if(i % columns == 0){
			std::cout << '\n';
		}
	}
}

