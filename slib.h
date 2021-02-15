#include <cstring>
#include <string>
#include <fstream>
#include <vector>


#ifndef SLIB
#define SLIB

namespace slib{
    bool isDigit(std::string word);
    bool isDigit(std::string_view view);
    std::vector<std::string> loadTxt(std::string filename);
}

#endif