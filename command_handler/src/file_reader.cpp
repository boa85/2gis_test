//
// Created by boa on 02.08.17.
//
#include "../include/file_reader.hpp"

namespace word_counter {
    namespace file_reader {

        FileReader::FileReader() {
            text_.reserve(LINE_COUNT);
        }

        bool FileReader::read(const std::string &filename) {
            return false;
        }
    }//namespace file_reader
}//word_c
