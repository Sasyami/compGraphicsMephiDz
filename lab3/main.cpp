#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "secondlab.hpp"

int main(){
    cv::Mat mat = cv::Mat(200,200, CV_8UC1,255);
    //drawLine<uchar>(mat,0,50,50,0,0);
    
    //drawThickLine<uchar>(mat,30,40,50,10,0,4);
    
    std::vector<int>a;
    std::vector<int>b;
    a.emplace_back(0);
    a.emplace_back(0);
    a.emplace_back(100);
    a.emplace_back(100);


    b.emplace_back(0);
    b.emplace_back(100);
    b.emplace_back(0);
    b.emplace_back(100);
    Polygon<int> p(a,b);
    //drawPolygon<uchar>(mat,p,0);
    //imwrite("test.jpg",mat);
    std::cout<<isSimple<int>(p)<<std::endl;
    
}