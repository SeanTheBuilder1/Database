#ifndef AUDITOR
#define AUDITOR

#include <string>
#include <vector>
#include <deque>
#include <iterator>
#include "dataType.h"
#include "searcher.h"

class Auditor{
private:
    std::vector<std::string> audit;
    std::deque<Item> items;
    Data& database;
public:
    Auditor():database(dataGet()){};
    bool getAudit(std::deque<Item>*& audit);
    bool exist(const std::string& index);
    void addItem(Item& item);
    bool openItem(const std::string& index);
    void saveItem(Item& item);
    void delItem(const std::string& index);
    bool getItem(const std::string& index, Item* &item);
    long getAuditID(const std::string& index);
    long getItemID(const std::string& index);
    void moveItem(Item& item, long destination);
    void moveItem(Item& item, Item& destination);
    void moveToStart(Item& item);
    void swapItem(Item& item, Item& destination);
    void loadAll();
};

Auditor& getAuditor();

#endif //AUDITOR