#include <boost/log/trivial.hpp>

//int main(int argc, char * argv[]){
//    // testing glog
//    google::InitGoogleLogging(argv[0]);
//    FLAGS_minloglevel = 0;
//    FLAGS_stderrthreshold = 0;
//
//    LOG(INFO) << "Hello world";
//    LOG(ERROR) << "This is an error";
//}

int main(int argc, const char * argv[]){
    BOOST_LOG_TRIVIAL(info) << "Hello world";
    BOOST_LOG_TRIVIAL(info) << "Hello world";
    BOOST_LOG_TRIVIAL(info) << "Hello world";
}