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

/*
            std::tuple getOptions(){
                return mode == WORDS ? std::make_tuple(mode, fileName_, word_) : mode == CHECKSUM ?
                       std::make_tuple((mode, fileName_)) : std::make_tuple("fig vam");
            }
*/
        };
    }//namespace argument_parser
}//namespace word_counter
