#ifndef PARSE_ARGS
#define PARSE_ARGS

#include <iostream>
#include <cstring>
#include <cassert>


#include "database.h"
#include "auditor.h"
#include "slib.h"



class Parser{
private:
    Data& database;
    Auditor& auditor;
public:
    Parser():database(dataGet()), auditor(getAuditor()){};
    void parse(int argc, char* argv[]);
};


#endif //PARSE_ARGS