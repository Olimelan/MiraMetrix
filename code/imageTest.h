//
// Description: Classe image
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
void onMouse(int event, int x, int y, int flags, void* userdata);

// Classes
class Image
{
    /* This class implement function to cycle threw channels from an image and modifiy it*/

public:
    Image();
    string name;
    string type;
    string windowName;
    int colonnes;
    int rows;
    Mat channels[3];
    Mat channelsGrey;
    int index;

    void setWindowName(string windowName);
    void setName(string name);
    void applyBlueShade();
    void applyGreenShade();
    void applyRedShade();
    void applyGreyShade();
    void restoreOriginal();
    void show();
    void startChannelCycling();


private:
    Mat imageHandler;
    Mat greyHandler;
    Mat imageOutput;
    void setChannelsMat();
    void setMouseActionCallBack(string windowName, Mat imageHandler);
};