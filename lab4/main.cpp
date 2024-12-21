#include <iostream>
#include "firstlab.hpp"
#include "secondlab.hpp"
int main(){
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
    //Bezie(mat,x,y,m,0);//300+100-200=0, 150+50 - 200 =0, 200-2*150 +100 = 0, 400+200-300*2=0
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
    //Bezie(mat,x,y,m,0);
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
    cv::imwrite("bezie4.jpg", mat);

    double y0 = 0;
    double x0 = 0;
    double x1 = 400;
    double y1 = 400;
    mat = cv::Mat(500,500, CV_8UC1,255);
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
    CyrusBeckClipLine(x0,y0,x1,y1,p);
    //std::cout<<y0<<" "<<y1<<std::endl;
    drawPolygon<uchar>(mat,p,100);
    drawLine<uchar>(mat,x0,y0,x1,y1,0);
    cv::imwrite("polygonCut.jpg", mat);
    
    //drawLine<uchar>(mat,178,154,176,156,0);

    //std::cout<<Bezie_rec(x1,0.9,2)<<std::endl;
    //BezieOne(mat,0, x1,y1,2);
    
    

}