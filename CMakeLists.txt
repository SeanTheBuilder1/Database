cmake_minimum_required(VERSION "3.0")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O2 -std=c++17")
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_COMPILER "g++")

aux_source_directory(./src/ SRC_LIST)

project("database")



add_executable(
    main
    "./src/main.cpp"
    ${SRC_LIST}
)

target_link_libraries(main PRIVATE )