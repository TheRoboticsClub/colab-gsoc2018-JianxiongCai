#include <Config.h>
#include "Map.h"
#include "LoopDetector.h"

int main (int argc, const char * argv[]){
    SLAM_VIEWER::Map map;

    if (argc != 3){
        std::cerr << "[ERROR] Usage error. " << std::endl;
        return 1;
    }

    // read in the trajectory file
    if(!SLAM_VIEWER::Config::ReadParameters(argv[1], map)){
        std::cerr << "[ERROR] fail to read the config file" << std::endl;
        return 1;
    }

    // TODO: check directory exist
    std::string img_dir = std::string(argv[2]);

    LoopDetector detector(map,img_dir);

    return 0;
}