//
// Created by boa on 04.08.17.
//

#include <iostream>
#include <fstream>

#include "../include/checksum_command.hpp"
#include "../../service/include/service.hpp"

namespace word_counter {

    namespace command_handler {
        using namespace service;

        ChecksumCommand::ChecksumCommand(std::string &filename)
                : filename_(std::move(filename)) {}

        void ChecksumCommand::execute() {
            boost::system::error_code errorCode;
            if (isValidFile(filename_, errorCode)) {
                std::cout << checksum() << std::endl;
                return;
            }
            throw std::runtime_error(errorCode.message());
        }//execute

        uint32_t ChecksumCommand::checksum() {
            std::ifstream input(filename_, std::ios::binary | std::ios::ate);
            if (input.is_open()) {
                const auto WORD_SIZE = sizeof(uint32_t);
                input.seekg(0, std::ios::end);
                auto sizeInBytes = input.tellg();
                input.seekg(0);
                uint32_t checksum = 0U;
                if (auto sizeInEntireWords = sizeInBytes / WORD_SIZE) {
                    for (auto i = 0; i < sizeInEntireWords; i++) {
                        uint32_t word;
                        input.read(reinterpret_cast<char *>(&word), WORD_SIZE);
                        checksum += word;
                    }
                }

                if (auto additionalSizeInBytes = sizeInBytes % WORD_SIZE) {
                    uint32_t word;
                    input.read(reinterpret_cast<char *>(&word), WORD_SIZE);
                    word &= (~0U << (WORD_SIZE - additionalSizeInBytes * 8));
                    checksum += word;
                }
                return checksum;
            }
            throw std::runtime_error("cannot open file " + filename_);
        }


    }//namespace command_handler
}//namespace word_counter

