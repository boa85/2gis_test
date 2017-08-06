//
// Created by boa on 06.08.17.
//

#include "../include/service.hpp"

namespace two_gis_test {

    namespace service {

        namespace fs=boost::filesystem;

        bool isValidFile(const std::string &filename, boost::system::error_code &errorCode) {
            return (fs::exists(filename, errorCode) && fs::is_regular(filename, errorCode));
        }
    }//namespace service
}//namespace two_gis_test
