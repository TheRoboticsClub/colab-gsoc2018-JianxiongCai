#ifndef LOOP_DETECTION_LOOPDETECTOR_H
#define LOOP_DETECTION_LOOPDETECTOR_H


#include <Map.h>

class LoopDetector {
public:
    LoopDetector(SLAM_VIEWER::Map&, const std::string&);

    bool addKeyFrame(SLAM_VIEWER::KeyFrame *);

private:
    // the directory to raw RGB image
    std::string img_dir_;
};


#endif //LOOP_DETECTION_LOOPDETECTOR_H
