//
// Created by ernest on 18-5-27.
//

#include <iostream>
#include "LoopDetector.h"

LoopDetector::LoopDetector(SLAM_VIEWER::Map &map) {
    for (auto frame : map.GetAllKeyFrames()){
        this->addKeyFrame(frame);
    }
}

bool LoopDetector::addKeyFrame(SLAM_VIEWER::KeyFrame * frame) {
    // read in the image path
    if (frame->GetFilename().empty()){
        printf("[ERROR] frame %d does not have attached filename\n", frame->GetId());
        return false;
    }

    // Extract ORB feature out


    // match against previous image seen before


    // Add ORB feature to DBoW2

    

}