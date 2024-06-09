# project-img-greyscale-conversion

### Compile the Code
#### 1. Direct Compilation
```zsh
g++ -std=c++11 gsc-opencv.cpp -o gsc-opencv -Xpreprocessor -fopenmp -I/opt/homebrew/include/opencv4 -L/opt/homebrew/Cellar/opencv/4.9.0_9/lib -I/opt/homebrew/Cellar/libomp/18.1.6/include -L/opt/homebrew/Cellar/libomp/18.1.6/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lomp
```
#### 2. Compilation using CMake
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
