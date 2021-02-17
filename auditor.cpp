#include "auditor.h"

bool Auditor::exist(std::string index){
    for(auto &i : items){
        if(i.getIndex() == index){
            return true;
        };
    }
    return false;
}

void Auditor::addItem(Item item){
    std::cout << "not yet \n";
}

void Auditor::openItem(std::string index){
    Item temp{index};
    temp.readItem(temp.getIndex());
    items.emplace_back(temp);
}

void Auditor::saveItem(Item item){
    std::cout << "not yet \n";
}

bool Auditor::getItem(std::string index, Item* &item){
    for(Item& i : items){
        if(i.getIndex() == index){
            item = &i;
            return true;
        };
    }
    return false;
}

Auditor& getAuditor(){
    static Auditor auditor;
    return auditor;
}