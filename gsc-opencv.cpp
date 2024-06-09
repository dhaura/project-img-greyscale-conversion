#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

#include "./sequential/SeqIGSC.h"
#include "./parallel/OpenMPIGSC.h"
#include "./parallel/CudaIGSC.h"

int main() {
    // Get input file path
    std::string input_file = "";
    std::cout << "Enter input file path: ";
    std::cin >> input_file; std::cout << "\n";

    // Get output file path
    std::string output_file = "";
    std::cout << "Enter output file path: ";
    std::cin >> output_file; std::cout << "\n";

    // Get execution method
    int execution_method = 1;
    std::cout << "Enter execution method [Sequential: 1, Parallel: 2]: ";
    std::cin >> execution_method; std::cout << "\n";
    
    // Load input image
    cv::Mat rgbImage = cv::imread(input_file, cv::IMREAD_UNCHANGED);
    if (rgbImage.empty()) {
        std::cerr << "Error: Could not load image. Check the file path.\n";
        return -1;
    }
    std::cout << "Loaded JPG image successfully.\n";

    // Convert input image to grayscale
    cv::Mat greyImage;
    std::cout << "Starting grayscale conversion...\n";
    auto start = std::chrono::high_resolution_clock::now();
    switch (execution_method) {
        case 1:
            SeqIGSC::convertImageToGrayscale(rgbImage, greyImage);
            break;
        case 2:
            OpenMPIGSC::convertImageToGrayscale(rgbImage, greyImage);
            break;
        case 3:
            CudaIGSC::convertImageToGrayscale(rgbImage, greyImage);
            break;
        default:
            std::cerr << "Invalid execution method.\n";
            return -1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Completed grayscale conversion successfully.\n";
    std::cout << "Time taken for conversion : " << duration.count() << " microseconds" << std::endl;

    // Save grayscale image
    if (!cv::imwrite(output_file, greyImage)) {
        std::cerr << "Error: Could not save the grayscale image.\n";
        return -1;
    }
    std::cout << "Saved grayscale JPG image to " << output_file << "\n";

    return 0;
}
