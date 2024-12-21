
#ifndef HEADER_HPP41
#define HEADER_HPP41

#include <iostream>
#include <cmath>
#include<vector>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../lab3/firstlab.hpp"
double line(double p0, double p1, double t)
{
    return p0 * (1.0 - t) + p1 * t;
}
double Bezie_rec(std::vector<int> vec, double t, int m){
    //std::cout<<vec.size()<<std::endl;
    if (m==1){
        return line(vec[0],vec[1],t);
    }
    if (t>1){
        t=1;
    }
    
    
    std::vector<int> first = std::vector<int>(vec);
    first.pop_back();
    
    std::vector<int> last = std::vector<int>(vec);
    last.erase(last.begin());
    
    
    return line(Bezie_rec(first,t,m-1),Bezie_rec(last,t,m-1),t);
}

void BezieOne(cv::Mat& mat, uchar color, std::vector<int> x, std::vector<int> y, int m){
    int N;
    
    if (m==3){
        N = 1 + pow((3*std::max(std::abs(x[0] - 2*x[1] + x[2]) + std::abs(y[0] - 2*y[1] + y[2]), std::abs(x[1] - 2*x[2] + x[3]) + std::abs(y[1] - 2*y[2] + y[3]))),0.5);
    }else{
        N = 1 + pow(m*((int)*(std::max_element(x.begin(), x.end()))  + (int)*(std::max_element(y.begin(), y.end()))) - (int)*(std::min_element(x.begin(), x.end())) - (int)*(std::min_element(y.begin(), y.end())),0.5);

    }
    //std::cout<<N<<std::endl;
    
    double h = 1./N;
    double t = 0;
    int xc, yc, nxc, nyc;
    xc = (int)Bezie_rec(x,t,m);
    yc = (int)Bezie_rec(y,t,m);
    

    while (t<1){
        t+=h;
        //std::cout<<t<<" "<<Bezie_rec(x,t,m)<<std::endl;
        nxc = (int)Bezie_rec(x,t,m);
        nyc = (int)Bezie_rec(y,t,m);
        //std::cout<<t<<" "<<xc<<" "<<yc<<" "<<nxc<<" "<<nyc<<std::endl;
        drawLine<uchar>(mat,xc,yc,nxc,nyc,color);
        xc = nxc;
        yc = nyc;
        
        
    }
}
void Bezie(cv::Mat&mat, std::vector<int>x, std::vector<int> y, int m, uchar color){
    std::vector<int> xChunk = std::vector<int>();
    std::vector<int> yChunk = std::vector<int>();
    if (((int)x.size())%m != 1 || ((int)y.size())%m != 1){
        return;
    }
    int i =-1;
    //m = m-1;
    for (int k = 0; k<=m; ++k){
        ++i;
        xChunk.emplace_back(x[i]);
        yChunk.emplace_back(y[i]);
    }
    BezieOne(mat,color, xChunk,yChunk, m);
    xChunk = std::vector<int>();
    yChunk = std::vector<int>();
    
    while (i<x.size()-1 && i<y.size()-1){

        for (int k =0; k<m; ++k){
            xChunk.emplace_back(x[i]);
            yChunk.emplace_back(y[i]);
            ++i;
        }
        xChunk.emplace_back(x[i]);
        yChunk.emplace_back(y[i]);
        BezieOne(mat,color,xChunk, yChunk, m);
        xChunk = std::vector<int>();
        yChunk = std::vector<int>();
        //std::cout<< i<<std::endl;
    }

}

#endif