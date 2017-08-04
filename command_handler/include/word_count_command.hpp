//
// Created by boa on 04.08.17.
//

#ifndef WORD_COUNTER_WORD_COUNT_COMMAND_HPP
#define WORD_COUNTER_WORD_COUNT_COMMAND_HPP

#include <string>

#include "icommand.hpp"

namespace word_counter {
    namespace command_handler {
        class WordCountCommand : public ICommand {
        public:
            WordCountCommand(const std::string &filename, const std::string &searchWord);

            void execute() override;
        };// class WordCountCommand

    }//namespace command_handler
}//namespace word_counter


#endif //WORD_COUNTER_WORD_COUNT_COMMAND_HPP
