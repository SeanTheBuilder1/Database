#include "dataType.h"



bool Item::readItem(std::string index){
    std::deque<std::string> temp;
    //Loop database
    for(long i = 0; i < database.dataSave.size(); ++i){
        //If index is right
        if(database.dataSave[i] == (std::string("`") + index)){
            //Restart loop at i + 1
            for(++i; i < database.dataSave.size(); ++i){
                //If captured string is next index end loop
                if(std::find(database.dataSave[i].begin(), database.dataSave[i].end(), '`') != database.dataSave[i].end()){
                    //If no contents found return false
                    //If contents found save to item and return true 
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
    //return true if successful and not nullptr
    //return false if failed
    if(&contents != nullptr){
        data = &contents;
        return true;
    }
    else{
        return false;
    }
}

std::string Item::getIndex(){
    return index;
}