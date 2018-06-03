#include <boost/log/trivial.hpp>
#include "LoopDetector.h"

namespace MapGen {

    LoopDetector::LoopDetector(MapGen::Map &map, const std::string &img_dir, const std::string &pretrained_voc) :
            img_dir_(img_dir) {
        // initialize variables
        orb_ = cv::ORB::create();

        // compute all features
        features_ = computeAllFeatures(map, img_dir);

        BOOST_LOG_TRIVIAL(info) << "Loading voc from " << pretrained_voc;
        voc_.loadFromTextFile(pretrained_voc);
        BOOST_LOG_TRIVIAL(info) << "Loaded voc from " << pretrained_voc;

        // doing loop detector

        // TODO: what if the img_dir does not have tailing '/'
    }


    std::vector<std::vector<cv::Mat>> LoopDetector::computeAllFeatures(MapGen::Map &map, const std::string &img_dir) {

        std::vector<std::vector<cv::Mat>> features_all;
        for (MapGen::KeyFrame *frame : map.GetAllKeyFrames()) {
            // read in the image
            std::string img_path = img_dir_ + frame->GetFilename();
            cv::Mat img = cv::imread(img_path);

            // compute ORB features
            cv::Mat mask;
            std::vector<cv::KeyPoint> keypoints;
            cv::Mat descriptors;
            orb_->detectAndCompute(img, mask, keypoints, descriptors);

            // change the structure of descriptors
            std::vector<cv::Mat> features;
            features.resize(descriptors.rows);
            for (int i = 0; i < descriptors.rows; ++i) {
                features.push_back(descriptors.row(i));
            }

            // append the features of current image to features_all
            features_all.push_back(features);
        }

        BOOST_LOG_TRIVIAL(info) << "size of features_all: " << features_all.size();
    }

    std::vector<std::pair<int, int>> LoopDetector::getLoopClosingPairs(MapGen::Map &map) {
        for (MapGen::KeyFrame *frame : map.GetAllKeyFrames()) {
            // read in the image
            std::string img_path = img_dir_ + frame->GetFilename();
            cv::Mat img = cv::imread(img_path);

            // compute ORB features
            cv::Mat mask;
            std::vector<cv::KeyPoint> keypoints;
            cv::Mat descriptors;
            orb_->detectAndCompute(img, mask, keypoints, descriptors);

            BOOST_LOG_TRIVIAL(info) << "total " << descriptors.rows << " descriptors";

            // change the structure of descriptors
            std::vector<cv::Mat> features;
            features.resize(descriptors.rows);
            for (int i = 0; i < descriptors.rows; ++i) {
                features.push_back(descriptors.row(i));
            }
        }
    }

}
