#ifndef AUDITOR
#define AUDITOR

#include <string>
#include <vector>
#include <deque>
#include "dataType.h"

class Auditor{
private:
    std::vector<std::string> audit;
    std::deque<Item> items;
    friend class Parser;
public:
    bool exist(std::string index);
    void addItem(Item item);
    bool openItem(std::string index);
    void saveItem(Item& item);
    bool getItem(std::string index, Item* &item);
};

Auditor& getAuditor();

#endif //AUDITOR