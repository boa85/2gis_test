//
// Created by boa on 04.08.17.
//

#ifndef TWO_GIS_TEST_ICOMMAND_HPP
#define TWO_GIS_TEST_ICOMMAND_HPP

namespace two_gis_test {
    namespace command_handler {
        /**
         * @class ICommand - pattern Command interface
         */
        class ICommand {

        public:
            /**
             * @brief ICommand - default constructor
             */
            ICommand() = default;

            /**
             * @brief ~ICommand - destructor
             */
            virtual ~ICommand() = default;


            /**
             * @brief -  copy constructor
             */
            ICommand(const ICommand &) = default;

            /**
             * @brief  - move constructor
             */
            ICommand(ICommand &&) = default;

            /**
             * @brief operator= copy assignment operator
             */
            ICommand &operator=(const ICommand &) = default;

            /**
             * @brief operator= move assignment operator
             */
            ICommand &operator=(ICommand &&) = default;


            /**
             * @brief execute - pure virtual method, override in derived classes
             */
            virtual void execute() = 0;
        };//class ICommand
    }//namespace command_handler
}//namespace two_gis_test


#endif //TWO_GIS_TEST_ICOMMAND_HPP
