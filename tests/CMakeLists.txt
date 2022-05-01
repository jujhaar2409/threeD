cmake_minimum_required(VERSION 3.14)
project(LexerTests)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE SOURCES "./*.cpp")

add_executable(LexerTests ${SOURCES})
target_include_directories(LexerTests PUBLIC .)

get_filename_component(CASES_DIR cases ABSOLUTE)

target_compile_definitions(LexerTests PUBLIC -DCASES_DIR="${CASES_DIR}")

# Set Gtest options
set(INSTALL_GTEST OFF)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(../ext/googletest googletest)
target_link_libraries(LexerTests gtest_main)

# find all source files
file(GLOB_RECURSE SOURCES
	../src/*.cpp
)

# Remove main.cpp from the list of sources
list(REMOVE_ITEM SOURCES ../src/main.cpp)

# add the executable
add_library(LexerLib ${SOURCES})
target_include_directories(LexerLib PUBLIC ../inc)
target_link_libraries(LexerTests LexerLib)

include(GoogleTest)
gtest_discover_tests(LexerTests)
