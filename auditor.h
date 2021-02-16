#ifndef AUDITOR
#define AUDITOR

#include <string>
#include <vector>
#include "dataType.h"

class Auditor{
private:
    std::vector<std::string> audit;
    std::vector<Item> items;
public:
    bool exist(std::string index);
    void addItem(Item item);
    void openItem(std::string index);
    void saveItem(Item item);
};


#endif //AUDITOR