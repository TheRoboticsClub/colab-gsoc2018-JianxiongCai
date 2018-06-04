#include "LoopDetectionConfig.h"

namespace MapGen {

    LoopDetectionConfig::LoopDetectionConfig(std::string filename) {
        cv::FileStorage fs(filename, cv::FileStorage::READ);
        if (!fs.isOpened()){
            BOOST_LOG_TRIVIAL(error) << "Fail to read the config file: " << filename;
            throw std::runtime_error("Fail to read the config file: " + filename);
        }

        // fix img_path if the user forget to add tailing '/'
        fs["img_dir"] >> img_dir_;
        if ((img_dir_.length() > 0) && (img_dir_[img_dir_.length() - 1] != '/')){
            img_dir_.push_back('/');
        }
        // TODO: check directory exist

        fs["trajectory"] >> trajectory_;
        fs["Vocabulary"] >> vocabulary_;
        fs["loop_detection_threshold"] >> threshold_;
    }

    std::string LoopDetectionConfig::get_img_dir() {return img_dir_;}
    std::string LoopDetectionConfig::get_trajectory() {return trajectory_;}
    std::string LoopDetectionConfig::get_vocabulary() {return vocabulary_;}
    double LoopDetectionConfig::get_threshold() {return threshold_;}

}