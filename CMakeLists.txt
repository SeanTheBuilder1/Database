cmake_minimum_required(VERSION "3.0")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O3 -std=c++17")
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_COMPILER "g++")

aux_source_directory(./src/ SRC_LIST)

project("database")

add_library(database STATIC
    "./src/auditor.cpp"
    "./src/database.cpp"
    "./src/dataType.cpp"
    "./src/searcher.cpp"
    "./src/slib.cpp"    
) 

add_executable(
    main
    "./src/main.cpp"
    "./src/interface.cpp"
    "./src/parseArgs.cpp"
)

# ${SRC_LIST}

target_include_directories(database PUBLIC auditor.h PUBLIC database.h PUBLIC dataType.h PUBLIC searcher.h PUBLIC slib.h)
target_include_directories(main PUBLIC auditor.h PUBLIC database.h PUBLIC dataType.h PUBLIC searcher.h PUBLIC slib.h)


target_link_libraries(main ${CMAKE_SOURCE_DIR}/libdatabase.a)