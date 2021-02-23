#include "searcher.h"

std::vector<std::string> Searcher::searchItem(const std::string& keyword){
    std::vector<std::string> validIndices;
    for (long i = 0; i < database.dataSave.size(); i++){
        if(database.dataSave[i].find("`") == std::string::npos){
            if(database.dataSave[i] == keyword){
                for(long j = i; j > 2; --j){
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

Searcher& getSearcher(){
    static Searcher searcher;
    return searcher;
}