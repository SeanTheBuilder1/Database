#ifndef DATABASE
#define DATABASE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Data{
private:
    std::vector<std::string> dataSave;
    std::fstream file; 
    void loadData();
public:
    Data(){
        Init();
    };
    void Init();
    void saveAlgo(int line, std::string replacement);
    
};

#endif //DATABASE