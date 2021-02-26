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
    Data& database;
    friend class Parser;
    friend class Searcher;
public:
    Auditor():database(dataGet()){};
    bool getAudit(std::deque<Item>* audit);
    bool exist(const std::string& index);
    void addItem(Item& item);
    bool openItem(const std::string& index);
    void saveItem(Item& item);
    void delItem(const std::string& index);
    bool getItem(const std::string& index, Item* &item);
    void loadAll();
};

Auditor& getAuditor();

#endif //AUDITOR