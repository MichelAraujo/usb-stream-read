// g++ -std=c++11 -o main main.cpp $(pkg-config --cflags --libs opencv4)

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open USB camera" << std::endl;
        return -1;
    }

    // Set camera properties (optional)
    // cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('U', 'Y', 'V', 'Y')); // Try forcing YUYV
    // cap.set(cv::CAP_PROP_CONVERT_RGB, true); // Force color conversion
    // cap.set(cv::CAP_PROP_MODE, 1); // Try setting mode to fix decoding
    // 

    // cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    // cap.set(cv::CAP_PROP_CONVERT_RGB, true);

    cv::Mat frame, converted;
    while (true) {
        // cap.set(cv::CAP_PROP_FRAME_WIDTH, 720);
        // cap.set(cv::CAP_PROP_FRAME_HEIGHT, 576);
        // cap.set(cv::CAP_PROP_FPS, 25);

        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Error: Empty frame received" << std::endl;
            break;
        }

//         std::cout << "Frame Channels: " << frame.channels() << std::endl;
//         std::cout << "Frame Size: " << frame.size() << std::endl;
//         std::cout << "Frame Type: " << frame.type() << std::endl;
//         std::cout << "Capture Format: " << cap.get(cv::CAP_PROP_FOURCC) << std::endl;
//         std::cout << "Frame Width: " << cap.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl;
//         std::cout << "Frame Height: " << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;

//         int format = cap.get(cv::CAP_PROP_FORMAT);
// std::cout << "Capture Format: " << format << std::endl;

std::cout << "Frame Width: " << cap.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl;
std::cout << "Frame Height: " << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;
std::cout << "FPS: " << cap.get(cv::CAP_PROP_FPS) << std::endl;
std::cout << "Format: " << cap.get(cv::CAP_PROP_FORMAT) << std::endl;


        // Convert YUYV to BGR (Check format first)
    // cv::cvtColor(frame, converted, cv::COLOR_YUV2BGR_YUYV);

        cv::imshow("USB Video Strem", frame);

        // Exit if 'q' is pressed
        if (cv::waitKey(1) == 'q') break;
    }

    cap.release();
    cv::destroyAllWindows();

    std::cout << "I'm a test program!" << std::endl;
    return 0;
}