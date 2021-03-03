#ifndef DATATYPE
#define DATATYPE

#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <functional>

#include "database.h"



class Item{
private:
    std::deque<std::string> contents;
    std::string index;
    Data& database;
public:
    Item(std::string i):database(dataGet()), index(i){};
    bool readItem(std::string index);
    bool getContents(std::deque<std::string>*& data);
    void editItem(long index, const std::string& replacement);
    void replaceContents(std::vector<std::string>& cont);
    void replaceContents(std::deque<std::string>& cont);
    void sort();
    void sort(std::function<bool(std::string, std::string)>);
    void sort(std::deque<std::string>::iterator x, std::deque<std::string>::iterator y);
    void sort(std::deque<std::string>::iterator x, std::deque<std::string>::iterator y, std::function<bool(std::string, std::string)> func);
    std::string getIndex();
};





#endif //DATATYPE