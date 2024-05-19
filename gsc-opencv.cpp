#include <iostream>
#include <opencv2/opencv.hpp>

#include "./sequential/BasicIGSC.h"

int main() {
    // Load PNG image
    std::string input_file;
    std::cout << "Enter input file name: "; std::cin >> input_file; std::cout << "\n";
    cv::Mat rgbaImage = cv::imread(input_file.c_str(), cv::IMREAD_UNCHANGED);
    std::cout << "Loaded PNG image successfully.\n";

    // Convert PNG image to grayscale
    cv::Mat greyImage;
    std::cout << "Starting grayscale conversion...\n";
    BasicIGSC::convertImageToGrayscale(rgbaImage, greyImage);
    std::cout << "Completed grayscale conversion successfully.\n";

    // Save grayscale image
    cv::imwrite("D:/Academic/CPP/HPCProjects/project-img-greyscale-conversion/samples/outputs/sample-output-1.png", greyImage);

    return 0;
}
