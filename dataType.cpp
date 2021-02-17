#include "dataType.h"



bool Item::readItem(std::string index){
    std::deque<std::string> temp;
    for(long i = 0; i < database.dataSave.size(); ++i){
        if(database.dataSave[i] == (std::string("`") + index)){
            for(++i; i < database.dataSave.size(); ++i){
                if(std::find(database.dataSave[i].begin(), database.dataSave[i].end(), '`') != database.dataSave[i].end()){
                    if(temp.empty()){
                        return false;
                    }
                    else{
                        contents = temp;
                        return true;
                    }
                }
                temp.emplace_back(database.dataSave[i]);
            }
            break;
        }
    }
    return false;
}

bool Item::getContents(std::deque<std::string>*& data){
    //loop through items list and check for index given and give pointer for item
    //return true if successful
    //return false if failed
    if(!contents.empty()){
        data = &contents;
        return true;
    }
    else
        return false;
}

std::string Item::getIndex(){
    return index;
}