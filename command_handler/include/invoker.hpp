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
        /**
         * @class Invoker - Based on the input data received from the client,
         * it generates commands and passes it on to execution
         */
        class Invoker {
        public:
            /**
             * @brief Invoker - constructor
             */
            Invoker() = default;

            /**
             * @brief ~Invoker - destructor
             */
            virtual  ~Invoker() = default;

            /**
             * @brief Invoker - copy contructor
             */
            Invoker(const Invoker &) = default;

            /**
             * @brief Invoker - move constructor
             */
            Invoker(Invoker &&) = default;

            /**
             * @brief operator= - copy assignment operator
             */
            Invoker &operator=(const Invoker &) = default;

            /**
             * @brief operator= move assignment operator
             */
            Invoker &operator=(Invoker &&) = default;

            /**
             * @brief countOccurrencesWord - create CountOccurrencesWordCommand and send to CommandHandler
             * @param filename - input file
             * @param searchWord - word, the number of occurrences of which will be calculated
             */
            void countOccurrencesWord(std::string &filename, std::string &searchWord);

            /**
             * @brief calculateCheckSum - create ChecksumCommand and sent to CommandHandler
             * @param filename - input file
             */
            void calculateCheckSum(std::string &filename);

            /**
             * @brief start - boost signal for sending command to CommandHandler
             */
            boost::signals2::signal<void(std::shared_ptr<ICommand> command)> start;
        protected:

            /**
             * @brief createCountOccurrencesWordCommand - create new exemplar of  CountOccurrencesWordCommand class
             * @param filename - input file
             * @param searchWord - Word, the number of occurrences of which will be calculated
             * @return - new exemplar of  CountOccurrencesWordCommand class
             */
            std::shared_ptr<ICommand> createCountOccurrencesWordCommand(std::string &filename, std::string &searchWord);

            /**
             * @brief createChecksumCommand - create new exemplar of  ChecksumCommand class
             * @param filename - input file
             * @return new exemplar of  ChecksumCommand class
             */
            std::shared_ptr<ICommand> createChecksumCommand(std::string &filename);

        };//class Invoker

    }//namespace command_handler
}//namespace word_counter



#endif //WORD_COUNTER_INVOKER_HPP
