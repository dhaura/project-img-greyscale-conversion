cmake_minimum_required(VERSION 3.10)
project(gsc_opencv)

set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for OpenCV and OpenMP
include_directories(/opt/homebrew/include/opencv4)
include_directories(/opt/homebrew/Cellar/libomp/18.1.6/include)

# Link directories for OpenCV and OpenMP
link_directories(/opt/homebrew/Cellar/opencv/4.9.0_9/lib)
link_directories(/opt/homebrew/Cellar/libomp/18.1.6/lib)

# Add the executable
add_executable(gsc-opencv gsc-opencv.cpp)

# Add OpenMP compile options for Clang
target_compile_options(gsc-opencv PRIVATE -Xpreprocessor -fopenmp)

# Link libraries
target_link_libraries(gsc-opencv PRIVATE opencv_core opencv_imgcodecs opencv_highgui omp)
