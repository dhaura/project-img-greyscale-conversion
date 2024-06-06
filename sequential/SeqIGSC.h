#include <iostream>
#include <opencv2/opencv.hpp>

class SeqIGSC 
{
	public:
		static void convertImageToGrayscale(const cv::Mat& rgbImage, cv::Mat& greyImage)
		{
            std::cout << "Image Channels: " << rgbImage.channels() << "\n";
            CV_Assert(rgbImage.channels() == 3); // Ensure input image is RGB

            greyImage.create(rgbImage.size(), CV_8UC1);
            for (int y = 0; y < rgbImage.rows; ++y) {
                for (int x = 0; x < rgbImage.cols; ++x) {
                    cv::Vec3b rgb = rgbImage.at<cv::Vec3b>(y, x);
                    greyImage.at<uchar>(y, x) = 0.299f * rgb[2] + 0.587f * rgb[1] + 0.114f * rgb[0];
                }
            }

		}

};
