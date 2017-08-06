//
// Created by boa on 04.08.17.
//

#ifndef TWO_GIS_TEST_ARGS_PARSE_EXCEPTION_HPP
#define TWO_GIS_TEST_ARGS_PARSE_EXCEPTION_HPP

#include <exception>
#include <string>

namespace two_gis_test {
    namespace argument_parser {
        /**
         * @class ArgsParseException - my exception
         */
        class ArgsParseException : public std::logic_error {
        public:
            /**
             * @brief ArgsParseException  - constructor
             * @param message - error message
             */
            explicit ArgsParseException(const std::string &message);

            /**
             * @brief ArgsParseException - constructor
             * @param message
             */
            explicit ArgsParseException(const char *message);

            /**
             * @brief ArgsParseException - copy constructor
             */
            ArgsParseException(const ArgsParseException &) = default;

            ArgsParseException &operator=(const ArgsParseException &) = default;

            ~ArgsParseException() override = default;

            /**
             * @brief what - override method
             * @return Returns a C-style character string describing the general cause of
             * the current error (the same string passed to the ctor).
             */
            const char *what() const throw() override;
        };
    }
}


#endif //TWO_GIS_TEST_ARGS_PARSE_EXCEPTION_HPP
