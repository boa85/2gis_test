//


#ifndef WORD_COUNTER_SERVICE_HPP
#define WORD_COUNTER_SERVICE_HPP

#include <vector>
#include <string>
namespace word_counter {
    namespace service {
        typedef std::vector<std::string> Text;
        enum MODE {
            WORDS,
            CHECKSUM,
            UNKNOWN
        };
    }
}
#endif//WORD_COUNTER_SERVICE_HPP