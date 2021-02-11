#ifndef PARSE_ARGS
#define PARSE_ARGS

#include <iostream>
#include "database.h"
#include <cstring>

class Parser{
private:
    Data database;
public:
    
    void parse(int argc, char* argv[]);
};


#endif //PARSE_ARGS