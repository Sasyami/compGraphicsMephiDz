#ifndef HEADER_HPP52
#define HEADER_HPP52
#include "../lab3/firstlab.hpp"
#include "../lab3/secondlab.hpp"
#include <vector>
#include "figure.hpp"


void drawPerspectiveOnZ(cv::Mat& mat, Figure f, float k, uchar color){
    int n = f.up.x.size();
    for (int i = 0; i<n;++i){
        drawLine(mat,f.up.x[i][0]/(k*f.up.x[i][2] +1),f.up.x[i][1]/(k*f.up.x[i][2] + 1) ,f.down.x[i][0] / (k*f.down.x[i][2] +1),f.down.x[i][1]/(k*f.down.x[i][2] +1),color);
        drawLine(mat,f.up.x[i][0]/(k*f.up.x[i][2] +1),f.up.x[i][1]/(k*f.up.x[i][2] +1),f.up.x[(i+1)%n][0]/(k*f.up.x[(i+1)%n][2] +1),f.up.x[(i+1)%n][1]/((k*f.up.x[(i+1)%n][2] +1)),color);
        drawLine(mat,f.down.x[i][0]/((k*f.down.x[i][2] +1)),f.down.x[i][1]/(k*f.down.x[i][2] +1),f.down.x[(i+1)%n][0]/(k*f.down.x[(i+1)%n][2] +1),f.down.x[(i+1)%n][1]/(k*f.down.x[(i+1)%n][2] +1),color);


    }
}
#endif