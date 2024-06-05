#include <iostream>
#include <opencv2/opencv.hpp>

#include "./sequential/SeqIGSC.h"

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    // Load input image
    std::string input_file = "/Users/dhaurapathirana/Documents/Personal/HPC/Projects/project-img-greyscale-conversion/samples/inputs/sample-input-2.jpg";
    std::cout << "Input file: " << input_file << "\n";
    
    cv::Mat rgbaImage = cv::imread(input_file, cv::IMREAD_UNCHANGED);
    if (rgbaImage.empty()) {
        std::cerr << "Error: Could not load image. Check the file path.\n";
        return -1;
    }
    std::cout << "Loaded PNG image successfully.\n";

    // Convert input image to grayscale
    cv::Mat greyImage;
    std::cout << "Starting grayscale conversion...\n";
    SeqIGSC::convertImageToGrayscale(rgbaImage, greyImage);
    std::cout << "Completed grayscale conversion successfully.\n";

    // Save grayscale image
    std::string output_file = "/Users/dhaurapathirana/Documents/Personal/HPC/Projects/project-img-greyscale-conversion/samples/outputs/sample-output-2.jpg";
    if (!cv::imwrite(output_file, greyImage)) {
        std::cerr << "Error: Could not save the grayscale image.\n";
        return -1;
    }
    std::cout << "Saved grayscale image to " << output_file << "\n";

    return 0;
}
