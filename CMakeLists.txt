cmake_minimum_required(VERSION "3.0")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O2 -std=c++17")
set(CMAKE_CXX_COMPILER "g++")


project("database")

add_executable(
    main
    "./src/auditor.h"
    "./src/database.h"
    "./src/dataType.h"
    "./src/interface.h"
    "./src/parseArgs.h"
    "./src/searcher.h"
    "./src/slib.h"
    "./src/auditor.cpp"
    "./src/database.cpp"
    "./src/dataType.cpp"
    "./src/interface.cpp"
    "./src/main.cpp"
    "./src/parseArgs.cpp"
    "./src/searcher.cpp"
    "./src/slib.cpp"
)