#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>


class OpenMPIGSC 
{
	public:
		static void convertImageToGrayscale(const cv::Mat& rgbImage, cv::Mat& greyImage)
		{
            std::cout << "Image Channels: " << rgbImage.channels() << "\n";
            CV_Assert(rgbImage.channels() == 3); // Ensure input image is RGB

            greyImage.create(rgbImage.size(), CV_8UC1);
            
            omp_set_num_threads(4);
            #pragma omp parallel for collapse(2)
            for (int i = 0; i < rgbImage.rows; ++i) {
                for (int j = 0; j < rgbImage.cols; ++j) {
                    cv::Vec3b rgb = rgbImage.at<cv::Vec3b>(i, j);
                    greyImage.at<uchar>(i, j) = 0.299f * rgb[2] + 0.587f * rgb[1] + 0.114f * rgb[0];
                }
            }
		}
};
