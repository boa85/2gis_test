//
// Created by boa on 02.08.17.
//

#ifndef WORD_COUNTER_COMMAND_HANDLER_HPP
#define WORD_COUNTER_COMMAND_HANDLER_HPP

#include <string>
#include <functional>
#include <memory>
#include "icommand.hpp"

namespace word_counter {
    namespace command_handler {
        class CommandHandler {
        public:
            CommandHandler() = default;

            void start(std::shared_ptr<ICommand> command);

        };//class CommandHandler

    }//namespace command_handler
}//namespace word_counter


#endif //WORD_COUNTER_COMMAND_HANDLER_HPP
