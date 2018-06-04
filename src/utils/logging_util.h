#ifndef SLAM_MAPGEN_LOGGING_UTIL_H
#define SLAM_MAPGEN_LOGGING_UTIL_H

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

void init_logging(){
    boost::log::core::get()->set_filter(
            boost::log::trivial::severity >= boost::log::trivial::info
    );
}

#endif //SLAM_MAPGEN_LOGGING_UTIL_H
