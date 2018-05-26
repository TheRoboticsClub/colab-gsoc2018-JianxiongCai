cmake_minimum_required(VERSION 3.0)
project(loop-detection)

set(CMAKE_CXX_STANDARD 11)

# Eigen
find_package(Eigen3 REQUIRED)
include_directories(
        ${EIGEN3_INCLUDE_DIR}
)
# OpenCV
find_package( OpenCV REQUIRED)
# DBoW2
find_package( DBoW2 REQUIRED)
include_directories(${DBoW2_INCLUDE_DIRS})
find_package( DLib REQUIRED)
include_directories(${DLib_INCLUDE_DIRS})

# src
include_directories(src/common)
include_directories(src/loop-detector)

# common
file(GLOB common_src src/common/*)

# Loop-detector
file(GLOB loop_detector_src src/loop-detector/*)
add_executable(loop_detection ${loop_detector_src} ${common_src} src/loop-detector/LoopDetector.cpp src/loop-detector/LoopDetector.h)
target_link_libraries( loop_detection ${OpenCV_LIBS}
        ${DBoW2_LIBS} ${DLib_LIBS}
        )