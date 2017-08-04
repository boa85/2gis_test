//
// Created by boa on 04.08.17.
//

#ifndef WORD_COUNTER_ARGS_PARSE_EXCEPTION_HPP
#define WORD_COUNTER_ARGS_PARSE_EXCEPTION_HPP

#include <exception>
#include <string>

namespace word_counter {
    namespace argument_parser {
        class ArgsParseException : public std::exception {
        public:
            explicit ArgsParseException(const std::string &message)throw();

            const char *what() const throw() override;

        private:
            const std::string errorMessage_;
        };

    }
}


#endif //WORD_COUNTER_ARGS_PARSE_EXCEPTION_HPP
