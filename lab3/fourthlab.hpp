#ifndef HEADER_HPP4
#define HEADER_HPP4
#include "secondlab.hpp"
enum EType {TOUCHING, CROSS_LEFT, CROSS_RIGHT, INESSENTIAL};

EType EdgeType(double ox, double oy, double dx, double dy, double ax, double ay) {
    switch(Classify(ox, oy, dx, dy, ax, ay)) {
        case LEFT:
            if(ay > oy && ay <= dy) return CROSS_LEFT; // пересекающая, A слева
            else return INESSENTIAL; // безразличная
        case RIGHT:
            if(ay > dy && ay <= oy) return CROSS_RIGHT; // пересекающая, A справа
            else return INESSENTIAL; // безразличная
        case BETWEEN:
        case ORIGIN:
        case DESTINATION:   
            return TOUCHING; // касающаяся
        default:
            return INESSENTIAL; // безразличная
    }
}
enum PType {OUTSIDE, INSIDE};

PType PInPolygonEOMode(int x, int y, //точка
        Polygon p) { //количество вершин в полигоне
    int param = 0;
    for(int i = 0; i < p.x.size(); i++) {
        switch(EdgeType(p.x[i], -p.y[i], p.x[(i+1)%p.x.size()], -p.y[(i+1)%p.x.size()], x, -y)) {
            case TOUCHING: //если лежит на полигоне, то заведомо принадлежит
                return INSIDE;
            case CROSS_LEFT:
            case CROSS_RIGHT:
                param= 1 - param; //изменяем значение четности
        }
    }
    if (param == 1) return INSIDE; //нечетное
    else return OUTSIDE;

}
PType PInPolygonNZWMode(int x, int y, //точка
        Polygon p) { //количество вершин в полигоне
    int param = 0;
    for(int i = 0; i < p.x.size(); i++) {
        switch(EdgeType(p.x[i], p.y[i], p.x[(i+1)%p.x.size()], p.y[(i+1)%p.x.size()], x, y)) {
            case TOUCHING: //если лежит на полигоне, то заведомо принадлежит
                return INSIDE;
            case CROSS_LEFT:
                param+=1;
                break;
            case CROSS_RIGHT:
                param-=1; //изменяем значение четности
                break;
            
        }

    }
    if (param !=0) return INSIDE; //нечетное
    else return OUTSIDE;

}


template <typename T>
void fillPolygon(cv::Mat& mat,PType (*rule)(int x, int y, Polygon p), Polygon p, T color){
    drawPolygon<T>(mat,p,color);
    for (int i =0 ;i<mat.rows;++i){
        for (int j =0; j<mat.cols; ++j){
            if (rule(j,i,p) == INSIDE){
                mat.at<uchar>(i,j) = color;
            }
        }
    }
}

#endif