#include <Config.h>
#include <boost/log/trivial.hpp>
#include "Map.h"
#include "LoopDetector.h"

int main (int argc, const char * argv[]){
    if (argc != 1){
        BOOST_LOG_TRIVIAL(error) << "Usage error";
        return 1;
    }

    MapGen::Map map;
    cv::FileStorage config(argv[1], cv::FileStorage::READ);
    if (!config.isOpened()){
        BOOST_LOG_TRIVIAL(error) << "Fail to read the config file: " << argv[1];
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
    MapGen::LoopDetector detector(map,img_dir, "/home/ernest/SLAM/ORB_SLAM2/Vocabulary/ORBvoc.txt", 0.575);

    // print out the loop detection pair
    auto closing_pairs = detector.getLoopClosingPairs();
    for (auto p : closing_pairs){
        BOOST_LOG_TRIVIAL(info) << "detected loop closing pair: " << p.first->GetFilename() << " & "
                                << p.second->GetFilename();
    }

    BOOST_LOG_TRIVIAL(info) << "detector initialized";

    return 0;
}