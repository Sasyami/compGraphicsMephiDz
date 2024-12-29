
#ifndef HEADER_HPP54
#define HEADER_HPP54
#include "../lab3/firstlab.hpp"
#include "../lab3/secondlab.hpp"
#include <vector>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "figure.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/videoio.hpp"

using namespace cv;

Mat createRotationMatrix(double angle, double x, double y, double z) {
    double n = sqrt(x * x + y * y + z * z);
    double nx = x / n;
    double ny = y / n;
    double nz = z / n;

    double cosAngle = cos(angle);
    double sinAngle = sin(angle);

    return (Mat_<double>(4, 4) <<
        cosAngle + nx * nx * (1 - cosAngle), nx * ny * (1 - cosAngle) + nz * sinAngle, nx * nz * (1 - cosAngle) - ny * sinAngle, 0,
        ny * nx * (1 - cosAngle) - nz * sinAngle, cosAngle + ny * ny * (1 - cosAngle), ny * nz * (1 - cosAngle) + nx * sinAngle, 0,
        nz * nx * (1 - cosAngle) + ny * sinAngle, nz * ny * (1 - cosAngle) - nx * sinAngle, cosAngle + nz * nz * (1 - cosAngle), 0,
        0, 0, 0, 1);
}

void writeRotation(Figure f, void (*drawer)(Mat& mat, Figure figure, uchar color)){
    VideoWriter video("./rotating_parallelepiped_perspective.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(800, 600));
    
    double angle = 0.0f;
    double rotationAxisX = 1.0f, rotationAxisY = 1.0f, rotationAxisZ = 1.0f;
    int i =0;
    double buf1,buf2,buf3;
    Mat img(600, 800, CV_8UC3, 255);
    while (true) {
       
        Mat rotationMatrix = createRotationMatrix(angle, rotationAxisX, rotationAxisY, rotationAxisZ);

        for (int i = 0; i<f.down.x.size(); ++i){
            buf1 = f.down.x[i][0]*rotationMatrix.at<double>(0,0) + f.down.x[i][1] * rotationMatrix.at<double>(1,0) + f.down.x[i][2]*rotationMatrix.at<double>(2,0);
            buf2= f.down.x[i][0]*rotationMatrix.at<double>(0,1) + f.down.x[i][1] * rotationMatrix.at<double>(1,1) + f.down.x[i][2]*rotationMatrix.at<double>(2,1);
            buf3 = f.down.x[i][0]*rotationMatrix.at<double>(0,2) + f.down.x[i][1] * rotationMatrix.at<double>(1,2) + f.down.x[i][2]*rotationMatrix.at<double>(2,2);

            f.down.x[i][0] = buf1;
            f.down.x[i][1] = buf2;
            f.down.x[i][2] = buf3;
        }
        for (int i = 0; i<f.down.x.size(); ++i){
            buf1 = f.up.x[i][0]*rotationMatrix.at<double>(0,0) + f.up.x[i][1] * rotationMatrix.at<double>(1,0) + f.up.x[i][2]*rotationMatrix.at<double>(2,0);
            buf2 = f.up.x[i][0]*rotationMatrix.at<double>(0,1) + f.up.x[i][1] * rotationMatrix.at<double>(1,1) + f.up.x[i][2]*rotationMatrix.at<double>(2,1);
            buf3 = f.up.x[i][0]*rotationMatrix.at<double>(0,2) + f.up.x[i][1] * rotationMatrix.at<double>(1,2) + f.up.x[i][2]*rotationMatrix.at<double>(2,2);


            f.up.x[i][0] = buf1;
            f.up.x[i][1] = buf2;
            f.up.x[i][2] = buf3;
        }
        drawer(img, f, 0);
        video.write(img); 
        
        angle += 0.01f; 
        if (i>= 100) break;
        ++i;
        img = Mat(600, 800, CV_8UC3, 255);


    }
    video.release();
}


#endif