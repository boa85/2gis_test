//

#pragma once
#include <boost/program_options.hpp>
#include <boost/signals2.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

#include "../../service/include/service.hpp"


namespace word_counter {
    using namespace service;
    namespace po=boost::program_options;
    namespace fs=boost::filesystem;
    namespace argument_parser {

        /**
         * @class ArgumentParser
         */
        class ArgumentParser {
        public:
            /**
             * @brief ArgumentParser
             */
            ArgumentParser();

            virtual ~ArgumentParser() = default;

            //copies and assigned constructors and operators has been forbidden
            ArgumentParser(const ArgumentParser &orig) = delete;

            ArgumentParser(const ArgumentParser &&orig) = delete;

            ArgumentParser &operator=(const ArgumentParser &other) = delete;

            ArgumentParser &operator=(const ArgumentParser &&other) = delete;

            /**
             * @brief count - program switching signal to word count mode
             * @param filename - input file
             * @param word - search word
             */
            boost::signals2::signal<void(const std::string &filename, const std::string &word)> count;

            /**
             * @brief checksum - the program switching signal to the Checksum calculation mode
             * @param filename - input file
             */
            boost::signals2::signal<void(const std::string &filename)> checksum;

        private:
            /**
             * @brief generalDescription_ - command line options description
             */
            po::options_description generalDescription_;

            /**
             * @brief wordCountDescription_ - word count mode description
             */
            po::options_description wordCountDescription_;

/**
             * @brief checksumDescription_ - checksum mode description
             */
            po::options_description checksumDescription_;

            /**
             * @brief mode_ - string program mode: WORDS, CHECKSUM
             */
            std::string mode_;

            std::string filename_;
            std::string searchWord_;
            /**
             * @brief initDescriptions - init boost program options descriptions
             */
            void initDescriptions();

            void prepareWordCountMode(const po::variables_map &vm);

            void prepareChecksumMode(const po::variables_map &vm);

            void error(const std::string &errorMessage);

            bool isValidFile(const std::string &filename, boost::system::error_code &errorCode);
        public:
            /**
             * @brief startParsing start command line arguments parser
             * @param argc count of arguments
             * @param argv  - arguments
             */
            void startParsing(int argc, char *argv[]);


        };
    }//namespace argument_parser
}//namespace word_counter
