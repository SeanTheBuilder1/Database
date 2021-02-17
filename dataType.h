#ifndef DATATYPE
#define DATAYPE

#include <vector>
#include <string>
#include <algorithm>
#include <deque>

#include "database.h"



class Item{
private:
    std::deque<std::string> contents;
    std::string index;
    Data& database;
    friend class Auditor;
    friend class Parser;
public:
    Item(std::string i):database(dataGet()), index(i){};
    bool readItem(std::string index);
    bool getContents(std::deque<std::string>*& data);
    std::string getIndex();
};

class Searcher{
    std::string searchItem(std::string keyword);
};




#endif //DATATYPE