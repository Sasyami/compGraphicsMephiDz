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
Vec4b B(Vec4b a, Vec4b b){
    
    return Vec4b(((int)a[0]*(int)b[0]),((int)a[1]*(int)b[1]),((int)a[2]*(int)b[2]),((int)a[3]*(int)b[3]));
}

Mat blendGRAY(Mat a, Mat b, Mat alpha){
    Mat c(a);
    for (int i = 0;i<a.rows; ++i){
        for (int j = 0;j<a.cols; ++j){
            double av = a.at<uchar>(i,j)*1./255;
            double bv = b.at<uchar>(i,j)*1./255;
            double alphav1 = alpha.at<uchar>(i,j)*1./255;
            double alphav2 = alpha.at<uchar>(i,j)*1./255;
            c.at<uchar>(i,j) = (int)255*((1-alphav1)*alphav2*av+ alphav1*(1-alphav2)*bv + alphav1*alphav2*B(av,bv));
        }
    }
    return c;
}
Mat blendRGB(Mat a, Mat b, Mat alpha){
    Mat c(a);
    for (int i = 0;i<a.rows; ++i){
        for (int j = 0;j<a.cols; ++j){
            Vec4b av = a.at<Vec4b>(i,j);
            Vec4b bv = b.at<Vec4b>(i,j);
            double alphav1 = alpha.at<uchar>(i,j)*1./255;
            double alphav2 = 1-alpha.at<uchar>(i,j)*1./255;
            Vec4b buf = ((1-alphav1)*alphav2*av+ alphav1*(1-alphav2)*bv + alphav1*alphav2*B(av,bv));
            
            c.at<Vec4b>(i,j) = Vec4b((int)buf[0],(int)buf[1],(int)buf[2], (int)buf[3]);
        }
    }
    
    return c;
}

Mat mirrorize(Mat mat){
    Mat m(mat.rows, mat.cols, mat.type());
    for (int i = 0;i<mat.rows;++i){
        for (int j = 0; j<mat.cols;++j){
            int val = mat.at<uchar>(i,j);
           
            m.at<uchar>(i,mat.cols -1 -j) = val;
            
            
        }
    }
    return m;

}
Mat transpose(Mat mat){
    Mat m(mat.cols,mat.rows,CV_8UC1);
    for (int i = 0;i<mat.rows;++i){
        for (int j = 0; j<mat.cols;++j){
            m.at<uchar>(j,i) = mat.at<uchar>(i,j);
        }
    }
    return m;
}
int main(){

    Mat alpha = imread("alpha.jpg", 
                       IMREAD_GRAYSCALE); 

    
    Mat image1 = imread("image1.jpg", 
                       IMREAD_GRAYSCALE); 
    Mat image2 = imread("image2.jpg", 
                       IMREAD_GRAYSCALE); 
    
    
    
    imwrite("transpozed.jpg",transpose(image2));
    imwrite("mirrorized.jpg",mirrorize(image2));
 
    Mat image1RGB;
    Mat image2RGB;
 
    image1RGB = imread("image1RGB.jpg",IMREAD_COLOR_RGB);
    image2RGB = imread("image2RGB.jpg",IMREAD_COLOR_RGB);
    cvtColor(image1RGB,image1RGB,COLOR_BGR2BGRA);
    cvtColor(image2RGB,image2RGB,COLOR_BGR2BGRA);

    imwrite("blendRGB.jpg",blendRGB(image1RGB,image2RGB,alpha) );

    imwrite("blendGRAY.jpg", blendGRAY(image1,image2,alpha)); 
    
   
    return 0; 

}