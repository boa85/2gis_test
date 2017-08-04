//
// Created by boa on 04.08.17.
//

#ifndef WORD_COUNTER_ICOMMAND_HPP
#define WORD_COUNTER_ICOMMAND_HPP

namespace word_counter {
    namespace command_handler {
        class ICommand {

        public:
            ICommand() = default;

            virtual ~ICommand() = default;
            
        protected:
            virtual void execute() = 0;
        };//class ICommand
    }//namespace command_handler
}//namespace word_counter


#endif //WORD_COUNTER_ICOMMAND_HPP
