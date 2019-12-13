#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

void detect_and_display([[maybe_unused]] const cv::Mat& frame,
                        [[maybe_unused]] const cv::CascadeClassifier& face_cascade,
                        [[maybe_unused]] const cv::CascadeClassifier& eyes_cascade)
{
}

int main(int argc, const char** argv)
{
  auto parser = cv::CommandLineParser(argc,
                                      argv,
                                      "{help h||}"
                                      "{face_cascade|/path/|Path to face cascade");
}
