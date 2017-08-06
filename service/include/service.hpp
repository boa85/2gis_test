//


#ifndef WORD_COUNTER_SERVICE_HPP
#define WORD_COUNTER_SERVICE_HPP

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
namespace word_counter {

    namespace service {
        namespace fs=boost::filesystem;
        /**
         * @brief isValidFile - checks the existence of the file and its status
         * @param filename - filename
         * @param errorCode - boost::system::error_code, return system error message
         * @return true, if a file exists and it is a regular file
         */
        bool isValidFile(const std::string &filename, boost::system::error_code &errorCode) {
            return (fs::exists(filename, errorCode) && fs::is_regular(filename, errorCode));
        }
    }
}
#endif//WORD_COUNTER_SERVICE_HPP