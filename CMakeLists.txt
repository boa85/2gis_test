cmake_minimum_required(VERSION 3.5)
project(2gis_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O0 -pedantic-errors -Wextra -Wall -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -Wno-ignored-qualifiers -Wno-unused-parameter")
find_package(Boost 1.58.0 COMPONENTS system filesystem program_options signals)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()
include_directories(${BOOST_INCLUDE_DIRS})

set(SOURCE_FILES
        args_parser/src/argument_parser.cpp
        args_parser/include/argument_parser.hpp
        args_parser/include/args_parse_exception.hpp
        args_parser/src/args_parse_exception.cpp
        service/include/service.hpp
        service/src/service.cpp
        command_handler/src/command_handler.cpp
        command_handler/include/command_handler.hpp
        command_handler/include/icommand.hpp
        command_handler/src/count_occurrences_word_command.cpp
        command_handler/include/count_occurrences_word_command.hpp
        command_handler/src/checksum_command.cpp
        command_handler/include/checksum_command.hpp
        command_handler/src/invoker.cpp
        command_handler/include/invoker.hpp)
add_executable(2gis_test ${SOURCE_FILES} main.cpp)
target_link_libraries(2gis_test ${Boost_LIBRARIES})
