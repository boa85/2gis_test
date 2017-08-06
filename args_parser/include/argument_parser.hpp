//

#ifndef TWO_GIS_TEST_ARGUMENT_PARSER_HPP
#define TWO_GIS_TEST_ARGUMENT_PARSER_HPP

#include <boost/program_options.hpp>
#include <boost/signals2.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

#include "../../service/include/service.hpp"


namespace two_gis_test {
    using namespace service;
    namespace po=boost::program_options;
    namespace argument_parser {

        /**
         * @class ArgumentParser
         */
        class ArgumentParser {
        public:
            /**
             * @brief ArgumentParser - default constructor, init generalDescription_
             */
            ArgumentParser();
            /**
             * @brief count - program switching signal to word count mode
             * @param filename - input file
             * @param word - search word
             */
            boost::signals2::signal<void(std::string &filename, std::string &word)> countOccurrencesWord;

            /**
             * @brief checksum - the program switching signal to the Checksum calculation mode
             * @param filename - input file
             */
            boost::signals2::signal<void(std::string &filename)> calculateChecksum;

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


            /**
             * @brief initDescriptions - init boost program options descriptions
             */
            void initDescriptions();

            /**
             * @brief prepareWordCountMode -  checks the correctness of the mode parameters and sent command to run mode
             * @param vm - boost::program_options variable map with program arguments
             */
            void prepareWordCountMode(const po::variables_map &vm);

            /**
             * @brief prepareChecksumMode - checks the correctness of the mode parameters and sent command to run mode
             * @param vm - boost::program_options variable map with program arguments
             */
            void prepareChecksumMode(const po::variables_map &vm);

            /**
             * @brief error - error handler method
             * @param errorMessage - message about error
             */
            void error(const std::string &errorMessage);

        public:
            /**
             * @brief startParsing start command line arguments parser
             * @param argc count of arguments
             * @param argv  - values of arguments
             */
            void startParsing(int argc, char *argv[]);
        };
    }//namespace argument_parser
}//namespace two_gis_test
#endif//TWO_GIS_TEST_ARGUMENT_PARSER_HPP