cmake_minimum_required(VERSION 3.0)
project(loop-detection)

set(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED)

# DBoW2
find_package( DBoW2 REQUIRED)
include_directories(${DBoW2_INCLUDE_DIRS})
find_package( DLib REQUIRED)
include_directories(${DLib_INCLUDE_DIRS})


# Loop-detector
file(GLOB loop_detector_src src/loop-detector/*)
add_executable(loop_detection ${loop_detector_src} )
target_link_libraries( loop_detection ${OpenCV_LIBS}
        ${DBoW2_LIBS} ${DLib_LIBS}
        )