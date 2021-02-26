#ifndef DATABASE
#define DATABASE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <string_view>
#include <algorithm>


#include "slib.h"

class Data{
private:
    std::string filePath;
    std::fstream file; 
    int columns;
    std::vector<std::string> loadData();
    void metaParser();
    void saveData(std::vector<std::string>& data);
    friend class Parser;
    friend class Item;
    friend class Auditor;
    friend class Searcher;
public:
    std::vector<std::string> dataSave;
    Data(std::string path = "data.txt"):filePath(path){
        Init();
        metaParser();
    };
    void Init();
    void saveAlgo(int line, std::string replacement);
    void fillData(int start, int end, std::string replacement);
    void saveCell(int x, int y, std::string replacement);
    void printList();
    void printTable();
    void clearData();
};

Data& dataGet();

#endif //DATABASE