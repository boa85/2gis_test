//
// Created by boa on 04.08.17.
//

#include <cstring>
#include <memory>

#include "../include/args_parse_exception.hpp"

namespace two_gis_test {
    namespace argument_parser {
        ArgsParseException::ArgsParseException(const std::string &message)
                : std::logic_error(message) {}

        const char *ArgsParseException::what() const throw() {
            return std::logic_error::what();
        }

        ArgsParseException::ArgsParseException(const char *message)
                : std::logic_error(message) {}
    }
}

