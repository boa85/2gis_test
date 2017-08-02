//

#pragma once
#include <boost/program_options.hpp>
#include <boost/signals2.hpp>
#include "../../service/include/service.hpp"

namespace word_counter {
    namespace argument_parser {
        namespace po=boost::program_options;
        using namespace service;

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
             * @brief filename_ - input filename
             */
            std::string fileName_;
            /**
             * @brief mode_ - string program mode: WORDS, CHECKSUM
             */
            std::string mode_;
            /**
             * @brief word_ search word
             */
            std::string word_;
            /**
             * @brief -
             */
            MODE mode;

            /**
             * @brief initDescriptions - init boost program options descriptions
             */
            void initDescriptions();

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
