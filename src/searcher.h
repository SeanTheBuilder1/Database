#ifndef SEARCHER
#define SEARCHER

#include <vector>
#include <string>

#include "database.h"
#include "auditor.h"

class Searcher{
private:
    Data& database;
public:
    Searcher():database(dataGet()){};  
    std::vector<std::string> searchItem(const std::string& keyword);
    std::vector<std::string> searchItemPreload(const std::string& keyword);
};

Searcher& getSearcher();

#endif //SEARCHER