cmake_minimum_required(VERSION 2.8)
project(loop_detection)

set(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED )

add_executable(loop_detection LoopDetection.cpp)
target_link_libraries( loop_detection ${OpenCV_LIBS} )