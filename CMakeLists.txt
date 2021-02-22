cmake_minimum_required(VERSION "3.0")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_COMPILER "g++")


project("database")

add_executable(
    main
    "./src/auditor.h"
    "./src/auditor.cpp"
    "./src/database.h"
    "./src/database.cpp"
    "./src/dataType.h"
    "./src/dataType.cpp"
    "./src/main.cpp"
    "./src/parseArgs.h"
    "./src/parseArgs.cpp"
    "./src/slib.h"
    "./src/slib.cpp"
)