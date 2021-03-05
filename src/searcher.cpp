#include "searcher.h"

std::vector<std::string> searchItem(const std::string& keyword){
    Data& database = dataGet();
    std::vector<std::string> validIndices;
    for (long i = 0; i < database.dataSave.size(); i++){
        if(database.dataSave[i].find("`") == std::string::npos){
            if(database.dataSave[i] == keyword){
                for(long j = i; j > 1; --j){
                    if(database.dataSave[j].find("`") != std::string::npos){
                        validIndices.emplace_back(std::string(database.dataSave[j]).substr(1, std::string::npos));
                        break;
                    }
                }
            }
        }
    }
    return validIndices;
}

std::vector<std::string> searchItemPreload(const std::string& keyword){
    Data& database = dataGet();
    Auditor& auditor = getAuditor();
    std::vector<std::string> validIndices;
    std::deque<Item>* items;
    auditor.getAudit(items);
    for(auto& i : *items){
        std::deque<std::string>* contents;
        i.getContents(contents);
        if(std::find(contents->begin(), contents->end(), keyword) != contents->end()){
            validIndices.push_back(i.getIndex());
        }
    }
    return validIndices;
}

long getDatabaseIndex(Item& item){
    Data& database = dataGet();
    for(int i = 2; i < database.dataSave.size(); ++i){
        if(database.dataSave[i] == "`" + item.getIndex())
            return i + 1;
    }
    return -1;
}