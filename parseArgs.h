#ifndef PARSE_ARGS
#define PARSE_ARGS

#include <iostream>
#include <cstring>
#include <cassert>

#include "database.h"

namespace slib{
    bool isDigit(std::string word);
    std::vector<std::string> loadTxt(std::string filename);
}


class Parser{
private:
    Data database;
public:
    
    void parse(int argc, char* argv[]);
};


#endif //PARSE_ARGS