cmake_minimum_required(VERSION 3.10)
project(ImgToGreyscaleCV)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "D:/Applications/Microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(OpenCV_DIR "D:/Applications/Microsoft/vcpkg/packages/opencv2_x64-windows/share/opencv2")

message("include => ${OpenCV_INCLUDE_DIRS}")
message("link => ${OpenCV_LIBS}")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add executable
add_executable(ImgToGreyscaleCV gsc-opencv.cpp "gsc-opencv.cpp")

# Link OpenCV libraries
target_link_libraries(ImgToGreyscaleCV 
    opencv_core2
    opencv_imgproc2
    opencv_highgui2
)
