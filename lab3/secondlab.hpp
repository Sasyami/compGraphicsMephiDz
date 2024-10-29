

#include "firstlab.hpp"
template<typename T>
class Polygon{
    public:
        std::vector<T> x;
        std::vector<T> y;
    Polygon(){
        x = std::vector<T>();
        y = std::vector<T>();
    }
    Polygon (std::vector<int> x_, std::vector<int> y_){
        x = std::vector<T>();
        y = std::vector<T>();
        
        for (int i =0; i<std::min(x_.size(),y_.size());++i){
            x.emplace_back(x_[i]);
            y.emplace_back(y_[i]);
        }
        
        
    
        
    }
};

template<typename T>
void drawPolygon(cv::Mat& mat, Polygon<T> p, T color){
    for (int i =0;i<p.x.size()-1;++i){
        
        drawLine<T>(mat,p.x[i],p.y[i],p.x[i+1],p.y[i+1], color);
    }
    drawLine<T>(mat,p.x[p.x.size()-1],p.y[p.x.size()-1],p.x[0],p.y[0], color );
}


template<typename T>
bool isSimple(Polygon<T> p){
    T ax, ay, bx, by,cx,cy,dx,dy,nx,ny;
    double t1,t2;
    for (int i = 0; i<p.x.size()-1; ++i){
        for (int j = i+1; j<p.x.size()-1; ++j){
            ax = p.x[i];
            ay = p.y[i];
            bx = p.x[i+1];
            by = p.y[i+1];
            cx = p.x[j];
            cy = p.y[j];
            dx = p.x[j+1];
            dy = p.y[j+1];
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