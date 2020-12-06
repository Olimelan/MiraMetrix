//
// Description: Fonction de la classe image
//
// Created by Olivier Melançon
//


// includes
#include "imageTest.h"

Image::Image()
{
    this->name = "cat.jpg";
    this->type = "COLOR";
    this->windowName = "Channels test";
    this->setChannelsMat();
    this->colonnes = 0;
    this->rows = 0;
    this->index = 0;
};

void Image::setName(string name)
{
    this->name = name;
    this->setChannelsMat();
};

void Image::setWindowName(string windowName)
{
    this->windowName = windowName;
};

void Image::setChannelsMat()
{
    this->imageHandler = imread(this->name, IMREAD_COLOR);
    this->greyHandler = imread(this->name, IMREAD_GRAYSCALE);

    cv::split(this->imageHandler, this->channels);
    merge(this->channels, 3, this->imageOutput);
};

void Image::applyBlueShade()
{
    this->restoreOriginal();
    this->channels[1] = Mat::zeros(this->channels[1].size(), CV_8UC1);
    this->channels[2] = Mat::zeros(this->channels[2].size(), CV_8UC1);

    merge(this->channels, 3, this->imageOutput);
};

void Image::applyGreenShade()
{
    this->restoreOriginal();
    this->channels[0] = Mat::zeros(this->channels[0].size(), CV_8UC1);
    this->channels[2] = Mat::zeros(this->channels[2].size(), CV_8UC1);

    merge(this->channels, 3, this->imageOutput);
};

void Image::applyRedShade()
{
    this->restoreOriginal();
    this->channels[0] = Mat::zeros(this->channels[0].size(), CV_8UC1);
    this->channels[1] = Mat::zeros(this->channels[1].size(), CV_8UC1);

    merge(this->channels, 3, this->imageOutput);
};

void Image::applyGreyShade()
{
    this->restoreOriginal();
    imshow(this->windowName, this->greyHandler);
};

void Image::show()
{
    imshow(this->windowName, this->imageOutput);
}

void Image::restoreOriginal()
{
    cv::split(this->imageHandler, this->channels);
    merge(this->channels, 3, this->imageOutput);
};

void Image::startChannelCycling()
{
    this->setChannelsMat();
    setMouseActionCallBack(this->windowName, this->imageHandler);
    this->show();
};

void Image::setMouseActionCallBack(string windowName, Mat imageHandler)
{
    namedWindow(windowName, WINDOW_FULLSCREEN); // init
    setMouseCallback(windowName, onMouse, this);
};

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    Image* image = static_cast<Image*>(userdata);

    if (event == EVENT_LBUTTONDOWN) {

        if (image->index == 0)
        {
            image->applyBlueShade();
            image->show();
            image->index += 1;
        }

        else if (image->index == 1)
        {
            image->applyGreenShade();
            image->show();
            image->index += 1;
        }

        else if (image->index == 2)
        {
            image->applyRedShade();
            image->show();
            image->index += 1;
        }
        else if (image->index == 3)
        {
            image->restoreOriginal();
            image->show();
            image->index = 0;
        }
    }
};