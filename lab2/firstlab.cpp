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
    Mat orig = mat.clone();
    int len = 1<<n;
    int vals[len];
    int error = 0;
    
    
    for (int i =0; i<len ;++i){
        
        vals[i] = (int)(255./(len-1)*i);
        
        
    }
    
    for (int i = 0; i<nmat.rows-1; ++i){
        for (int j = 1;j <nmat.cols-1;++j){
            
            error = nmat.at<uchar>(i,j) - vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            
            nmat.at<uchar>(i,j) = vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            
            nmat.at<uchar>(i,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+1) + (7*error/16)));
            nmat.at<uchar>(i+1,j-1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-1) + (3*error/16)));
            nmat.at<uchar>(i+1,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j) + (5*error/16)));
            nmat.at<uchar>(i+1,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+1) + (1*error/16)));
            
            
        }
    }
    for (int i = 0;i<nmat.rows;++i){
        nmat.at<uchar>(i,0) = vals[findClosest(vals,len,nmat.at<uchar>(i,0))];
        nmat.at<uchar>(i,nmat.cols - 1) = vals[findClosest(vals,len,nmat.at<uchar>(i,nmat.cols - 1))];

    }
    for (int j = 1;j<nmat.cols;++j){
        nmat.at<uchar>(nmat.rows-1,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-1,j))];
    }

    return nmat;

}

