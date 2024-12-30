
#ifndef HPP53
#define HPP53
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "figure.hpp"


std::vector<std::vector<double>> transform(std::vector<std::vector<double>> up1, cv::Mat transformationMatrix){
    
    std::vector<std::vector<double>> up(up1);
    
    for (int i =0; i<up.size();++i){
        
        
        
        auto d = up[i];
        cv::Mat pointMat = (cv::Mat_<double>(4, 1) << d[0], d[1], d[2], 1);
        cv::Mat transformedPoint = transformationMatrix.t() * pointMat;
    
        
        d[0] = transformedPoint.at<double>(0)/transformedPoint.at<double>(3);
        d[1] = transformedPoint.at<double>(1)/transformedPoint.at<double>(3);
        d[2] = transformedPoint.at<double>(2)/transformedPoint.at<double>(3);
        up[i] = d;

    }
    
    return up;
}


#endif