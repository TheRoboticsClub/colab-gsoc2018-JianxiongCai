#include <Config.h>
#include <boost/log/trivial.hpp>
#include "Map.h"
#include "LoopDetector.h"

int main (int argc, const char * argv[]){
    MapGen::Map map;

    if (argc != 3){
        BOOST_LOG_TRIVIAL(error) << "Usage error";
        return 1;
    }

    // read in the trajectory file
    if(!MapGen::Config::ReadParameters(argv[1], map)){
        BOOST_LOG_TRIVIAL(error) << "fail to read the config file";
        return 1;
    }

    // TODO: check directory exist
    std::string img_dir = std::string(argv[2]);

    // TODO: for testing only
    MapGen::LoopDetector detector(map,img_dir, "/home/ernest/SLAM/ORB_SLAM2/Vocabulary/ORBvoc.txt");

    BOOST_LOG_TRIVIAL(info) << "detector initialized";

    return 0;
}