Mat dizzSnake(Mat mat, int n){
    Mat nmat(mat);
    
    int len = (int)1<<n;
    int vals[len];
    int error = 0;
   
    for (int i =0; i<len ;++i){
        
        vals[i] = (int)(255./(len-1)*i);
        
    }
    int start = 1;
    int end = nmat.cols - 1 -1;
    int dir = 1;
    for (int i = 0; i<nmat.rows-1; ++i){
        for (int j = start;j != end+dir;j = j+dir){
            
            error = nmat.at<uchar>(i,j) - vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            nmat.at<uchar>(i,j) = vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            nmat.at<uchar>(i,j+dir) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+dir) + (7*error/16)));
            nmat.at<uchar>(i+1,j-dir) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-dir) + (3*error/16)));
            nmat.at<uchar>(i+1,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j) + (5*error/16)));
            nmat.at<uchar>(i+1,j+dir) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+dir) + (1*error/16)));
            
        }
        std::swap(start, end);
        dir =dir *(-1);
    }

    for (int i = 0;i<nmat.rows;++i){

        nmat.at<uchar>(i,0) = vals[findClosest(vals, len, nmat.at<uchar>(i,0))];
        nmat.at<uchar>(i,nmat.cols -1) = vals[findClosest(vals, len, nmat.at<uchar>(i,nmat.cols - 1))];
        
    }
    
    for (int j = 1;j<nmat.cols;++j){
        nmat.at<uchar>(nmat.rows-1,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-1,j))];
    }
    
    return nmat;


}
Mat stucki(Mat mat, int n){
    Mat nmat(mat);
    int len = 1<<n;
    int vals[len];
    int error = 0;
   
    for (int i =0; i<len ;++i){
        
        vals[i] = (int)(255./(len-1)*i);
        
    }
    
    for (int i = 0; i<nmat.rows-2; ++i){
        for (int j = 2;j <nmat.cols-2;++j){
            
            error = nmat.at<uchar>(i,j) - vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            nmat.at<uchar>(i,j) = vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            nmat.at<uchar>(i,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+1) + (8*error/42)));
            nmat.at<uchar>(i,j+2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+2) + (4*error/42)));
            nmat.at<uchar>(i+1,j-2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-2) + (2*error/42)));
            nmat.at<uchar>(i+1,j-1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-1) + (4*error/42)));
            nmat.at<uchar>(i+1,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j) + (8*error/42)));
            nmat.at<uchar>(i+1,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+1) + (4*error/42)));
            nmat.at<uchar>(i+1,j+2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+2) + (2*error/42)));
            nmat.at<uchar>(i+2,j-2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j-2) + (1*error/42)));
            nmat.at<uchar>(i+2,j-1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j-1) + (2*error/42)));
            nmat.at<uchar>(i+2,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j) + (4*error/42)));
            nmat.at<uchar>(i+2,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j+1) + (2*error/42)));
            nmat.at<uchar>(i+2,j+2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j+2) + (1*error/42)));
        }
    }
    for (int i = 0;i<nmat.rows;++i){
        nmat.at<uchar>(i,0) = vals[findClosest(vals,len,nmat.at<uchar>(i,0))];
        nmat.at<uchar>(i,1) = vals[findClosest(vals,len,nmat.at<uchar>(i,1))];
        nmat.at<uchar>(i,nmat.cols -1 ) = vals[findClosest(vals,len,nmat.at<uchar>(i,nmat.cols-1))];
        nmat.at<uchar>(i,nmat.cols - 2 ) = vals[findClosest(vals,len,nmat.at<uchar>(i,nmat.cols-2))];
    }
    for (int j = 2;j<nmat.cols-2;++j){
        nmat.at<uchar>(nmat.rows-1,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-1,j))];
        nmat.at<uchar>(nmat.rows-2,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-2,j))];
    }

    return nmat;

}
Mat stuckiFloyd(Mat mat, int n){
    Mat nmat(mat);
    
    int len = (int)1<<n;
    //std::cout<<len<<std::endl;
    int vals[len];
    int error = 0;
   
    for (int i =0; i<len ;++i){
        
        vals[i] = (int)(255./(len-1)*i);
        
    }
    int start = 2;
    int end = nmat.cols - 1 -1-1;
    int dir = 1;
    for (int i = 0; i<nmat.rows-1; ++i){
        for (int j = start;j != end+dir;j = j+dir){
            
            error = nmat.at<uchar>(i,j) - vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
            if (i%2!=0){
                nmat.at<uchar>(i,j) = vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
                nmat.at<uchar>(i,j+dir) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+dir) + (7*error/16)));
                nmat.at<uchar>(i+1,j-dir) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-dir) + (3*error/16)));
                nmat.at<uchar>(i+1,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j) + (5*error/16)));
                nmat.at<uchar>(i+1,j+dir) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+dir) + (1*error/16)));
            }else{
                nmat.at<uchar>(i,j) = vals[findClosest(vals,len,nmat.at<uchar>(i,j))];
                nmat.at<uchar>(i,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+1) + (8*error/42)));
                nmat.at<uchar>(i,j+2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i,j+2) + (4*error/42)));
                nmat.at<uchar>(i+1,j-2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-2) + (2*error/42)));
                nmat.at<uchar>(i+1,j-1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j-1) + (4*error/42)));
                nmat.at<uchar>(i+1,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j) + (8*error/42)));
                nmat.at<uchar>(i+1,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+1) + (4*error/42)));
                nmat.at<uchar>(i+1,j+2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+1,j+2) + (2*error/42)));
                nmat.at<uchar>(i+2,j-2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j-2) + (1*error/42)));
                nmat.at<uchar>(i+2,j-1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j-1) + (2*error/42)));
                nmat.at<uchar>(i+2,j) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j) + (4*error/42)));
                nmat.at<uchar>(i+2,j+1) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j+1) + (2*error/42)));
                nmat.at<uchar>(i+2,j+2) = std::max(0, std::min(255,(int)nmat.at<uchar>(i+2,j+2) + (1*error/42)));
            }
            
        }
        std::swap(start, end);
        dir =dir *(-1);
    }
    for (int i = 0;i<nmat.rows;++i){
        nmat.at<uchar>(i,0) = vals[findClosest(vals,len,nmat.at<uchar>(i,0))];
        nmat.at<uchar>(i,1) = vals[findClosest(vals,len,nmat.at<uchar>(i,1))];
        nmat.at<uchar>(i,nmat.cols -1 ) = vals[findClosest(vals,len,nmat.at<uchar>(i,nmat.cols-1))];
        nmat.at<uchar>(i,nmat.cols - 2 ) = vals[findClosest(vals,len,nmat.at<uchar>(i,nmat.cols-2))];
    }
    for (int j = 2;j<nmat.cols-2;++j){
        nmat.at<uchar>(nmat.rows-1,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-1,j))];
        nmat.at<uchar>(nmat.rows-2,j) = vals[findClosest(vals,len,nmat.at<uchar>(nmat.rows-2,j))];
    }

    return nmat;
}
int main(){
    Mat image1 = imread("image1.jpg", 
                       IMREAD_GRAYSCALE);
    int n = 2;

    {imwrite("output1.png",dizz(image1.clone(),n));}
    {imwrite("output1snaked.png",dizzSnake(image1.clone(),n));}
    {imwrite("output1stucki.png", stucki(image1.clone(),n));}
    {imwrite("outputStuckiFloyd.png", stuckiFloyd(image1,n));}

}