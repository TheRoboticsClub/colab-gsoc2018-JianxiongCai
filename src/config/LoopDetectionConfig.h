#ifndef SLAM_MAPGEN_LOOPDETECTIONCONFIG_H
#define SLAM_MAPGEN_LOOPDETECTIONCONFIG_H

#include <string>
#include <opencv2/core/persistence.hpp>
#include <exception>
#include <boost/log/trivial.hpp>

namespace MapGen {
    class LoopDetectionConfig {
    public:
        explicit LoopDetectionConfig(std::string filename);

        std::string get_img_dir();

        std::string get_trajectory();

        std::string get_vocabulary();

        double get_threshold();

    private:
        std::string img_dir_;
        std::string trajectory_;
        std::string vocabulary_;
        double threshold_;
    };
}


#endif //SLAM_MAPGEN_LOOPDETECTIONCONFIG_H
