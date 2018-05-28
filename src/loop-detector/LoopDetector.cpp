
#include "LoopDetector.h"

LoopDetector::LoopDetector(SLAM_VIEWER::Map &map, const std::string& img_dir):
        img_dir_(img_dir) {
//    for (auto frame : map.GetAllKeyFrames()){
//        this->addKeyFrame(frame);
//    }

    voc_ = OrbVocabulary(9,3,DBoW2::TF_IDF, DBoW2::L1_NORM);
    orb_ = cv::ORB::create();

    // TODO: what if the img_dir does not have tailing '/'

    auto features_all = computeAllFeatures(map,img_dir);

    // create VOC
    voc_.create(features_all);

    int debug = 1;
}

bool LoopDetector::addKeyFrame(SLAM_VIEWER::KeyFrame * frame) {
    // read in the image path
    std::string img_path = img_dir_ + frame->GetFilename();
    if (img_path.empty()){
        printf("[ERROR] frame %d does not have attached filename\n", frame->GetId());
        return false;
    }

    auto img = cv::imread(img_path);
//    cv::imshow("img",img);
//    cv::waitKey(0);


    // match against previous image seen before


    // Add ORB feature to DBoW2

}

std::vector<std::vector<cv::Mat>> LoopDetector::computeAllFeatures(SLAM_VIEWER::Map & map, const std::string & img_dir) {

    std::vector<std::vector<cv::Mat>> features_all;
    for (SLAM_VIEWER::KeyFrame* frame : map.GetAllKeyFrames()){
        // read in the image
        std::string img_path = img_dir_ + frame->GetFilename();
        cv::Mat img = cv::imread(img_path);

//        cv::imshow("img",img);
//        cv::waitKey(0);

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

        // append the features of current image to features_all
        features_all.push_back(features);
    }

    std::cout << "size of features_all: " << features_all.size() << std::endl;

}