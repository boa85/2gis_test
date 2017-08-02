//
// Created by boa on 02.08.17.
//

#ifndef WORD_COUNTER_COMMAND_HANDLER_HPP
#define WORD_COUNTER_COMMAND_HANDLER_HPP

#include <string>
#include <memory>
#include "file_reader.hpp"

namespace word_counter {
    using namespace file_reader;
    namespace command_handler {

        class CommandHandler {
        public:
            CommandHandler();

            virtual ~CommandHandler() = default;

            void countWords(const std::string &filename, const std::string word);

            void calculateChecksum(const std::string &filename);

        private:
            std::unique_ptr<FileReader> fileReader_;
        };//class CommandHandler
    }//namespace command_handler
}//namespace word_counter



#endif //WORD_COUNTER_COMMAND_HANDLER_HPP
