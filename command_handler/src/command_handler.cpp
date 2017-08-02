//
// Created by boa on 02.08.17.
//

#include <iostream>
#include "../include/command_handler.hpp"

namespace word_counter {
    namespace command_handler {


        CommandHandler::CommandHandler() : fileReader_(std::make_unique<FileReader>()) {

        }

        void CommandHandler::countWords(const std::string &filename, const std::string word) {
            std::cout << "filename = " << filename << " search word = " << word << std::endl;
        }

        void CommandHandler::calculateChecksum(const std::string &filename) {
            std::cout << "filename = " << filename << std::endl;
        }
    }//namespace command_handler
}//namespace word_counter
