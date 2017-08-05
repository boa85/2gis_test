//
// Created by boa on 05.08.17.
//

#include "../include/invoker.hpp"
#include "../include/count_occurrences_word_command.hpp"
#include "../include/checksum_command.hpp"

namespace word_counter {
    namespace command_handler {
        std::shared_ptr<ICommand> Invoker::createCountOccurrencesWordCommand(std::string &filename,
                                                                             std::string &searchWord) {
            return std::make_shared<CountOccurrencesWordCommand>(filename, searchWord);
        }

        std::shared_ptr<ICommand> Invoker::createChecksumCommand(std::string &filename) {
            return std::make_shared<ChecksumCommand>(filename);
        }

        void Invoker::countNumberOccurrencesWord(std::string &filename, std::string &searchWord) {
            auto command = createCountOccurrencesWordCommand(filename, searchWord);
            start(command);
        }

        void Invoker::calculateCheckSum(std::string &filename) {
            auto command = createChecksumCommand(filename);
            start(command);
        }

    }//namespace command_handler
}//namespace word_counter
