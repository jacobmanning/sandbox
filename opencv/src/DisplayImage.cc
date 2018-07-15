#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " </path/to/image>" << std::endl;
        return 1;
    }

    auto image = cv::imread(argv[1], 1);

    if (!image.data) {
        std::cerr << "No image data!" << std::endl;
        return 1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow(argv[1], image);
    cv::waitKey(0);

    return 0;
}
