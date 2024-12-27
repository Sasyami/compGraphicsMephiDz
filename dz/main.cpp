#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "task3.hpp"
#include "task2.hpp"
#include "task1.hpp"

int main(){
    cv::Mat mat = cv::Mat(1000,1000, CV_8UC1,255);
    std::vector<cv::Point2f> points = {
        {256, 144},
        {426, 748},
        {700, 130},
        {52 ,524},        
        {814, 558},
    };
    drawContour(mat, points,0);
    cv::imwrite("polygon.png",mat);
    mat = cv::Mat(1000,1000, CV_8UC1,255);
    points = {
        {256, 144},
        {426, 748},
        {700, 130},
        {52 ,524},        
        {814, 558},
    };
    drawContour(mat,getContour(points),0);
    cv::imwrite("contour.png",mat);
    mat = cv::Mat(1000,1000, CV_8UC1,255);
    points = {
        
        
        
              
        {814, 558},
        {52 ,524},  
        {700, 130},
        {426, 748},
        {256, 144},
    };
    drawContour(mat, points,0);
    cv::imwrite("polygonBackwards.png",mat);
    mat = cv::Mat(1000,1000, CV_8UC1,255);
    points = {
        {814, 558},
        {52 ,524},  
        {700, 130},
        {426, 748},
        {256, 144},
    };
    drawContour(mat,getContour(points),0);
    cv::imwrite("contourBackwards.png",mat);
    




    mat = cv::Mat(1000,1000, CV_8UC1,255);
    drawDuga(mat,500,500,200,2*M_PI*0.3, -M_PI/3.,0);
    cv::Point2f center = {500,(float)(mat.rows - 500)};
    cv::circle(mat, center, 200, 125, 1);
    cv::imwrite("output2.png",mat);



    mat = cv::Mat(500,500, CV_8UC1,255);
    drawDuga(mat,100,150,100,M_PI, -M_PI,0);
    cv::imwrite("output2Circle.png",mat);
    
    

    cv::Mat image = cv::imread("input.jpg", cv::IMREAD_COLOR_BGR);
    
    kMeans(image,8);

    cv::imwrite("output3k8.png",image);
    std::cout<<"k8 done"<<std::endl;
    cv::Mat image1 = cv::imread("input.jpg", cv::IMREAD_COLOR_BGR);
   
    kMeans(image1,16);

    cv::imwrite("output3k16.png",image1);

    std::cout<<"k16 done"<<std::endl;
    cv::Mat image2 = cv::imread("input.jpg", cv::IMREAD_COLOR_BGR);
    
    kMeans(image2,32);
    
    cv::imwrite("output3k32.png",image2);
    std::cout<<"k32 done"<<std::endl;
}