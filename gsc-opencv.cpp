#include <iostream>
#include <opencv2/opencv.hpp>

#include "./sequential/SeqIGSC.h"

int main() {
    // Get input file path
    std::string input_file = "";
    std::cout << "Enter input file path: ";
    std::cin >> input_file; std::cout << "\n";

    // Get output file path
    std::string output_file = "";
    std::cout << "Enter output file path: ";
    std::cin >> output_file; std::cout << "\n";
    
    // Load input image
    cv::Mat rgbaImage = cv::imread(input_file, cv::IMREAD_UNCHANGED);
    if (rgbaImage.empty()) {
        std::cerr << "Error: Could not load image. Check the file path.\n";
        return -1;
    }
    std::cout << "Loaded JPG image successfully.\n";

    // Convert input image to grayscale
    cv::Mat greyImage;
    std::cout << "Starting grayscale conversion...\n";
    SeqIGSC::convertImageToGrayscale(rgbaImage, greyImage);
    std::cout << "Completed grayscale conversion successfully.\n";

    // Save grayscale image
    if (!cv::imwrite(output_file, greyImage)) {
        std::cerr << "Error: Could not save the grayscale image.\n";
        return -1;
    }
    std::cout << "Saved grayscale JPG image to " << output_file << "\n";

    return 0;
}
