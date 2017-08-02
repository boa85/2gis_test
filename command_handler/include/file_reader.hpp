//
// Created by boa on 02.08.17.
//

#ifndef WORD_COUNTER_FILE_READER_HPP
#define WORD_COUNTER_FILE_READER_HPP

#include "../../service/include/service.hpp"
#include <boost/signals2.hpp>

namespace word_counter {
    using namespace service;
    namespace file_reader {
        class FileReader {
        public:
            FileReader();

            void read(const std::string &filename);

            boost::signals2::signal<void(const Text &)> getText;
        private:
            const unsigned LINE_COUNT = 1000;
            const unsigned LENGTH = 255;
            Text text_;

            void init();
        };

    }
}

#endif //WORD_COUNTER_FILE_READER_HPP
