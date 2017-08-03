//
// Created by boa on 02.08.17.
//

#include "../include/command_handler.hpp"
#include <iostream>

namespace word_counter {
    namespace command_handler {
        CommandHandler::CommandHandler() : fileReader_(std::make_unique<FileReader>()) {

        }

        void CommandHandler::runCountWordsMode(const std::string &filename, std::string &searchWord) {
            searchWord_ = std::move(searchWord);
            fileReader_->getText.connect(boost::bind(&CommandHandler::countWords, this, _1));
            fileReader_->read(filename);
        }

        void CommandHandler::runCalculateChecksumMode(const std::string &filename) {
            fileReader_->getText.connect(boost::bind(&CommandHandler::calculateChecksum, this, _1));
            fileReader_->read(filename);
            std::cout << "filename = " << filename << std::endl;
        }

        void CommandHandler::countWords(const Text &text) {

        }

        void CommandHandler::calculateChecksum(const Text &text) {

        }

    }//namespace command_handler
}//namespace word_counter
