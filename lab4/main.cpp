#include <iostream>
#include "firstlab.hpp"
#include "secondlab.hpp"
void drawDots(cv::Mat& mat, std::vector<int> x, std::vector<int> y, uchar color){
    for (int i = 0 ; i<x.size(); ++i){
        mat.at<uchar>(y[i], x[i]) = color;
        mat.at<uchar>(y[i]-1, x[i]) = color;
        mat.at<uchar>(y[i], x[i]-1) = color;
        mat.at<uchar>(y[i]+1, x[i]) = color;
        mat.at<uchar>(y[i], x[i]+1) = color;
        mat.at<uchar>(y[i]-2, x[i]) = color;
        mat.at<uchar>(y[i], x[i]-2) = color;
        mat.at<uchar>(y[i]+2, x[i]) = color;
        mat.at<uchar>(y[i], x[i]+2) = color;
    }
    
}
int main(){
    int isIntersect;
    cv::Mat mat = cv::Mat(500,500, CV_8UC1,255);
    int m = 3;
    std::vector<int> x = std::vector<int>();
    x.emplace_back(100);
    x.emplace_back(200);
    x.emplace_back(300);
    x.emplace_back(400);
    x.emplace_back(300);
    x.emplace_back(200);
    x.emplace_back(100);
   
    
    std::vector<int> y = std::vector<int>();
    y.emplace_back(50);
    y.emplace_back(100);
    y.emplace_back(150);
    y.emplace_back(200);
    y.emplace_back(250);
    y.emplace_back(300);
    y.emplace_back(350);
    Bezie(mat,x,y,m,0);

    drawDots(mat,x,y,125);
    cv::imwrite("bezie3Composite.jpg", mat);
    x = std::vector<int>();
    x.emplace_back(400);
    x.emplace_back(100);
    x.emplace_back(200);
    y = std::vector<int>();
    y.emplace_back(200);
    y.emplace_back(100);
    y.emplace_back(200);
    m=2;
    
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawDots(mat,x,y,125);
    Bezie(mat,x,y,m,0);
    cv::imwrite("bezie2.jpg", mat);
    


    x = std::vector<int>();
    x.emplace_back(100);
    x.emplace_back(200);
    
    x.emplace_back(300);
    x.emplace_back(400);
    x.emplace_back(500);
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(150);
    
    y.emplace_back(0);
    y.emplace_back(150);
    y.emplace_back(100);
    m=4;
    mat = cv::Mat(500,500, CV_8UC1,255);
    Bezie(mat,x,y,m,0);
    drawDots(mat,x,y,125);
    cv::imwrite("bezie4.jpg", mat);

    double y0 = 0;
    double x0 = 0;
    double x1 = 400;
    double y1 = 400;
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(100);
    x.emplace_back(100);
    
    x.emplace_back(200);
    x.emplace_back(200);
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    Polygon p(x,y);
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
   
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    cv::imwrite("polygonCut1.jpg", mat);


    // полигон в обратную сторону
    y0 = 0;
    x0 = 0;
    x1 = 400;
    y1 = 400;
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(200);
    x.emplace_back(200);
    x.emplace_back(100);
    x.emplace_back(100);
    
    
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    p = Polygon(x,y);
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
   
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    cv::imwrite("polygonCut2.jpg", mat);


    y0 = 125;
    x0 = 125;
    x1 = 175;
    y1 = 175;
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(200);
    x.emplace_back(200);
    x.emplace_back(100);
    x.emplace_back(100);
    
    
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    p = Polygon(x,y);
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
   
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    cv::imwrite("polygonCut3.jpg", mat);



    y0 = 50;
    x0 = 100;
    x1 = 400;
    y1 = 50;

    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(200);
    x.emplace_back(200);
    x.emplace_back(100);
    x.emplace_back(100);
    
    
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    p = Polygon(x,y);
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
   
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    cv::imwrite("polygonCut4.jpg", mat);



    y0 = 150;
    x0 = 150;
    x1 = 400;
    y1 = 400;
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(200);
    x.emplace_back(200);
    x.emplace_back(100);
    x.emplace_back(100);
    
    
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    p = Polygon(x,y);
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
   
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    cv::imwrite("polygonCut5.jpg", mat);


    y0 = 100;
    x0 = 100;
    x1 = 100;
    y1 = 200;
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(200);
    x.emplace_back(200);
    x.emplace_back(100);
    x.emplace_back(100);
    
    
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    p = Polygon(x,y);
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
   
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    cv::imwrite("polygonCut6.jpg", mat);


    y0 = 0;
    x0 = 0;
    x1 = 400;
    y1 = 200;
    mat = cv::Mat(500,500, CV_8UC1,255);
    drawLine<uchar>(mat,x0,y0,x1,y1,200);
    x = std::vector<int>();
    x.emplace_back(200);
    x.emplace_back(200);
    x.emplace_back(100);
    x.emplace_back(100);
    
    
    y = std::vector<int>();
    y.emplace_back(100);
    y.emplace_back(200);
    
    y.emplace_back(200);
    y.emplace_back(100);
    p = Polygon(x,y);
    
    isIntersect = CyrusBeckClipLine(x0,y0,x1,y1,p);
    
    drawPolygon<uchar>(mat,p,100);
    if (isIntersect!=0){
        drawLine<uchar>(mat,x0,y0,x1,y1,0);
    }
    
    cv::imwrite("polygonCut7.jpg", mat);

   

}