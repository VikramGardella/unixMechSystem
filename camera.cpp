#include "camera.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

CameraStreamer::CameraStreamer(int camIndex, int fps)
    : cameraIndex(camIndex), frameRate(fps), cap(camIndex) {
    if(!cap.isOpened()) {
        cerr << "Failed to open camera at index." << cameraIndex << endl;
    }
}

bool CameraStreamer::startStream(const string& windowName) {
    if(!cap.isOpened()) {
        return false;
    }

    cv::Mat frame;
    while(true) {
        cap >> frame;
        if(frame.empty()) {
            cerr << "Empty frame captured." << endl;
            continue;
        }

        // Show in local window (can remove this if you want headless operation)
        cv::imshow(windowName, frame);

        // Wait for key or frame delay
        if(cv::waitKey(1000 / frameRate) == 27) {
            break;
        } // ESC to quit

        // Optional: stream to network using OpenCV VideoWriter + GStreamer pipeline
    }

    cap.release();
    cv::destroyAllWindows();
    return true;
}
