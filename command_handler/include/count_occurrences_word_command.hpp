//
// Created by boa on 04.08.17.
//

#ifndef WORD_COUNTER_WORD_COUNT_COMMAND_HPP
#define WORD_COUNTER_WORD_COUNT_COMMAND_HPP

#include <string>
#include <vector>

#include "icommand.hpp"

namespace two_gis_test {
    namespace command_handler {
        /**
         * @class CountOccurrencesWordCommand - implements ICommand interface
         */
        class CountOccurrencesWordCommand : public ICommand {
        public:
            /**
             * @brief CountOccurrencesWordCommand - constructor
             * @param filename - input file
             * @param searchWord - search word
             */
            CountOccurrencesWordCommand(std::string &filename, std::string &searchWord);

            /**
             * @brief ~CountOccurrencesWordCommand - destructor
             */
            ~CountOccurrencesWordCommand() override = default;

            /**
             * @brief CountOccurrencesWordCommand -  copy constructor
             */
            CountOccurrencesWordCommand(const CountOccurrencesWordCommand &) = default;

            /**
             * @brief  CountOccurrencesWordCommand - move constructor
             */
            CountOccurrencesWordCommand(CountOccurrencesWordCommand &&) = default;

            /**
             * @brief operator= copy assignment operator
             */
            CountOccurrencesWordCommand &operator=(const CountOccurrencesWordCommand &) = default;

            /**
              * @brief operator= move assignment operator
              */
            CountOccurrencesWordCommand &operator=(CountOccurrencesWordCommand &&) = default;
            /**
             * @brief start - run command execution of the command
             * @param command - command to be executed
             */

            /**
             * @brief execute - override method ICommand interface,
             * count number of occurrences word in file filename_
             */
            void execute() override;

        private:
            /**
             * @brief filename_ - input file
             */
            std::string filename_;
            /**
             * @brief searchWord_ - Word, the number of occurrences of which will be calculated
             */
            std::string searchWord_;

            /**
             * @brief prefixFunction - Classical implementation of the Knuth-Morris-Pratt algorithm
             * computing prefix functions
             */
            std::vector<int> prefixFunction(const std::string &s);

            int countOccurrences();
        };// class CountOccurrencesWordCommand

    }//namespace command_handler
}//namespace two_gis_test


#endif //WORD_COUNTER_WORD_COUNT_COMMAND_HPP
