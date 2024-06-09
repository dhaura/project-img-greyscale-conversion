# project-img-greyscale-conversion

### Setup the Environment (MacOS)
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
