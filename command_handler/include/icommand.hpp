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

        protected:
            virtual void execute() = 0;
        };

    }
}


#endif //WORD_COUNTER_ICOMMAND_HPP
