cmake_minimum_required(VERSION 3.8)
project(file_reader)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O0 -pedantic-errors -Wextra -Wall -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -Wno-ignored-qualifiers -Wno-unused-parameter")
find_package(Boost 1.58.0 COMPONENTS regex system  filesystem program_options signals)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()
include_directories(${BOOST_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp args_parser/src/argument_parser.cpp args_parser/include/argument_parser.hpp args_parser/test/test.cpp service/include/service.hpp)
add_executable(file_reader ${SOURCE_FILES})
target_link_libraries(file_reader   ${Boost_LIBRARIES} )