//
// Created by boa on 04.08.17.
//

#ifndef WORD_COUNTER_WORD_COUNT_COMMAND_HPP
#define WORD_COUNTER_WORD_COUNT_COMMAND_HPP

#include <string>

#include "icommand.hpp"

namespace word_counter {
    namespace command_handler {
        class CountOccurrencesWordCommand : public ICommand {
        public:
            CountOccurrencesWordCommand(std::string &filename, std::string &searchWord);

            ~CountOccurrencesWordCommand() override = default;

            void execute() override;

        private:
            std::string filename_;
            std::string searchWord_;

        };// class CountOccurrencesWordCommand

    }//namespace command_handler
}//namespace word_counter


#endif //WORD_COUNTER_WORD_COUNT_COMMAND_HPP
