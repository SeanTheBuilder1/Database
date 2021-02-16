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
}

void Auditor::saveItem(Item item){
    std::cout << "not yet \n";
}