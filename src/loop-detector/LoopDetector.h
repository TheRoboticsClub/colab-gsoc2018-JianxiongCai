#ifndef LOOP_DETECTION_LOOPDETECTOR_H
#define LOOP_DETECTION_LOOPDETECTOR_H


#include <Map.h>
#include <iostream>

// opencv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>

// DBoW
#include <DBoW2.h>
#include <BowVector.h>

class LoopDetector {
public:
    // perform offline loop-detection from the loop detector
    LoopDetector(SLAM_VIEWER::Map&, const std::string&);

private:
    // iterate through all images and compute all features (ORB)
    std::vector<std::vector<cv::Mat>> computeAllFeatures(SLAM_VIEWER::Map&, const std::string&);

    bool addKeyFrame(SLAM_VIEWER::KeyFrame *);


    // the directory to raw RGB image
    std::string img_dir_;

    // TODO: tun the parameter of orb vocabulary
    OrbVocabulary voc_;
    cv::Ptr<cv::ORB> orb_;
    std::vector<std::vector<cv::Mat>> features_;
};


#endif //LOOP_DETECTION_LOOPDETECTOR_H
