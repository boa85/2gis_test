//
// Created by boa on 04.08.17.
//

#include <iostream>

#include "../include/checksum_command.hpp"

namespace word_counter {
    namespace command_handler {
        ChecksumCommand::ChecksumCommand(std::string &filename) : filename_(std::move(filename)) {
            std::cout << "ChecksumCommand, fn = " << filename_ << std::endl;
        }

        void ChecksumCommand::execute() {
            std::cout << "ChecksumCommand::execute()" << std::endl;
        }

    }//namespace command_handler
}//namespace word_counter

