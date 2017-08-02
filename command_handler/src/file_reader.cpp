//
// Created by boa on 02.08.17.
//
#include "../include/file_reader.hpp"
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace word_counter {
    namespace file_reader {
        namespace fs=boost::filesystem;

        FileReader::FileReader() {
            init();
        }

        void FileReader::read(const std::string &filename) {
            if (fs::exists(filename) && fs::is_regular(filename)) {
                fs::ifstream in(filename);
                if (!in.is_open()) {
                    throw std::runtime_error("cannot open file");
                }
                std::string string;

                while (getline(in, string)) {
                    text_.push_back(string);
                }
                getText(text_);
                return;
            }
            throw std::logic_error("file " + filename + " is not a regular file");
        }

        void FileReader::init() {
            text_.reserve(LINE_COUNT);
            for (auto s : text_) {
                s.reserve(LENGTH);
            }
        }
    }
}
