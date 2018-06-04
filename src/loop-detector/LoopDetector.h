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

#include <boost/log/trivial.hpp>

using namespace MapGen;

namespace MapGen {

    class LoopDetector {
    public:
        // perform offline loop-detection from the loop detector
        // if pretrained_voc is specified, use pretrained_voc
        LoopDetector(MapGen::Map &, const std::string &, const std::string &pretrained_voc, double loop_closure_thres);

        std::vector<std::pair<KeyFrame *, KeyFrame *>> getLoopClosingPairs();

    private:
        // iterate through all images and compute BowVector for each image
        void computeAllFeatures(MapGen::Map &, const std::string &);
        void detectLoops(MapGen::Map &map);

        double loop_closure_thres_;

        // the directory to raw RGB image
        std::string img_dir_;

        // TODO: tun the parameter of orb vocabulary
        ORBVocabularyExt voc_;
        cv::Ptr<cv::ORB> orb_;

        std::vector<std::pair<KeyFrame *, KeyFrame *>> loop_closure_pairs_;
    };

}


#endif //LOOP_DETECTION_LOOPDETECTOR_H
