cmake_minimum_required(VERSION 3.14)
project(Lexer)

include(CTest)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Lexer ${SOURCES})

target_include_directories(Lexer PUBLIC inc)

add_subdirectory(tests)

