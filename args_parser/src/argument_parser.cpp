//

#include "../include/argument_parser.hpp"

using namespace boost::system;
namespace word_counter {
    namespace argument_parser {
        ArgumentParser::ArgumentParser()
                : generalDescription_("program options") {
            initDescriptions();
        }

        void ArgumentParser::initDescriptions() {
            generalDescription_.add_options()
                    ("help,h", "\nsimple word counter\n"
                            "author: boa85\n"
                            "program options: \n "
                            "mode, filename, word\n"
                            "e.g ./word_counter -f Test.tst -m words -v mother - \n prints the number of the word \"mother\" in the Test.tst file"
                            "\n or \n "
                            "./word_counter -f Test.tst -m checksum - prints a 32-bit checksum\n ")
                    ("mode,m", po::value<std::string>(&mode_)->required(),
                     "program mode: words, checksum");
            wordCountDescription_.add_options()
                    ("file,f", po::value<std::string>(),
                     "input filename, e.g. Test.tst")
                    ("word,w", po::value<std::string>(),
                     " search word");
            checksumDescription_.add_options()
                    ("file,f", po::value<std::string>(),
                     "input filename, e.g. Test.tst");
        }

        void ArgumentParser::startParsing(int argc, char *argv[]) {
            po::variables_map vm;//
            po::parsed_options parsed =//magic
                    po::command_line_parser(argc, argv).options(generalDescription_).allow_unregistered().run();

            po::store(parsed, vm);//more magic
            po::notify(vm);//even more magic

            if (vm.count("help") != 0u) {//if found a help flag
                std::cout << generalDescription_;//show help
                return;
            }
            if (mode_ == "word") {//check program mode
                generalDescription_.add(wordCountDescription_);//add WORD_COUNT mode options descriptions
                po::store(po::parse_command_line(argc, argv, generalDescription_), vm);//parse options
                prepareWordCountMode(vm);
            } else if (mode_ == "checksum") {
                generalDescription_.add(checksumDescription_);
                po::store(po::parse_command_line(argc, argv, generalDescription_), vm);
                prepareChecksumMode(vm);
            } else {
                error("unknown program mode");
            }
        }

        void ArgumentParser::prepareWordCountMode(const po::variables_map &vm) {
            std::string filename;
            std::string word;
            const auto fKey = "file";
            const auto wKey = "word";
            if (vm.count(fKey) != 0u) {
                filename = vm[fKey].as<std::string>();
                if (filename.empty()) {
                    error("empty value of the filename argument");
                }
            } else {
                error("the option \"filename\" is required but missing");
            }
            if (vm.count(wKey) != 0u) {
                word = vm[wKey].as<std::string>();
                if (word.empty()) {
                    error("empty value of the search word argument");
                }
            } else {
                error("the option \"search word \" is required but missing");
            }
            boost::system::error_code errorCode;
            if (isValidFile(filename, errorCode)) {
                count(filename, word);
            } else {
                error("invalid value " + filename + " " + errorCode.message());
            }
        }

        void ArgumentParser::prepareChecksumMode(const po::variables_map &vm) {
            std::string filename;
            const auto key = "file";
            if (vm.count(key) != 0u) {
                filename = vm[key].as<std::string>();
                if (filename.empty()) {
                    error("empty value of the filename argument");
                }
            }
            boost::system::error_code errorCode;
            if (isValidFile(filename, errorCode)) {
                checksum(filename);
            }
        }

        void ArgumentParser::error(const std::string &errorMessage) {
            std::cout << errorMessage << std::endl << "See help " << std::endl << generalDescription_ << std::endl;
            throw std::invalid_argument(errorMessage);
        }

        bool ArgumentParser::isValidFile(const std::string &filename, boost::system::error_code &errorCode) {
            return (fs::exists(filename, errorCode) && fs::is_regular(filename, errorCode));
        }
    }//namespace argument_parser
}//namespace word_counter
