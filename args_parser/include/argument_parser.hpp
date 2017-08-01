//

#pragma once
#include <boost/program_options.hpp>
#include <boost/signals2.hpp>
#include "../../service/include/service.hpp"

namespace word_counter {
    namespace argument_parser {
        namespace po=boost::program_options;
        using namespace service;
        class ArgumentParser {
        public:
            ArgumentParser();

            virtual ~ArgumentParser() = default;

            ArgumentParser(const ArgumentParser &orig) = delete;

            ArgumentParser(const ArgumentParser &&orig) = delete;

            ArgumentParser &operator=(const ArgumentParser &other) = delete;

            ArgumentParser &operator=(const ArgumentParser &&other) = delete;


            boost::signals2::signal<void(const std::string &filename, const std::string &word)> count;
            boost::signals2::signal<void(const std::string &filename)> checksum;

        private:
            /**
             * @brief generalDescription_ - command line options description
             */
            po::options_description generalDescription_;

            std::string fileName_;

            std::string mode_;

            std::string word_;

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
