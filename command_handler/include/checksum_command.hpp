//
// Created by boa on 04.08.17.
//

#ifndef WORD_COUNTER_CHECKSUM_COMMAND_HPP
#define WORD_COUNTER_CHECKSUM_COMMAND_HPP

#include <string>

#include "icommand.hpp"

namespace two_gis_test {
    namespace command_handler {
        /**
         * @class ChecksumCommand - implements ICommand interface
         */
        class ChecksumCommand : public ICommand {
        public:

            /**
             * @brief ChecksumCommand - constructor
             * @param filename - input file
             */
            explicit ChecksumCommand(std::string &filename);

            /**
             * @brief ~ChecksumCommand - destructor
             */
            ~ChecksumCommand() override = default;

            /**
             * @brief - ChecksumCommand - copy constructor
             */
            ChecksumCommand(const ChecksumCommand &) = default;

            /**
             * @brief ChecksumCommand - move constructor
             */
            ChecksumCommand(ChecksumCommand &&) = default;

            /**
             * @brief operator= copy assignment operator
             */
            ChecksumCommand &operator=(const ChecksumCommand &) = default;

            /**
              * @brief operator= move assignment operator
              */
            ChecksumCommand &operator=(ChecksumCommand &&) = default;

            /**
             * @brief execute - override method, calculate checksum
             */
            void execute() override;


        private:
            /**
             * @brief filename_ - input file
             */
            std::string filename_;

            uint32_t checksum();
        };//class ChecksumCommand
    }//namespace command_handler
}//namespace two_gis_test


#endif //WORD_COUNTER_CHECKSUM_COMMAND_HPP
