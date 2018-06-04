#include <opencv2/core/core.hpp>

int main(int argc, const char * argv[]){
    cv::FileStorage fs("loop_detector_config.yaml",cv::FileStorage::WRITE);
    fs << "img_dir" << "/home/ernest/SLAM/datasets/sequence_43/images/";
    fs << "trajectory" << "/home/ernest/SLAM/datasets/trajectory/trajectory_noloop.yaml";
    fs << "Vocabulary" << "/home/ernest/SLAM/colab-gsoc2018-JianxiongCai/Vocabulary/ORBvoc.txt";
    fs << "loop_detection_threshold" << 0.575;

    fs.release();

    return 0;
}