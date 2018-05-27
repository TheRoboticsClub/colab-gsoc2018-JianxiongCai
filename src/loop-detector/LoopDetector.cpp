
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <DBoW2.h>
#include "LoopDetector.h"

LoopDetector::LoopDetector(SLAM_VIEWER::Map &map, const std::string& img_dir):
        img_dir_(img_dir) {
    for (auto frame : map.GetAllKeyFrames()){
        this->addKeyFrame(frame);
    }
}

bool LoopDetector::addKeyFrame(SLAM_VIEWER::KeyFrame * frame) {
    // read in the image path
    std::string img_path = img_dir_ + frame->GetFilename();
    if (img_path.empty()){
        printf("[ERROR] frame %d does not have attached filename\n", frame->GetId());
        return false;
    }

//    auto img = cv::imread(img_path);
//    cv::imshow("img",img);
//    cv::waitKey(0);

    // Extract ORB feature out



    // match against previous image seen before


    // Add ORB feature to DBoW2

}