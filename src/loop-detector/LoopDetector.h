#ifndef LOOP_DETECTION_LOOPDETECTOR_H
#define LOOP_DETECTION_LOOPDETECTOR_H


#include <Map.h>

class LoopDetector {
public:
    LoopDetector(SLAM_VIEWER::Map&);

    bool addKeyFrame(SLAM_VIEWER::KeyFrame *);
};


#endif //LOOP_DETECTION_LOOPDETECTOR_H
