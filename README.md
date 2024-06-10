# project-img-greyscale-conversion

## Windows
### Setup the Environment
#### 1. Install Visual Studio
Install VS 2022 Community Edition from [here](https://visualstudio.microsoft.com/downloads/).
#### 2. Install vcpkg
```cmd
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
```
#### 3. Install OpenCV
```cmd
.\vcpkg install opencv4
```
### Compile the Code
#### 1. Add the follwoing content to CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(gsc_opencv)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_TOOLCHAIN_FILE "{path/to/vcpkg.cmake}")
set(OpenCV_DIR "{path/to/share/opencv4}")
set(Protobuf_DIR "{path/to/share/protobuf")
set(TIFF_LIBRARY "{path/to/tiff/lib")
set(TIFF_INCLUDE_DIR "{path/to/tiff/include")
set(quirc_DIR "{path/to/share/quirc")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Find OpenMP package
find_package(OpenMP REQUIRED)

# Add the executable
add_executable(gsc-opencv  "gsc-opencv.cpp")

# Link libraries
target_link_libraries(gsc-opencv PUBLIC OpenMP::OpenMP_CXX)
target_link_libraries(gsc-opencv PUBLIC opencv_core4 opencv_imgcodecs4 opencv_highgui4 opencv_imgproc4)
```
##### Example
```cmake
cmake_minimum_required(VERSION 3.10)
project(gsc_opencv)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_TOOLCHAIN_FILE "D:/Applications/Microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(OpenCV_DIR "D:/Applications/Microsoft/vcpkg/packages/opencv4_x64-windows/share/opencv4")
set(Protobuf_DIR "D:/Applications/Microsoft/vcpkg/packages/protobuf_x64-windows/share/protobuf")
set(TIFF_LIBRARY "D:/Applications/Microsoft/vcpkg/packages/tiff_x64-windows/lib")
set(TIFF_INCLUDE_DIR "D:/Applications/Microsoft/vcpkg/packages/tiff_x64-windows/include")
set(quirc_DIR "D:/Applications/Microsoft/vcpkg/packages/quirc_x64-windows/share/quirc")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Find OpenMP package
find_package(OpenMP REQUIRED)

# Add the executable
add_executable(gsc-opencv  "gsc-opencv.cpp")

# Link libraries
target_link_libraries(gsc-opencv PUBLIC OpenMP::OpenMP_CXX)
target_link_libraries(gsc-opencv PUBLIC opencv_core4 opencv_imgcodecs4 opencv_highgui4 opencv_imgproc4)
```
#### 2. Compile the code using CMake
```cmd
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Run the Project
```cmd
./gsc-opencv
```

## MacOS
### Setup the Environment
#### 1. Install Xcode Command Line Tools
```zsh
xcode-select --install
```
#### 2. Install Homebrew
```zsh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
#### 3. Install OpenCV
```zsh
brew install opencv
```
#### 4. Install OpenMP
```zsh
brew install libomp
```
#### 5. Install CMake
```zsh
brew install cmake
```

### Compile the Code
#### Direct Compilation
```zsh
g++ -std=c++11 gsc-opencv.cpp -o gsc-opencv -Xpreprocessor -fopenmp -I{path/to/opencv/include} -L{path/to/openvc/lib} -I{path/to/libomp/include} -L{path/to/libomp/lib} -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lomp
```
##### Example
```zsh
g++ -std=c++11 gsc-opencv.cpp -o gsc-opencv -Xpreprocessor -fopenmp -I/opt/homebrew/include/opencv4 -L/opt/homebrew/Cellar/opencv/4.9.0_9/lib -I/opt/homebrew/Cellar/libomp/18.1.6/include -L/opt/homebrew/Cellar/libomp/18.1.6/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lomp
```
#### Compilation using CMake
#### 1. Add the follwoing content to CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(gsc_opencv)

set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for OpenCV and OpenMP
include_directories({path/to/opencv/include})
include_directories({path/to/libomp/include})

# Link directories for OpenCV and OpenMP
link_directories({path/to/opencv/lib})
link_directories({path/to/libomp/lib})

# Add the executable
add_executable(gsc-opencv gsc-opencv.cpp)

# Add OpenMP compile options for Clang
target_compile_options(gsc-opencv PRIVATE -Xpreprocessor -fopenmp)

# Link libraries
target_link_libraries(gsc-opencv PRIVATE opencv_core opencv_imgcodecs opencv_highgui omp)
```
##### Example
```cmake
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
```
#### 2. Compile the code using CMake
```zsh
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the Project
```zsh
./gsc-opencv
```
