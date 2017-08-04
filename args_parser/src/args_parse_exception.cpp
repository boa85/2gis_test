//
// Created by boa on 04.08.17.
//

#include "../include/args_parse_exception.hpp"

namespace word_counter {
    namespace argument_parser {
        ArgsParseException::ArgsParseException(const std::string &message) throw()
                : errorMessage_(message) {}

        const char *ArgsParseException::what() const throw() {
            return std::string("argument parser " + errorMessage_).c_str();
        }
    }
}

