cmake_minimum_required(VERSION 3.10)
project(ImgToGreyscaleCV)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "D:/Applications/Microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(OpenCV_DIR "D:/Applications/Microsoft/vcpkg/packages/opencv4_x64-windows/share/opencv4")
set(Protobuf_DIR "D:/Applications/Microsoft/vcpkg/packages/protobuf_x64-windows/share/protobuf")
set(TIFF_LIBRARY "D:/Applications/Microsoft/vcpkg/packages/tiff_x64-windows/lib")
set(TIFF_INCLUDE_DIR "D:/Applications/Microsoft/vcpkg/packages/tiff_x64-windows/include")
set(quirc_DIR "D:/Applications/Microsoft/vcpkg/packages/quirc_x64-windows/share/quirc")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add executable
add_executable(ImgToGreyscaleCV gsc-opencv.cpp "gsc-opencv.cpp")

# Link OpenCV libraries
target_link_libraries(ImgToGreyscaleCV 
    opencv_core4
    opencv_imgproc4
    opencv_highgui4
    opencv_imgcodecs4
)
