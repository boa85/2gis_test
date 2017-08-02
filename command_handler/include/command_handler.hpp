//
// Created by boa on 02.08.17.
//

#ifndef WORD_COUNTER_COMMAND_HANDLER_HPP
#define WORD_COUNTER_COMMAND_HANDLER_HPP

#include <string>
#include <functional>
#include <bits/unique_ptr.h>
#include "../../service/include/service.hpp"
#include "file_reader.hpp"

namespace word_counter {
    using namespace service;
    using namespace file_reader;
    namespace command_handler {
        class CommandHandler {
        public:
            explicit CommandHandler();

            virtual ~CommandHandler() = default;

            void runCountWordsMode(const std::string &filename, std::string &searchWord);

            void runCalculateChecksumMode(const std::string &filename);

        private:
            std::unique_ptr<FileReader> fileReader_;

            void countWords(const Text &text);

            void calculateChecksum(const Text &text);

            std::string searchWord_;
        };//class CommandHandler

    }//namespace command_handler
}//namespace word_counter


#endif //WORD_COUNTER_COMMAND_HANDLER_HPP
