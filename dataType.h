#ifndef DATATYPE
#define DATAYPE

#include <vector>
#include <string>
#include <algorithm>

#include "database.h"



class Item{
private:
    std::vector<std::string> contents;
    std::string index;
    Data& database;
public:
    Item(std::string i):database(dataGet()), index(i){};
    bool readItem(std::string index);
    bool getContents(std::vector<std::string>& data);
    std::string getIndex();
};

class Searcher{
    std::string searchItem(std::string keyword);
};




#endif //DATATYPE