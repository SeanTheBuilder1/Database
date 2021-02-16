#include "dataType.h"



void Item::readItem(std::string index){
    std::vector<std::string> temp;
    auto check = [&](auto& i){if(i == '`'){return true;}else{return false;}};
    for(int i = 0; i < database.dataSave.size(); ++i){
        if(database.dataSave[i] == ('`' + index)){
            for(++i; i < database.dataSave.size(); ++i){
                if(std::find(database.dataSave[i].begin(), database.dataSave[i].end(), '`') != database.dataSave[i].end()){
                    break;
                }
                temp.emplace_back(database.dataSave[i]);
            }
            break;
        }
    }
    item = temp;
}

std::string Item::getIndex(){
    return index;
}