#include "database.h"

void Data::Init(){
    loadData();
	metaParser();
}

void Data::metaParser(){
	bool error = false;
	//Check if file is empty
	if(dataSave.empty()){
		dataSave.emplace_back("//list");
		dataSave.emplace_back("//1");
		dataSave.emplace_back("`");
		saveData(dataSave);
	}
	//Check for minimum format
	else if(3 > dataSave.size()){
		dataSave.clear();
		dataSave.emplace_back("//list");
		dataSave.emplace_back("//1");
		dataSave.emplace_back("`");
		error = true;
	}
	//Check if database is table
	else if(!(dataSave[0].substr(0, 2) == "//" && dataSave[1].substr(0, 2) == "//")){
		long state{10};
		for(long i = 0; i <= 2; ++i){
			if(dataSave[i].substr(0, 1) == "`")
				state = i;
		}
		if(state == 0){
			dataSave.insert(dataSave.begin(), std::move("//list"));
			dataSave.insert(dataSave.begin() + 1, std::move("//1"));
		}
		else if(state == 1){
			dataSave[0] = "//list";
			dataSave.insert(dataSave.begin() + 1, std::move("//1"));
		}
		else if(state == 2){
			dataSave[0] = "//list";
			dataSave[1] = "//1";
		}
		error = true;
	}

	else if(dataSave[2].substr(0, 1) != "`"){
		dataSave[2].insert(dataSave[2].begin(), '`');
		error = true;
	}

	else if(dataSave[0] == "//table"){
		std::string col{dataSave[1]};
		assert(col.size() > 2);
		col.erase(0, 2);
		//Check if database is valid tablie
		bool success = false;
		if(slib::isDigit(col)){
			if(stoi(col) > 0){
				success = true;
				columns = stoi(col);
			}
		}
		//Reset format if failed
		if(!success){
			dataSave[0] = "//list";
			dataSave[1] = "//1";
			error = true;
		}
	}
	//Check if list
	else if(dataSave[0] == "//list"){
		columns = 1;
	}
	else if(std::find(dataSave.begin(), dataSave.end(), std::string("`")) == dataSave.end()){
		//Check if item header exists, else add a header
		if(*dataSave.end() != "`"){
			dataSave[2] = '`';
			error = true;
		}
	}
	
	else if(dataSave[0].substr(0, 2) == "//" && dataSave[1].substr(0, 2) == "//"){
		dataSave[0] = "//list";
		dataSave[1] = "//1";
		error = true;
	}

	//If all cases don't apply reset format
	else{
		dataSave[0] == "//list";
		dataSave[1] == "//1";
		error = true;
	}
	//Print the Error
	if(error){
		saveData(dataSave);
		std::cout << "A file error occured\nError has been partially fixed, please try again\n";
		throw "File error remedied";
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
	for(long i = start; i < end; ++i){
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
	long i=0;
	//Save file from list
	for (; i < static_cast<int>(data.size()-1); ++i) {
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
	for(long i = 1; i <= dataSave.size(); ++i){
		std::cout << dataSave[i + 1] << "\t";
		if(i % columns == 0){
			std::cout << '\n';
		}
	}
}

void Data::clearData(){
	//Clear database and reformat
	dataSave.clear();
	dataSave.emplace_back("//list");
	dataSave.emplace_back("//1");
	dataSave.emplace_back("`");
	saveData(dataSave);
}

void Data::openFile(const std::string& path){
	filePath = path;
	Init();
}


Data& dataGet(){
    static Data data;
    return data;
}

