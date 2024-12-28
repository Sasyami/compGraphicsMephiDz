
#ifndef HEADER_HPP1
#define HEADER_HPP1

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

template <typename T>
void setPixel(cv::Mat& mat, int row, int col, T val){
    mat.at<T>(row,col) = val;
}

template <typename T>
void drawLine(cv::Mat& mat, int x1,int y1, int x2, int y2, T color){
    y1 = -y1;
    y2 = -y2;
    
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    int buf;
    
    if (deltaX>=deltaY && x1>x2){
        
        buf = x1;
        x1 = x2;
        x2 = buf;
        buf = y1;
        y1 = y2;
        y2 = buf;
        
    }
    else if (deltaY>deltaX && y1>y2){
        
        buf = x1;
        x1 = x2;
        x2 = buf;
        buf = y1;
        y1 = y2;
        y2 = buf;
        
    }
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int xStep = deltaX>=deltaY? 1: 0;
    int yStep = deltaY>deltaX? 1:0;
    int xAddition = deltaX<deltaY? signX: 0;
    int yAddition = deltaY<=deltaX? signY:0;
    int errorAddition = 2*std::min(deltaX,deltaY);
    int errorDeletion = -2*std::max(deltaX,deltaY);
    int error= errorDeletion/2;
    
   
    while (x1!=x2 || y1!=y2)
    {   
        setPixel<T>(mat,-y1,x1,color);
        error +=errorAddition;
        if (error >= 0){
            error +=errorDeletion;
            x1+=xAddition;
            y1+=yAddition;
            
        }
        x1 +=xStep;
        y1+= yStep;
        //std::cout<<x1<<" "<<y1<<std::endl;
        
        
    }
    //std::cout<<error<<std::endl;
    if (x1==x2 && y1 ==y2){
        setPixel(mat,-y1,x1,color);
    }
}

template <typename T>
void drawHatchedLine(cv::Mat& mat, int x1,int y1, int x2, int y2, int len, int space, T color){
    y1 = -y1;
    y2 = -y2;
    
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    int buf;
    
    if (deltaX>=deltaY && x1>x2){
        
        buf = x1;
        x1 = x2;
        x2 = buf;
        buf = y1;
        y1 = y2;
        y2 = buf;
        
    }
    else if (deltaY>deltaX && y1>y2){
        
        buf = x1;
        x1 = x2;
        x2 = buf;
        buf = y1;
        y1 = y2;
        y2 = buf;
        
    }
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int xStep = deltaX>=deltaY? 1: 0;
    int yStep = deltaY>deltaX? 1:0;
    int xAddition = deltaX<deltaY? signX: 0;
    int yAddition = deltaY<=deltaX? signY:0;
    int errorAddition = 2*std::min(deltaX,deltaY);
    int errorDeletion = -2*std::max(deltaX,deltaY);
    int error= errorDeletion/2;
    
    int xl = x1;
    int yl = y1;
    int sz = len;
    bool isSpace = false;
    while (x1!=x2 || y1!=y2)
    {   
        if ((x1-xl)*(x1 - xl) + (y1 - yl)*(y1 - yl) <=sz*sz){
            if (!isSpace){
                setPixel<T>(mat,-y1,x1,color);
            }
            
        }else{
            if (isSpace){
                sz = len;
                setPixel<T>(mat,-y1,x1,color);
            }else{
                sz = space;
            }
            xl = x1;
            yl = y1;
            isSpace = !isSpace;
        }
        
        
        error +=errorAddition;
        if (error >= 0){
            error +=errorDeletion;
            x1+=xAddition;
            y1+=yAddition;
            //++is;
            
        }
        x1 +=xStep;
        y1+= yStep;
        //std::cout<<x1<<" "<<y1<<std::endl;
        
        
    }
    //std::cout<<error<<std::endl;
    if (x1==x2 && y1 ==y2 && !isSpace){
        setPixel(mat,-y1,x1,color);
    }
}



#endif