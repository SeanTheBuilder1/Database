#ifndef PARSE_ARGS
#define PARSE_ARGS

#include <iostream>
#include <cstring>
#include <cassert>

#include "database.h"
#include "slib.h"



class Parser{
private:
    Data& database;
public:
    Parser():database(dataGet()){};
    void parse(int argc, char* argv[]);
};


#endif //PARSE_ARGS