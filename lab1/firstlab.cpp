#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std; 

double B(double a, double b){
    double c = a*b;
    return c;
}

Mat blendGRAY(Mat a, Mat b, Mat alpha){
    Mat c(a);
    for (int i = 0;i<a.rows; ++i){
        for (int j = 0;j<a.cols; ++j){
            double av = a.at<uchar>(i,j)*1./255;
            double bv = b.at<uchar>(i,j)*1./255;
            double alphav1 = alpha.at<uchar>(i,j)*1./255;
            double alphav2 = 1-alpha.at<uchar>(i,j)*1./255;
            c.at<uchar>(i,j) = (int)255*((1-alphav1)*alphav2*av+ alphav1*(1-alphav2)*bv + alphav1*alphav2*B(av,bv));
        }
    }
    return c;
}

int main(){

    Mat alpha = imread("alpha.jpg", 
                       IMREAD_GRAYSCALE); 
    
    // Error Handling 
    
    Mat image1 = imread("image1.jpg", 
                       IMREAD_GRAYSCALE); 
    Mat image2 = imread("image2.jpg", 
                       IMREAD_GRAYSCALE); 
    
    
    
    
    // Show Image inside a window with 
    // the name provided 
    imwrite("Output.jpg", blendGRAY(image1,image2,alpha)); 
  
    // Wait for any keystroke 
    
    return 0; 

}