#ifndef INTERFACE
#define INTERFACE

#include <iostream>
#include <functional>
#include <string>
#include "slib.h"
#include "dataType.h"
#include "auditor.h"


class Interface{
private:
    Auditor& auditor;
public:
    Interface():auditor(getAuditor()){};
    void editItem(Item* item);
};



#endif //INTERFACE