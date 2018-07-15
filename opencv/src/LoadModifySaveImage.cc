#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path/to/image>" << std::endl;
        return -1;
    }

    const char* image_name = argv[1];
    auto image = cv::imread(image_name, cv::IMREAD_COLOR);
    if (!image.data) {
        std::cerr << "No image data" << std::endl;
        return -1;
    }

    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    cv::imwrite("gray_image.jpg", gray_image);

    cv::namedWindow(image_name, cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Gray image", cv::WINDOW_AUTOSIZE);

    cv::imshow(image_name, image);
    cv::imshow("Gray image", gray_image);

    cv::waitKey(0);

    return 0;
}
