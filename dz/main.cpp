#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "task3.hpp"
#include "task2.hpp"
#include "task1.hpp"

int main(){
    cv::Mat mat = cv::Mat(500,500, CV_8UC1,255);
    std::vector<cv::Point2f> points = {
        {256, 144},
        {426, 748},
        {700, 130},
        {52 ,524},        
        {814, 558},
    };
    drawContour(mat, points,0);
    cv::imwrite("polygon.png",mat);
    mat = cv::Mat(500,500, CV_8UC1,255);
    points = {
        {256, 144},
        {426, 748},
        {700, 130},
        {52 ,524},        
        {814, 558},
    };
    drawContour(mat,getContour(points),0);
    cv::imwrite("contour.png",mat);
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawDuga(mat,100,150,100,2*M_PI*0.3, -M_PI/3.,0);
    cv::imwrite("output2.png",mat);
    cv::Mat image = cv::imread("input.jpg", cv::IMREAD_COLOR_BGR);
    //std::cout<<dist(cv::Vec3b(255,255,255), cv::Vec3f(256,256,256))<<std::endl;
    //std::cout<<image1.rows<<" "<<image1.cols<<std::endl;
    kMeans(image,8);

    cv::imwrite("output3.png",image);
}