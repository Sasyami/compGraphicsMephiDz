#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;
int findClosest(int* array, int len, int val){
    int diff = INT_MAX;
    for (int i = 0; i<len;++i){
        if (abs(array[i] - val)<=diff){
            diff = abs(array[i] - val);
        }else{
            return i-1;
        }
    }
    return (len - 1);
    
} 
Mat dizz(Mat mat, int n){
    Mat nmat(mat);
    int len = (int)pow(2.,(double)n);
    int vals[len];
    int error = 0;
    
    for (int i =0; i<len ;++i){
        
        vals[i] = (int)(255./(len-1)*i);
        
    }
    
    for (int i = 0; i<nmat.rows-1; ++i){
        for (int j = 1;j <nmat.cols-1;++j){
            error = nmat.at<uchar>(i,j) - vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            nmat.at<uchar>(i,j) = vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            nmat.at<uchar>(i,j+1) += (int)(7./16.*error);
            nmat.at<uchar>(i+1,j-1) += (int)(3./16.*error);
            nmat.at<uchar>(i,j) += (int)(5./16.*error);
            nmat.at<uchar>(i,j+1) += (int)(1./16.*error);
        }
    }
    for (int i = 0;i<nmat.rows;++i){
        nmat.at<uchar>(i,0) = vals[findClosest(vals,len,nmat.at<uchar>(i,0))];

    }
    for (int j = 1;j<nmat.cols;++j){
        nmat.at<uchar>(nmat.rows-1,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-1,j))];
    }
    return nmat;

}
int main(){
    Mat image1 = imread("image1.jpg", 
                       IMREAD_GRAYSCALE); 
    
    
    imwrite("output1.png",dizz(image1,2));
}