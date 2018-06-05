#include "Config.h"
#include "LoopDetectionConfig.h"
#include "Map.h"
#include "LoopDetector.h"
#include "logging_util.h"

using namespace MapGen;

int main (int argc, const char * argv[]){
    init_logging();

    if (argc != 2){
        BOOST_LOG_TRIVIAL(error) << "Usage error";
        return 1;
    }


    LoopDetectionConfig config(argv[1]);
    Map map;

    // read in the trajectory file
    if(!MapGen::Config::ReadParameters(config.get_trajectory(), map)){
        BOOST_LOG_TRIVIAL(error) << "fail to read the trajectory file at: " << config.get_trajectory();
        return 1;
    }

    // detect loops
    MapGen::LoopDetector detector(map,config.get_img_dir(), config.get_vocabulary(), config.get_threshold());

    // print out the loop detection pair
    auto closing_pairs = detector.getLoopClosingPairs();
    for (auto p : closing_pairs){
        BOOST_LOG_TRIVIAL(info) << "detected loop closing pair: " << p.first->GetFilename() << " & "
                                << p.second->GetFilename();
    }

    BOOST_LOG_TRIVIAL(info) << "Detection Completed";

    return 0;
}