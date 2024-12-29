#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "figure.hpp"
#include "perspective.hpp"
#include "back_face_culling.hpp"
#include "rotation.hpp"
void drawer(Mat& mat, Figure fig, uchar color){
    drawPerspectiveOnZ(mat,fig, 0.002,0);
}
int main(){
    cv::Mat mat = cv::Mat(300,300, CV_8UC1,255);
    std::vector<std::vector<float>> up = {{50,50,50}, {100,100,0},{100,150,50},{50,100,100}, };
    std::vector<std::vector<float>> down = {{150,0,100}, {200,50,50}, {200,100,200},{150,50,150}, };
    Figure f = Figure(Polygon3d(up), Polygon3d(down));
    drawFigureOnZ(mat,f,0);
    cv::imwrite("outputZ.jpg",mat);


    mat = cv::Mat(300,300, CV_8UC1,255);
    
    drawPerspectiveOnZ(mat,f, 0.002, 0);
    cv::imwrite("perspectiveZ.jpg",mat);


    mat = cv::Mat(300,300, CV_8UC1,255);
    
    drawVisibleFaces(mat,f);
    cv::imwrite("visibleZ.jpg",mat);

    writeRotation(f, drawer);
}