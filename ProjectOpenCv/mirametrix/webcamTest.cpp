//
// Description: Fonction de la classe webcam
//
// Created by Olivier Melançon
//

#include "webcamTest.h"

Webcam::Webcam()
{
    this->setWindowName("Webcam feed"); // default name
    this->index = 0;
};

void Webcam::setWindowName(string windowName)
{
    /* set the windows name of the webcam feed*/
    this->windowName = windowName;
};

void Webcam::show()
{
    /* Start the webcam feed*/
    this->windowName = windowName;

    VideoCapture vid(0);
    if (!vid.isOpened())
    {
        cout << "Webcam feed cannot start" << endl;
    }

    while (vid.read(this->frame))
    {
        cv::split(this->frame, this->videoChannels);

        imshow(this->windowName, this->outputFrame);

        if (waitKey(1000 / 20) >= 0)
        {
            // When a key is enter the code exit
            break;
        }
    }
};

void Webcam::startChannelCycling()
{
    /* code to cycle threw each channels*/

    this->setWindowName("Channel cycling");
    this->setMouseActionCallBack(this->windowName);

    VideoCapture vid(0);
    if (!vid.isOpened())
    {
        cout << "Webcam feed cannot start" << endl;
    }

    while (vid.read(this->frame))
    {
        cv::split(this->frame, this->videoChannels);

        applyFilter();

        imshow(this->windowName, this->outputFrame);

        if (waitKey(1000 / 20) >= 0)
        {
            // When a key is enter the code exit
            break;
        }
    }
};

void Webcam::applyFilter()
{

    /* This function choose witch channels we want to show on the webcam feed base on the index incremented by the mouse click*/

    if (this->index == 1)
    {
        this->applyBlueShade();
    }

    else if (this->index == 2)
    {
        this->applyGreenShade();
    }

    else if (this->index == 3)
    {
        this->applyRedShade();
    }
    else if (this->index == 0)
    {
        this->outputFrame = this->frame;
    }

};

void Webcam::applyBlueShade()
{
    /* This function apply the blue channels on the output frame show by the webcam*/
    this->restoreChannels();
    this->videoChannels[1] = Mat::zeros(this->videoChannels[1].size(), CV_8UC1);
    this->videoChannels[2] = Mat::zeros(this->videoChannels[2].size(), CV_8UC1);

    merge(this->videoChannels, 3, this->outputFrame);
};

void Webcam::applyGreenShade()
{
    /* This function apply the green channels on the output frame show by the webcam*/
    this->restoreChannels();
    this->videoChannels[0] = Mat::zeros(this->videoChannels[0].size(), CV_8UC1);
    this->videoChannels[2] = Mat::zeros(this->videoChannels[2].size(), CV_8UC1);

    merge(this->videoChannels, 3, this->outputFrame);
};

void Webcam::applyRedShade()
{
    /* This function apply the red channels on the output frame show by the webcam*/
    this->restoreChannels();
    this->videoChannels[0] = Mat::zeros(this->videoChannels[0].size(), CV_8UC1);
    this->videoChannels[1] = Mat::zeros(this->videoChannels[1].size(), CV_8UC1);

    merge(this->videoChannels, 3, this->outputFrame);
};

void Webcam::setMouseActionCallBack(string windowName)
{
    /* This function set the callback function for the mouse when it is click, the call back function is onMouseWebcam */
    namedWindow(this->windowName, WINDOW_FULLSCREEN);
    setMouseCallback(this->windowName, onMouseWebcam, this);
};

void Webcam::restoreChannels()
{
    /* This function restore the original frame on each channels*/
    cv::split(this->frame, this->videoChannels);
};

void onMouseWebcam(int event, int x, int y, int flags, void* userdata)
{
    /* This function increment the index of the object that identified witch channels we want to show on the webcam feed ( 0 to 3, normal to red)*/
    Webcam* webcam = static_cast<Webcam*>(userdata);

    if (event == EVENT_LBUTTONDOWN) {

        webcam->index += 1;

        if (webcam->index > 3)
        {
            webcam->index = 0;
        }
    }
};