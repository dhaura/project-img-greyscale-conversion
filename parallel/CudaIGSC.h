#include <iostream>
#include <opencv2/opencv.hpp>
#include <cuda.h>

__global__ void rgbToGrayscale(const uchar3* rgbImage, uchar* greyImage, int rows, int cols) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i < cols && j < rows) {
        int index = j * cols + i;
        uchar3 rgb = rgbImage[index];
        greyImage[index] = 0.299f * rgb.z + 0.587f * rgb.y + 0.114f * rgb.x;
    }
}

class CudaIGSC
{
public:
    static void convertImageToGrayscale(const cv::Mat& rgbImage, cv::Mat& greyImage)
    {
        std::cout << "Image Channels: " << rgbImage.channels() << "\n";
        CV_Assert(rgbImage.channels() == 3); // Ensure input image is RGB

        greyImage.create(rgbImage.size(), CV_8UC1);

        // Allocate GPU memory
        uchar3* d_rgbImage;
        uchar* d_greyImage;
        cudaMalloc(&d_rgbImage, rgbImage.rows * rgbImage.cols * sizeof(uchar3));
        cudaMalloc(&d_greyImage, greyImage.rows * greyImage.cols * sizeof(uchar));

        // Copy input data to GPU
        cudaMemcpy(d_rgbImage, rgbImage.data, greyImage.rows * greyImage.cols * sizeof(uchar3), cudaMemcpyHostToDevice);

        // Define block and grid dimensions
        dim3 blockSize(16, 16);
        dim3 gridSize((greyImage.cols + blockSize.x - 1) / blockSize.x, (greyImage.rows + blockSize.y - 1) / blockSize.y);

        rgbToGrayscale << <gridSize, blockSize >> > (d_rgbImage, d_greyImage, greyImage.rows, greyImage.cols);

        // Check for any errors
        cudaError_t err = cudaGetLastError();
        if (err != cudaSuccess)
        {
            std::cerr << "CUDA error: " << cudaGetErrorString(err) << "\n";
            exit(EXIT_FAILURE);
        }

        // Wait until GPU kernel is done
        cudaDeviceSynchronize();

        // Copy output data from GPU to CPU
        cudaMemcpy(greyImage.data, d_greyImage, greyImage.rows * greyImage.cols * sizeof(uchar), cudaMemcpyDeviceToHost);

        // Free GPU memory
        cudaFree(d_rgbImage);
        cudaFree(d_greyImage);
    }
};
