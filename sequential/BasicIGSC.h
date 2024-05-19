#include <iostream>
#include <opencv2/opencv.hpp>

class BasicIGSC 
{
	public:
		static void convertImageToGrayscale(const cv::Mat& rgbaImage, cv::Mat& greyImage)
		{
            CV_Assert(rgbaImage.channels() == 4); // Ensure input image is RGBA

            greyImage.create(rgbaImage.size(), CV_8UC1);

            for (int y = 0; y < rgbaImage.rows; ++y) {
                for (int x = 0; x < rgbaImage.cols; ++x) {
                    cv::Vec4b rgba = rgbaImage.at<cv::Vec4b>(y, x);
                    greyImage.at<uchar>(y, x) = 0.299f * rgba[2] + 0.587f * rgba[1] + 0.114f * rgba[0];
                }
            }
		}

};
