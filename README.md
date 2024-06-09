# project-img-greyscale-conversion

### Compile the Code
```zsh
g++ -std=c++11 gsc-opencv.cpp -o gsc-opencv -Xpreprocessor -fopenmp -I/opt/homebrew/include/opencv4 -L/opt/homebrew/Cellar/opencv/4.9.0_9/lib -I/opt/homebrew/Cellar/libomp/18.1.6/include -L/opt/homebrew/Cellar/libomp/18.1.6/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lomp
```

### Run the Project
```zsh
./gsc-opencv
```
