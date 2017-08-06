//
// Created by boa on 05.08.17.
//

#include "../include/invoker.hpp"
#include "../include/count_occurrences_word_command.hpp"
#include "../include/checksum_command.hpp"

namespace two_gis_test {

    namespace command_handler {
        std::shared_ptr<ICommand> Invoker::createCountOccurrencesWordCommand(const std::string &filename,
                                                                             const std::string &searchWord) {
            return std::make_shared<CountOccurrencesWordCommand>(filename, searchWord);
        }

        std::shared_ptr<ICommand> Invoker::createChecksumCommand(const std::string &filename) {
            return std::make_shared<ChecksumCommand>(filename);
        }

        void Invoker::countOccurrencesWord(const std::string &filename, const std::string &searchWord) {
            auto command = createCountOccurrencesWordCommand(filename, searchWord);
            start(command);
        }

        void Invoker::calculateCheckSum(const std::string &filename) {
            auto command = createChecksumCommand(filename);
            start(command);
        }

    }//namespace command_handler
}//namespace two_gis_test
