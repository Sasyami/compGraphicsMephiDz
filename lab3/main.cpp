#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "secondlab.hpp"
#include "fourthlab.hpp"

int main(){
    cv::Mat mat = cv::Mat(1000,1000, CV_8UC1,255);
    drawHatchedLine<uchar>(mat, 100,100, 400, 300,30,30,0);
    drawHatchedLine<uchar>(mat,100,100,400,100,30,30,0);
    cv::imwrite("hatchedline.png", mat);
    /* std::vector<int>a;
    std::vector<int>b;
    a.emplace_back(0);
    a.emplace_back(100);
    a.emplace_back(200);
    a.emplace_back(0);
    a.emplace_back(200);

    b.emplace_back(0);
    b.emplace_back(200);
    b.emplace_back(0);
    b.emplace_back(100);
    b.emplace_back(100);
    
    Polygon p(a,b);
    
    fillPolygon<uchar>(mat,&PInPolygonNZWMode,p,125);
    cv::imwrite("test.jpg",mat); */
    mat = cv::Mat(300,300, CV_8UC1,255);
    std::vector<int>a1;
    std::vector<int>b1;
    


    a1.emplace_back(0);
    a1.emplace_back(100);
    a1.emplace_back(100);
    a1.emplace_back(0);
    

    b1.emplace_back(0);
    b1.emplace_back(0);
    
    b1.emplace_back(100);
    b1.emplace_back(100);
    Polygon p(a1,b1);
    drawPolygon<uchar>(mat, p, 0);
    cv::imwrite("simpleConvexFigure.jpg", mat);
    std::cout<<"Простой? - "<<isSimple(p)<<std::endl;
    std::cout<<"Выпуклый? - "<<isConvex(p)<<std::endl;

    std::vector<int>a;
    std::vector<int>b;
    


    a.emplace_back(0);
    a.emplace_back(100);
    a.emplace_back(200);
    a.emplace_back(0);
    a.emplace_back(200);

    b.emplace_back(0);
    b.emplace_back(200);
    b.emplace_back(0);
    b.emplace_back(100);
    b.emplace_back(100);
    
    p = Polygon(a,b);
    mat = cv::Mat(300,300, CV_8UC1,255);
    drawPolygon<uchar>(mat, p, 0);
    
    cv::imwrite("starFigure.jpg", mat);
    mat = cv::Mat(300,300, CV_8UC1,255);
    drawPolygon<uchar>(mat, p, 0);
    fillPolygon<uchar>(mat,&PInPolygonEOMode,p,125);

    cv::imwrite("starFigureEO.jpg", mat);
    mat = cv::Mat(300,300, CV_8UC1,255);
    drawPolygon<uchar>(mat, p, 0);
    fillPolygon<uchar>(mat,&PInPolygonNZWMode,p,125);
    cv::imwrite("starFigureNZW.jpg", mat);


    std::cout<<"Простой? - "<<isSimple(p)<<std::endl;
    std::cout<<"Выпуклый? - "<<isConvex(p)<<std::endl;
    a = std::vector<int>();
    b = std::vector<int>();

    a.emplace_back(0);
    a.emplace_back(100);
    a.emplace_back(100);
    a.emplace_back(0);
    a.emplace_back(0);
    a.emplace_back(300);
    a.emplace_back(300);
    a.emplace_back(200);
    a.emplace_back(200);
    a.emplace_back(300);
    a.emplace_back(300);
    a.emplace_back(0);

    b.emplace_back(0);
    b.emplace_back(0);
    b.emplace_back(300);
    b.emplace_back(300);
    b.emplace_back(200);
    b.emplace_back(200);
    b.emplace_back(300);
    b.emplace_back(300);
    b.emplace_back(0);
    b.emplace_back(0);
    b.emplace_back(100);
    b.emplace_back(100);
    p = Polygon(a,b);
    mat = cv::Mat(400,400, CV_8UC1,255);
    drawPolygon<uchar>(mat, p, 0);
    
    cv::imwrite("quadFigure.jpg", mat);


    mat = cv::Mat(400,400, CV_8UC1,255);
    drawPolygon<uchar>(mat, p, 0);
    fillPolygon<uchar>(mat,&PInPolygonEOMode,p,125);

    cv::imwrite("quadFigureEO.jpg", mat);
    mat = cv::Mat(400,400, CV_8UC1,255);
    drawPolygon<uchar>(mat, p, 0);
    fillPolygon<uchar>(mat,&PInPolygonNZWMode,p,125);

    cv::imwrite("quadFigureNZW.jpg", mat);
    std::cout<<"Простой? - "<<isSimple(p)<<std::endl;
    std::cout<<"Выпуклый? - "<<isConvex(p)<<std::endl;

    

}