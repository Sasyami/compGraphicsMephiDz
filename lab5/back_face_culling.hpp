
#ifndef HEADER_HPP53
#define HEADER_HPP53
#include "../lab3/firstlab.hpp"
#include "../lab3/secondlab.hpp"
#include <vector>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include "figure.hpp"
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

void SetPixel(Mat& img, int x, int y, int r, int g, int b) {
    if (x >= 0 && x < img.cols && y >= 0 && y < img.rows)
        img.at<Vec3b>(y, x) = Vec3b(r, g, b);
}


void Line(Mat& img, int x1, int y1, int x2, int y2, int color) {
    int x = x1, y = y1;
    int dx = x2 - x1, dy = y2 - y1;
    int e, i;
    int ix = (dx > 0) ? 1 : (dx < 0) ? -1 : 0;
    if (ix == -1) dx = -dx;
    int iy = (dy > 0) ? 1 : (dy < 0) ? -1 : 0;
    if (iy == -1) dy = -dy;

    auto setPixel = [&](int x, int y) {
        int r = color & 0xFF;
        int g = (color >> 8) & 0xFF;
        int b = (color >> 16) & 0xFF;
        SetPixel(img, x, y, r, g, b);
    };

    if (dx >= dy) {
        e = 2 * dy - dx;
        for (i = 0; i <= dx; i++) {
            setPixel(x, y);
            if (e >= (iy >= 0 ? 0 : 1)) {
                y += iy;
                e -= 2 * dx;
            }
            x += ix;
            e += dy * 2;
        }
    }
    else {
        e = 2 * dx - dy;
        for (i = 0; i <= dy; i++) {
            setPixel(x, y);
            if (e >= (ix >= 0 ? 0 : 1)) {
                x += ix;
                e -= 2 * dy;
            }
            y += iy;
            e += dx * 2;
        }
    }
}

std::vector<Polygon3d> getPolygons(Figure f){
    auto out = std::vector<Polygon3d>();
    out.emplace_back(f.up);
    out.emplace_back(f.down);
    int n = f.up.x.size();
    for (int i = 0; i<n;++i){
        
        std::vector<std::vector<double>> vpol = std::vector<std::vector<double>>();
        vpol.emplace_back(f.down.x[i]);
        vpol.emplace_back(f.down.x[(i+1)%n]);
        
        vpol.emplace_back(f.up.x[(i+1)%n]);
        vpol.emplace_back(f.up.x[i]);
       
        
        out.emplace_back(Polygon3d(vpol));
    }
    return out;
}

void drawPolygonZ(Mat& mat, const Polygon3d& pol){
    for (int i = 0; i<pol.x.size();++i){
        Line(mat,pol.x[i][0], pol.x[i][1], pol.x[(i+1)%pol.x.size()][0], pol.x[(i+1)%pol.x.size()][1], 0xB4A7D6);
    }
}
void drawVisibleFaces(Mat& mat, Figure figure) {
    std::vector<Point2f> projectedPoints;

    Vec3f c;
    for (const auto& v: figure.up.x){
        c[0] += v[0]/(figure.up.x.size()*2);
        c[1] += v[1]/(figure.up.x.size()*2);
        c[2] += v[2]/(figure.up.x.size()*2);
    }

    for (const auto& v: figure.down.x){
        c[0] += v[0]/(figure.up.x.size()*2);
        c[1] += v[1]/(figure.up.x.size()*2);
        c[2] += v[2]/(figure.up.x.size()*2);
    }

    
    std::vector<Polygon3d> polygons = getPolygons(figure);
    
    Vec3f v(0, 0, -1);
    
    for (const Polygon3d& p: polygons){
        Vec3f n;
        Vec3f a,b;
        a[0] = p.x[1][0] - p.x[0][0];
        a[1] = p.x[1][1] - p.x[0][1];
        a[2] = p.x[1][2] - p.x[0][2];

        b[0] = p.x[2][0] - p.x[0][0];
        b[1] = p.x[2][1] - p.x[0][1];
        b[2] = p.x[2][2] - p.x[0][2];


        n[0] = a[1]*b[2] - a[2]*b[1];
        n[1] = a[2]*b[0] - a[0]*b[2];
        n[2] = a[0]*b[1] - a[1]*b[0];
        
        if (n[0]*(c[0] - p.x[0][0]) + n[1]*(c[1] - p.x[0][1])+n[2]*(c[2] - p.x[0][2])>0){
            n *= -1;
        }
        if (n[2]<0){
            drawPolygonZ(mat,p);
        }
        


        
    }
    //mat.at<uchar>(c[1],c[0]) = 125;
}

#endif