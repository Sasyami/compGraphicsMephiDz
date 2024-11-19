

#include "firstlab.hpp"

#ifndef HEADER_HPP2
#define HEADER_HPP2


class Polygon{
    public:
        std::vector<int> x;
        std::vector<int> y;
    private:
        int length;
    public:
        Polygon(){
            x = std::vector<int>();
            y = std::vector<int>();
            this->length = 0;
        }
        Polygon (std::vector<int> x_, std::vector<int> y_){
            x = std::vector<int>();
            y = std::vector<int>();
            this->length = x_.size();
            
            for (int i =0; i<std::min(x_.size(),y_.size());++i){
                x.emplace_back(x_[i]);
                y.emplace_back(y_[i]);
            }
            
            
        
            

        }
        int size(){
            return this->length;
        }   
};
enum ClPointType {NONE, LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN,
DESTINATION};


ClPointType Classify(int x1, int y1, int x2, int y2, int x, int y) {
    int ax = x2 - x1; //a

    int ay = y2 - y1;
    int bx = x - x1; //b
    int by = y - y1;
    int s = ax*by - bx*ay;
    
    if (s > 0) return LEFT;
    if (s < 0) return RIGHT;
    if ((ax*bx < 0) || (ay*by < 0)) return BEHIND; //позади
    if ((ax*ax + ay*ay) < (bx*bx + by*by)) return BEYOND; //впереди
    if (x1==x && y1==y) return ORIGIN;
    if (x2==x && y2==y) return DESTINATION;
    return BETWEEN; //между
}

template<typename T>
void drawPolygon(cv::Mat& mat, Polygon p, T color){
    for (int i =0;i<p.x.size()-1;++i){
        
        drawLine<T>(mat,p.x[i],p.y[i],p.x[i+1],p.y[i+1], color);
    }
    drawLine<T>(mat,p.x[p.x.size()-1],p.y[p.x.size()-1],p.x[0],p.y[0], color );
}


bool isSimple(Polygon p){
    int ax, ay, bx, by,cx,cy,dx,dy,nx,ny;
    double t1,t2;
    for (int i = 0; i<p.x.size()-1; ++i){
        for (int j = i+1; j<p.x.size()-1; ++j){
            ax = (p.x[i]);
            ay = (p.y[i]);
            bx = (p.x[i+1]);
            by = (p.y[i+1]);
            cx = (p.x[j]);
            cy = (p.y[j]);
            dx = (p.x[j+1]);
            dy = (p.y[j+1]);
            nx = dy - cy;
            ny = -dx + cx;
            if (nx*(bx -ax) + ny*(by-ay) == 0){
                continue;
            }else{
                t1 = - (double)(nx*(ax-cx) + ny*(ay-cy))/(double)(nx*(bx -ax) + ny*(by-ay));
            }
            
            nx = by - ay;
            ny = -bx + ax;
            if ((nx*(dx - cx) + ny*(dy - cy) ==0)){
                continue;
            }else{
                t2= - (double)(nx* (cx -ax) + ny * (cy - ay))/(double)(nx*(dx - cx) + ny*(dy - cy));
            }
            
            if ((t1>0 && t1<1) && (t2>0 && t2<1)){
                return false;
            }
        }

    }
    for (int i =0; i<p.x.size()-1;++i){
            ax = p.x[i];
            ay = p.y[i];
            bx = p.x[i+1];
            by = p.y[i+1];
            cx = p.x[p.x.size()-1];
            cy = p.y[p.y.size() -1];
            dx = p.x[0];
            dy = p.y[0];
            
            nx = dy - cy;
            ny = -dx + cx; 
            
            if((nx*(bx -ax) + ny*(by-ay))!=0){
                t1 = - (double)(nx*(ax-cx) + ny*(ay-cy))/(double)(nx*(bx -ax) + ny*(by-ay));
            }else{
                continue;
            }
            
            nx = by - ay;
            ny = -bx + ax;
            if (nx*(dx - cx) + ny*(dy - cy) == 0){
                continue;
            }else{
                t2= - (double)(nx* (cx -ax) + ny * (cy - ay))/(double)(nx*(dx - cx) + ny*(dy - cy));
            }
            
            
            if ((t1>0 && t1<1) && (t2> 0 && t2<1)){
                return false;
            }
    }
    return true;
}
//convT - type for multiplied and substracted values, if it can overflow T max value


bool isConvex(Polygon p ){

    for (int i = 0; i<p.x.size()-1;++i){
        ClPointType type = NONE;
        for (int j = 0; j<p.x.size(); ++j){
            ClPointType pt = Classify(p.x[i],p.y[i],p.x[i+1],p.y[i+1],p.x[j],p.y[j]);
            if (type == NONE && (pt == LEFT || pt==RIGHT)){
                type = pt;
            }else if (type != pt && pt!= ORIGIN && pt!=DESTINATION && pt!=BEHIND && pt!=BEYOND && pt!=BETWEEN){
                return false;
            }

        }
    }
    ClPointType type = NONE;
        for (int j = 0; j<p.x.size(); ++j){
            ClPointType pt = Classify(p.x[p.x.size()-1],p.y[p.y.size()-1],p.x[0],p.y[0],p.x[j],p.y[j]);
            if (type == NONE && (pt == LEFT || pt==RIGHT)){
                type = pt;
            }else if (type != pt && pt!= ORIGIN && pt!=DESTINATION && pt!=BEHIND && pt!=BEYOND && pt!=BETWEEN){
                return false;
            }

        }
    return true;

}

#endif