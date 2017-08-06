//
// Created by boa on 04.08.17.
//
#include <iostream>
#include <fstream>
#include <boost/system/error_code.hpp>


#include "../include/count_occurrences_word_command.hpp"
#include "../../service/include/service.hpp"

namespace word_counter {

    namespace command_handler {
        using namespace service;
        CountOccurrencesWordCommand::CountOccurrencesWordCommand(std::string &filename,
                                                                 std::string &searchWord)
                : filename_(std::move(filename)),
                  searchWord_(std::move(searchWord)) {

        }

        void CountOccurrencesWordCommand::execute() {
            boost::system::error_code errorCode;
            if (isValidFile(filename_, errorCode)) {
                std::ifstream input(filename_);
                if (input.is_open()) {
                    auto counter = 0;
                    std::string line;
                    while (getline(input, line)) {
                        std::vector<int> pi = prefixFunction(searchWord_ + '#' + line);
                        auto length = searchWord_.length();
                        for (auto i = 0; i < line.length(); i++) {
                            if (pi[length + 1 + i] == length) {
                                ++counter;
                            }
                        }
                    }
                    input.close();
                    std::cout << "find " << counter << " occurrences" << std::endl;
                    return;
                }
                throw std::runtime_error("cannot open file " + filename_);
            }
            throw std::runtime_error(errorCode.message());
        }//execution

        std::vector<int> CountOccurrencesWordCommand::prefixFunction(const std::string &s) {
            std::vector<int> pi(s.length(), 0);
            for (int i = 1; i < s.length(); i++) {
                int j = pi[i - 1];
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

    }//namespace command_handler
}//namespace word_counter

