//
// Created by boa on 05.08.17.
//

#ifndef WORD_COUNTER_INVOKER_HPP
#define WORD_COUNTER_INVOKER_HPP

#include <memory>

#include <boost/signals2.hpp>

#include "icommand.hpp"

namespace word_counter {
    namespace command_handler {
        class Invoker {
        public:
            Invoker() = default;

            virtual  ~Invoker() = default;

            void countOccurrencesWord(std::string &filename, std::string &searchWord);

            void calculateCheckSum(std::string &filename);

            boost::signals2::signal<void(std::shared_ptr<ICommand>)> start;
        protected:
            std::shared_ptr<ICommand> createCountOccurrencesWordCommand(std::string &filename, std::string &searchWord);

            std::shared_ptr<ICommand> createChecksumCommand(std::string &filename);

        };

    }//namespace command_handler
}//namespace word_counter



#endif //WORD_COUNTER_INVOKER_HPP
