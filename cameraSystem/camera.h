#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <string>

class CameraStreamer {
public:
    CameraStreamer(int camIndex = 0, int fps = 10);
    bool startStream(const std::string& windowName = "Camera Feed");

private:
    int cameraIndex;
    int frameRate;
    cv::VideoCapture cap;
};

#endif
