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
#include "ORBVocabularyExt.h"

namespace MapGen {

    class LoopDetector {
    public:
        // perform offline loop-detection from the loop detector
        // if pretrained_voc is specified, use pretrained_voc
        LoopDetector(MapGen::Map &, const std::string &, const std::string &pretrained_voc = "");

        std::vector<std::pair<int, int>> getLoopClosingPairs(MapGen::Map &map);

    private:
        // iterate through all images and compute BowVector for each image
        void computeAllFeatures(MapGen::Map &, const std::string &);
        void detectLoops(MapGen::Map &map);

        // the directory to raw RGB image
        std::string img_dir_;

        // TODO: tun the parameter of orb vocabulary
        ORBVocabularyExt voc_;
        cv::Ptr<cv::ORB> orb_;
        std::vector<std::vector<cv::Mat>> features_;

        std::vector<std::pair<int, int>> loop_closure_pairs_;
    };

}


#endif //LOOP_DETECTION_LOOPDETECTOR_H
