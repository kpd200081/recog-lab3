#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    VideoCapture cap(0);
    Mat frame, bluredFrame, blue, edges;
    while(true) {
        cap >> frame;

        if(frame.empty())
            continue;
        imshow("Source", frame);

        GaussianBlur(frame, bluredFrame, Size(21, 21), 0, 0);
        imshow("Blurred", bluredFrame);

        cvtColor(frame, blue, COLOR_BGR2HSV);
        inRange(frame, Scalar(100, 50, 0), Scalar(360, 255, 95), blue);
        imshow("Blue objects", blue);

        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(9, 9), 0, 0);
        Canny(edges, edges, 35, 50);
        imshow("edges", edges);

        if(waitKey(10) == 27)
            break; // ESC
    }

    cap.release();
    return 0;
}
