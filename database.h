#ifndef DATABASE
#define DATABASE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Data{
private:
    std::vector<std::string> dataSave;
    std::string filePath;
    std::fstream file; 
    std::vector<std::string> loadData();
public:
    Data(){
        Init();
    };
    void Init();
    void saveAlgo(int line, std::string replacement);
    void printList();
};

#endif //DATABASE