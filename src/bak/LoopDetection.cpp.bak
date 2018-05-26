#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>

#include "DBoW2.h"

// Note: It only relies on the RGB image now
// TODO: add the trajectory for loop detection (proposal) maybe
//      Advantage: avoid similar problem

// TODO: add YAML parser for parsing config (or use OpenCV directly)


/*
 * Acknowledgement: Some functions are from DBoW
 * TODO: A formal license and acknowledgement maybe
 */

using namespace std;

// Read In the keyframe ids from the file
bool readInFS(std::vector<std::string>& keyframe_names, const std::string file_name){
    cv::FileStorage fs;
    fs.open(file_name,cv::FileStorage::READ);

    if (!fs.isOpened()){
        std::cerr << "[ERROR] error encountered on reading fs" << std::endl;
        return false;
    }

    cv::FileNode keyframes = fs["keyframes"];
    for (auto it = keyframes.begin(); it != keyframes.end(); it++){
        std::string tmp_name;
        (*it)["filename"] >> tmp_name;
        keyframe_names.push_back(tmp_name);
        // std::cout << tmp_name << std::endl;
    }

    return true;
}


void changeStructure(const cv::Mat &plain, vector<cv::Mat> &out)
{
    out.resize(plain.rows);

    for(int i = 0; i < plain.rows; ++i)
    {
        out[i] = plain.row(i);
    }
}

void loadFeatures(std::vector<std::string> keyframe_names, std::string img_directory)
{
    std::cout << "[INFO] extracting all features" << std::endl;
    vector<vector<cv::Mat>> features;
    features.clear();
    features.reserve(keyframe_names.size());

    cv::Ptr<cv::ORB> orb = cv::ORB::create();

    for(int i = 0; i < keyframe_names.size(); ++i)
    {
        std::string img_name = img_directory + keyframe_names[i];

        cv::Mat image = cv::imread(img_name, 0);
        cv::Mat mask;
        vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;

        orb->detectAndCompute(image, mask, keypoints, descriptors);

        // TODO: rewrite this. It's wried to do it in this way
        features.push_back(vector<cv::Mat >());
        changeStructure(descriptors, features.back());
    }
}


int main(int argc, const char * argv[]) {
    // read in the keyframe ids from file storage
    std::vector<std::string> keyframe_names;
    readInFS(keyframe_names, "/home/ernest/SLAM/loop-detection/trajectory_noloop.yaml");
    if (keyframe_names.size() == 0){
        std::cerr << "[ERROR] No keyframe in the file storage" << std::endl;
    }

    // add each keyframe to DBoW


    // check if this keyframe has appeared before, if appear, preform operation like loop closure
    // Just for simplicity, output the loop detection keyframe id.



    return 0;
}