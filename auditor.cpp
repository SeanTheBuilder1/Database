#include "auditor.h"

bool Auditor::exist(std::string index){
    for(auto &i : audit){
        if(i  == index)
            return true;
    }
    return false;
}

void Auditor::addItem(Item item){
    std::cout << "not yet \n";
}

bool Auditor::openItem(std::string index){
    Item temp{index};
    if(temp.readItem(temp.getIndex())){
        items.emplace_back(temp);
        audit.emplace_back(index);
        return true;
    }
    else{
        std::cout << "The item \"" + index + "\" does not exist on the database\n";
        return false;
    }   
}

void Auditor::saveItem(Item& item){
    long beg{0};
    long end{0};
    bool stopper = false;
    //index line number of item for next iterator
    for(long i = 0; i < item.database.dataSave.size();  ++i){
        if((item.database.dataSave[i] == (std::string("`") + item.getIndex())) == 1){
            beg = (i + 1);
            for(++i; i < item.database.dataSave.size(); ++i){
                if(std::find(item.database.dataSave[i].begin(), item.database.dataSave[i].end(), '`') != item.database.dataSave[i].end()){
                    end = i;
                    stopper = true;
                    break;
                }
            }
        }
        else if(stopper)
            break;
    }
    //if successful erase old contents of item from database copy and insert new contents 
    //and save database copy to merge to data.txt
    if(stopper){
        item.database.dataSave.erase(item.database.dataSave.begin() + beg, item.database.dataSave.begin() + end);
        item.database.dataSave.insert(item.database.dataSave.begin() + beg, item.contents.begin(), item.contents.end());
        item.database.saveData(item.database.dataSave);
    }
}

bool Auditor::getItem(std::string index, Item* &item){
    //loop through items list and check for index given and give pointer for item
    //return true if successful
    //return false if failed
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