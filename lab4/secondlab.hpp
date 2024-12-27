
#ifndef HEADER_HPP42
#define HEADER_HPP42
#include <iostream>
#include <cmath>
#include<vector>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../lab3/secondlab.hpp"

int CyrusBeckClipLine(double& x1, double& y1, double& x2, double& y2, Polygon p){
    if (!isConvex(p)){
        return -1;
    }
    double t1 = 0, t2 = 1, t;
    double sx= x2-x1, sy= y2-y1;
    std::vector<int> px = p.x;
    std::vector<int> py = p.y;
    int n = (int)px.size();
    double nx, ny, denom, num, x1_new, y1_new, x2_new, y2_new;
    for(int i = 0; i < n; i++) {
        nx= py[(i+1)%n]-py[i]; ny= px[i]-px[(i+1)%n]; 
        denom= nx*sx+ny*sy; 
        num= nx*(x1-px[i])+ny*(y1-py[i]);
        if(denom != 0) { 
            t= -num/denom;
            if( denom > 0) { 
                if(t > t1) t1=t; 
            }
            else { 

                if(t < t2) t2=t; 
            }

        } 
        //else { if (Classify(px[i], py[i], px[(i+1)%n], py[(i+1)%n],x1,y1)==LEFT) return 0; } 
    } 
    if(t1 <= t2) { 
        x1_new = x1+t1*(x2-x1); y1_new = y1+t1*(y2-y1);
        x2_new = x1+t2*(x2-x1); y2_new = y1+t2*(y2-y1);
        x1 = x1_new; y1 = y1_new; x2 = x2_new; y2 = y2_new;
        return 1; 
    }else{
        x1_new = x1+t1*(x2-x1); y1_new = y1+t1*(y2-y1);
        x2_new = x1+t2*(x2-x1); y2_new = y1+t2*(y2-y1);
        x2 = x1_new; y2 = y1_new; x1 = x2_new; y1 = y2_new;
    }
    return 0; 
}
#endif