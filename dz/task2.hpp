
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
    /* double buf = alpha;
    alpha = - beta;
    beta = -buf;
    yr = mat.rows - yr; */
    

    double beta1 = std::max(beta, alpha - M_PI/2);

    
    
    for (int i =0; alpha>beta; ++i){
        double x0 = xr+ r*cos(alpha);
        double y0 = yr + r*sin(alpha);

        double x3 = xr +r*cos(beta1);
        double y3 = yr + r*sin(beta1);
        double xt;
        double yt;
        double t;
        if (abs(cos(beta1) + sin(beta1) + cos(alpha) - sin(alpha))> 0.01){
            t = (x0+y0 - x3 - y3)/(cos(beta1) + sin(beta1) + cos(alpha) - sin(alpha));

        }else{
            t = (x3 - x0 )/(sin(beta1)+ sin(alpha));
            

        }
        xt = x3 - t*sin(beta1);
        yt = y3 + t*cos(beta1);
        double d = abs(t);
        double F = 4./3./(1. + sqrt((1 + (d/r) * (d/r))));
        
        double x1 = x0 + F*(xt - x0);
        double y1 = y0 + F*(yt - y0);
        double x2 = x3 + F*(xt - x3);
        double y2 = y3 + F*(yt - y3);


        std::vector<int> x = std::vector<int>();
        std::vector<int> y = std::vector<int>();
        x.emplace_back(x0);
        x.emplace_back(x1);
        x.emplace_back(x2);
        x.emplace_back(x3);
        y.emplace_back(y0);
        y.emplace_back(y1);
        y.emplace_back(y2);
        y.emplace_back(y3);
        for (int i =0 ;i<y.size();++i){
            std::cout<<x[i]<<","<<y[i]<<" ";
        }
        std::cout<<"\n"<<alpha<<" "<<beta1<<std::endl;;
        Bezie(mat,x,y,3,(uchar) color);
        alpha = beta1;
        beta1 = std::max(beta, alpha - M_PI/2);
        
        



    }
    




}


#endif