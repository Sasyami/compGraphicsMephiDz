#ifndef HEADER_HPP51
#define HEADER_HPP51
#include "../lab3/firstlab.hpp"
#include "../lab3/secondlab.hpp"
#include <vector>
class Polygon3d{
    public:
        std::vector<std::vector<int>> x;
        int length;
        int dims;
        Polygon3d(){
            x = std::vector<std::vector<int>>();
            
            this->length = 0;
            this->dims = 0;
        }
        Polygon3d (std::vector<std::vector<int>> x_){
            x = std::vector<std::vector<int>>();
            std::vector<int> buf;
            this->length = x_.size();
            this ->dims = this->length>0?x_[0].size():0;
            for (int i =0; i<x_.size();++i){
                buf = std::vector<int>();
                for (int j = 0; j<dims;++j){
                    buf.emplace_back(x_[i][j]);
                }
                x.emplace_back(buf);
                
            }
            
            
        
            

        }
        
};
class Figure{
    public:
        Polygon3d up;
        Polygon3d down;

        Figure(Polygon3d nup, Polygon3d ndown){
            up = Polygon3d(nup.x);
            down = Polygon3d(ndown.x);
        }
        


};

void drawFigureOnZ(cv::Mat& mat, Figure f, uchar color){
    int n = f.up.x.size();
    for (int i = 0; i<f.up.x.size();++i){
        drawLine(mat,f.up.x[i][0],f.down.x[i][0],f.up.x[(i+1)%n][0],f.down.x[(i+1)%n][0],color);
    }
}

#endif