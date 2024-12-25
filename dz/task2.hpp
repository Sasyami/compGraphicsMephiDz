
#ifndef HEADER_HPPd2
#define HEADER_HPPd2
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../lab4/firstlab.hpp"
#include <cmath>
void drawDuga(cv::Mat& mat, double xr, double yr, double r, double alpha, double beta, int color){
    double buf = alpha;
    alpha = - beta;
    beta = -buf;
    yr = mat.rows - yr;
    std::vector<int> x = std::vector<int>();
    auto y = std::vector<int>();
    double angle = alpha;
    int n = 5;
    double h = (alpha - beta)/(pow(3,n));
    int xi, yi;
    for (int i = 0; i<=pow(3,n);++i){
        xi = xr + r*cos(angle);
        yi = yr + r*sin(angle);
        x.emplace_back(xi);
        y.emplace_back(yi);
        angle -= h;

    }
    drawLine<uchar>(mat, xr,yr, xr+r*cos(alpha),yr+r*sin(alpha), color);
    drawLine<uchar>(mat, xr,yr, xr+r*cos(beta),yr+r*sin(beta), color);
    Bezie(mat,x,y,3,color);




}


#endif