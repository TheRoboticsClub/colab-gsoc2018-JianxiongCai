
#include "LoopDetector.h"

LoopDetector::LoopDetector(MapGen::Map &map, const std::string& img_dir, const std::string& pretrained_voc):
        img_dir_(img_dir) {
//    for (auto frame : map.GetAllKeyFrames()){
//        this->addKeyFrame(frame);
//    }

    // initialize variables
    orb_ = cv::ORB::create();

    // compute all features
    features_ = computeAllFeatures(map,img_dir);

    // load / create VOC
    if (pretrained_voc.size() == 0) {
        create_VOC(map);
    }
    else{
        load_voc(pretrained_voc);
    }

    // doing loop detector

    // TODO: what if the img_dir does not have tailing '/'
}


std::vector<std::vector<cv::Mat>> LoopDetector::computeAllFeatures(MapGen::Map & map, const std::string & img_dir) {

    std::vector<std::vector<cv::Mat>> features_all;
    for (MapGen::KeyFrame* frame : map.GetAllKeyFrames()){
        // read in the image
        std::string img_path = img_dir_ + frame->GetFilename();
        cv::Mat img = cv::imread(img_path);

        // compute ORB features
        cv::Mat mask;
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;
        orb_->detectAndCompute(img,mask,keypoints,descriptors);

        // change the structure of descriptors
        std::vector<cv::Mat> features;
        features.resize(descriptors.rows);
        for(int i = 0; i < descriptors.rows; ++i)
        {
            features.push_back(descriptors.row(i));
        }

        // append the features of current image to features_all
        features_all.push_back(features);
    }

    std::cout << "size of features_all: " << features_all.size() << std::endl;
}

bool LoopDetector::create_VOC(MapGen::Map& map) {
    voc_ = OrbVocabulary(9,3,DBoW2::TF_IDF, DBoW2::L1_NORM);

    // TODO: the voc clustering is using too much memory
    // create VOC
    voc_.create(features_);
}

bool LoopDetector::load_voc(const std::string& voc_fname) {
    std::cout << "Loading voc from " << voc_fname << std::endl;
    voc_.load(voc_fname);
}

std::vector<std::pair<int,int>> LoopDetector::getLoopClosingPairs(MapGen::Map& map) {
    for (MapGen::KeyFrame* frame : map.GetAllKeyFrames()){
        // read in the image
        std::string img_path = img_dir_ + frame->GetFilename();
        cv::Mat img = cv::imread(img_path);

        // compute ORB features
        cv::Mat mask;
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;
        orb_->detectAndCompute(img,mask,keypoints,descriptors);

        std::cout << "descriptors: " << descriptors.rows << std::endl;

        // change the structure of descriptors
        std::vector<cv::Mat> features;
        features.resize(descriptors.rows);
        for(int i = 0; i < descriptors.rows; ++i)
        {
            features.push_back(descriptors.row(i));
        }
    }
}