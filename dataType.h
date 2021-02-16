#ifndef DATATYPE
#define DATAYPE

#include <vector>
#include <string>
#include <algorithm>

#include "database.h"



class Item{
private:
    std::vector<std::string> contents;
    std::vector<std::string> item;
    std::string index;
    Data& database;
public:
    Item(std::string i):database(dataGet()), index(i){};
    void readItem(std::string index);
    std::string getIndex();
};

class Searcher{
    std::string searchItem(std::string keyword);
};




#endif //DATATYPE