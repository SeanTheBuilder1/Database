#include "auditor.h"

bool Auditor::exist(std::string index){
    for(auto &i : audit){
        if(i  == index)
            return true;
    }
    return false;
}

void Auditor::addItem(Item& item){
    if(std::find(database.dataSave.begin(), database.dataSave.end(), ("`" + item.getIndex())) == std::end(database.dataSave)){
        auto it = std::find(database.dataSave.begin(), database.dataSave.end(), "`");
        std::deque<std::string> temp = item.contents;
        temp.insert(temp.begin(), "`" + item.getIndex());
        temp.emplace_back("`");
        database.dataSave.erase(it);
        database.dataSave.insert(it, temp.begin(), temp.end());
        database.saveData(database.dataSave);
        audit.emplace_back(item.getIndex());
        items.emplace_back(item);
    }
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
    for(long i = 0; i < database.dataSave.size();  ++i){
        if((database.dataSave[i] == (std::string("`") + item.getIndex())) == 1){
            beg = (i + 1);
            for(++i; i < database.dataSave.size(); ++i){
                if(std::find(database.dataSave[i].begin(), database.dataSave[i].end(), '`') != database.dataSave[i].end()){
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
        database.dataSave.erase(database.dataSave.begin() + beg, database.dataSave.begin() + end);
        database.dataSave.insert(database.dataSave.begin() + beg, item.contents.begin(), item.contents.end());
        database.saveData(database.dataSave);
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