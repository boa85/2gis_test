//
// Created by boa on 04.08.17.
//

#ifndef TWO_GIS_TEST_CHECKSUM_COMMAND_HPP
#define TWO_GIS_TEST_CHECKSUM_COMMAND_HPP

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
            explicit ChecksumCommand(const std::string &filename);

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
            /**
             * @brief checksum - calculate checksum
             * @return 32-bit checksum
             */
            uint32_t checksum();
        };//class ChecksumCommand
    }//namespace command_handler
}//namespace two_gis_test


#endif //TWO_GIS_TEST_CHECKSUM_COMMAND_HPP
