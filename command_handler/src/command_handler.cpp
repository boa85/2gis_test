//
// Created by boa on 02.08.17.
//

#include "../include/command_handler.hpp"

namespace two_gis_test {
    namespace command_handler {
        void CommandHandler::start(std::shared_ptr<ICommand> command) {
            command->execute();
        }
    }//namespace command_handler
}//namespace two_gis_test
