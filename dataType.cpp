#include "dataType.h"



bool Item::readItem(std::string index){
    std::vector<std::string> temp;
    for(long i = 0; i < database.dataSave.size(); ++i){
        if((database.dataSave[i] == (std::string("`") + index)) == 1){
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
    contents = temp;
    return true;
}

bool Item::getContents(std::vector<std::string>& data){
    if(!contents.empty()){
        data = contents;
        return true;
    }
    else
        return false;
}

std::string Item::getIndex(){
    return index;
}