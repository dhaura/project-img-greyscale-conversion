cmake_minimum_required(VERSION 3.10)
project(ImgToGrayscaleCV)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "D:/Applications/Microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(OpenCV_DIR "D:/Applications/Microsoft/vcpkg/packages/opencv2_x64-windows/share/opencv2")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add executable
add_executable(ImgToGrayscaleCV gsc-opencv.cpp "gsc-opencv.cpp")

# Link OpenCV libraries
target_link_libraries(ImgToGrayscaleCV 
    opencv_core 
    opencv_imgproc 
    opencv_highgui 
)
