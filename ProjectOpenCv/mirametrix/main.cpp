//
// Description: Main du programme test et userinterface
//
// Created by Olivier Melançon
//

#include "imageTest.h"
#include "webcamTest.h"
#include "opencv2/opencv.hpp"

#include <stdlib.h>
#include <iostream>

using namespace std;



void userInterface(void* imageHandler, void* webcamHandler)
{
    //This function create a userinterface to control witch action the user want to do

    int option = 0;
    int imageID = 0;
    int action = 0;

    Image* image_test = static_cast<Image*>(imageHandler);
    Webcam* webcam_test = static_cast<Webcam*>(webcamHandler);

    cout << " This program will allow you to make some modifications on an image or cycle channels on a webcam feed\n" << endl;

    cout << "Do you want to use a webcam feed or an image ?\n" << endl;
    cout << "1- Webcam feed (main test)\n" << endl;
    cout << "2- image \n" << endl;
    cout << "Autres: Exit\n" << endl;
    cout << "Enter your choice:" << endl;

    cin >> option;

    if (option == 1)
    {
        cout << "WEBCAM FEED" << endl;
        cout << "Press any key to exit\n\n" << endl;
        webcam_test->startChannelCycling();
        system("CLS");

    }
    else if (option == 2)
    {
        cout << " Choose an image in the list below:\n" << endl;
        cout << "1- cat.jpg" << endl;
        cout << "2- dog.jpg" << endl;
        cout << "3- car.jpg" << endl;
        cin >> imageID;

        if (imageID == 1)
        {
            image_test->setName("cat.jpg");
        }

        else if (imageID == 2)
        {
            image_test->setName("dog.jpg");
        }

        else if (imageID == 3)
        {
            image_test->setName("car.jpg");
        }

        system("CLS");

        cout << " Choose the action to do on that image:\n" << endl;
        cout << " 1- Channel cycling (main test)\n" << endl;
        cout << " 2- Apply shade of blue\n" << endl;
        cout << " 3- Apply shade of green\n" << endl;
        cout << " 4- Apply shade of red\n" << endl;
        cout << " 5- Apply shade of grey\n" << endl;
        cout << " 6- Exit\n" << endl;
        cin >> action;

        if (action == 1)
        {
            image_test->setWindowName("Channel cycling");
            image_test->startChannelCycling();
        }
        else if (action == 2)
        {
            image_test->setWindowName("Shade of blue");
            image_test->applyBlueShade();
            image_test->show();
        }
        else if (action == 3)
        {
            image_test->setWindowName("Shade of green");
            image_test->applyGreenShade();
            image_test->show();
        }
        else if (action == 4)
        {
            image_test->setWindowName("Shade of red");
            image_test->applyRedShade();
            image_test->show();
        }

        else if (action == 5)
        {
            image_test->setWindowName("Shade of grey");
            image_test->applyGreyShade();
        }
        waitKey();
    }
}

int main(int argc, char** argv)
{
    Image imageHandler;
    Webcam webcamHandler;

    userInterface(&imageHandler, &webcamHandler);

    

}