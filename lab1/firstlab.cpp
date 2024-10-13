#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std; 
int min(int a,int b){
    if (a>b){
        return b;
    }
    return a;
}
void circilize(Mat* mat){
    for (int i = 0;i<mat->rows;++i){
        for (int j = 0; j<mat->cols;++j){
            Vec4b buf = mat->at<Vec4b>(i,j);
            
            int r = min(mat->rows,mat->cols)*1./2.;
            if ((mat->rows/2. -i)*(mat->rows/2. -i)+(mat->cols/2. -j)*(mat->cols/2. -j)>r*r){
                buf[3] = 0;
            }
            mat->at<Vec4b>(i,j) = buf;
           
            
        }
    }

}
int main(){
    Mat alpha = imread("image1jpg", 
                       IMREAD_GRAYSCALE); 
    Mat alphaRGBA;
    cvtColor(alpha,alphaRGBA,COLOR_GRAY2RGBA);
    circilize(&alphaRGBA);
    
    imwrite("output1.png",alphaRGBA);
    //circilize(alphaRGBA);
}