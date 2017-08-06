//
// Created by boa on 04.08.17.
//
#include <iostream>
#include <fstream>
#include <boost/system/error_code.hpp>


#include "../include/count_occurrences_word_command.hpp"
#include "../../service/include/service.hpp"

namespace two_gis_test {

    namespace command_handler {
        using namespace service;
        CountOccurrencesWordCommand::CountOccurrencesWordCommand(const std::string &filename,
                                                                 const std::string &searchWord)
                : filename_(filename),
                  searchWord_(searchWord) {}

        void CountOccurrencesWordCommand::execute() {
            boost::system::error_code errorCode;
            if (!isValidFile(filename_, errorCode)) {
                throw std::runtime_error(errorCode.message());
            }
            std::cout << "find " << countOccurrences() << " occurrences" << std::endl;
        }//execution

        std::vector<int> CountOccurrencesWordCommand::prefixFunction(const std::string &s) {
            std::vector<int> pi(s.length(), 0);
            for (size_t i = 1; i < s.length(); i++) {
                auto j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1];
                }
                if (s[i] == s[j]) {
                    pi[i] = j + 1;
                } else {
                    pi[i] = j;
                }
            }
            return pi;
        }//prefixFunction

        int CountOccurrencesWordCommand::countOccurrences() {
            std::ifstream input(filename_);
            if (!input.is_open()) {
                throw std::runtime_error("cannot open file " + filename_);
            }
            auto counter = 0;
            std::string line;
            while (getline(input, line)) {
                std::vector<int> pi = prefixFunction(searchWord_ + '#' + line);
                size_t length = searchWord_.length();
                for (size_t i = 0; i < line.length(); i++) {
                    if (pi[length + 1 + i] == length) {
                        ++counter;
                    }
                }
            }
            input.close();
            return counter;
        }//countOccurrences


    }//namespace command_handler
}//namespace two_gis_test

