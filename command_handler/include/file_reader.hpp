//
// Created by boa on 02.08.17.
//

#ifndef WORD_COUNTER_FILE_READER_HPP
#define WORD_COUNTER_FILE_READER_HPP

#include <functional>
#include "../../service/include/service.hpp"

namespace word_counter {
    using namespace service;
    namespace file_reader {
        class FileReader {

        public:
            FileReader();

            virtual ~FileReader() = default;

            bool read(const std::string &filename);

        private:
            Text text_;
            const unsigned LINE_COUNT = 1000;
        };//class FileReader
    }//namespace file_reader
}//namespace word_counter



#endif //WORD_COUNTER_FILE_READER_HPP
