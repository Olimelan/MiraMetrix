//
// Description: Classe webcam
//
// Created by Olivier Melançon
//

#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdint.h>
#include <string>
#include <stdlib.h>

using namespace cv;
using namespace std;

// Functions
void onMouseWebcam(int event, int x, int y, int flags, void* userdata);

// Classes
class Webcam
{
    /* This class implement function to cycle threw channels from a webcam feed*/

public:

    string windowName;
    Mat videoChannels[3];
    Mat outputFrame;
    int index;

    Webcam();
    void setWindowName(string windowName);
    void startChannelCycling();
    void applyBlueShade();
    void applyGreenShade();
    void applyRedShade();
    void restoreChannels();
    void show();


private:
    Mat frame;

    void setMouseActionCallBack(string windowName);
    void applyFilter();
};