
#ifndef HEADER_HPPd3
#define HEADER_HPPd3
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
float dist(cv::Vec3b a, cv::Vec3f b){
    
    return (a[0]-b[0])*(a[0] - b[0]) + (a[1]-b[1])*(a[1] - b[1]) + (a[2]-b[2])*(a[2] - b[2]);
}
void kMeans(cv::Mat& mat, int k){
    
    std::vector<cv::Vec3f> ks = std::vector<cv::Vec3f>();
    int* kis = new int[k];
    cv::Mat klusts = cv::Mat(mat.rows, mat.cols, CV_8UC1);
    for (int i =0; i<k;++i){
        cv::Vec3f buf = cv::Vec3f(256./k*i,256/k*i,256/k*i);
        
        ks.emplace_back(buf);
    }
    bool pass = true;
    while (pass){
        pass = false;
        for (int i = 0; i<k;++i){
            kis[i] = 0;
           
        }
        for (int i = 0; i<mat.rows;++i){
            for (int j = 0; j<mat.cols;++j){
                float min_dist = 27000000;
                int min_k = -1;
                for (int ki = 0; ki<k;++ki){
                    float d = dist(mat.at<cv::Vec3b>(i,j), ks[ki]);
                    //std::cout<<i<<" "<<j<<std::endl;
                    if (d<min_dist){
                        min_dist = d;
                        min_k = ki;
                    }
                }
                if (klusts.at<uchar>(i,j) != min_k){
                    
                    pass = true;
                }
                klusts.at<uchar>(i,j) = min_k;
                kis[min_k] +=1;
            }
        }
        for (int i = 0; i<k;++i){
            
            ks[i] = cv::Vec3f(0,0,0); 
        }
        for (int i = 0; i<mat.rows;++i){
            for (int j = 0; j<mat.cols;++j){
                int klust = klusts.at<uchar>(i,j);
                cv::Vec3b v = mat.at<cv::Vec3b>(i,j);
                ks[klust] += cv::Vec3f((float)v[0],(float)v[1],(float)v[2])/kis[klust];
                
                
            }
        }
       





        pass = false; //ubrat!!
    }
    //std::cout<<mat.cols<<std::endl;
    for (int i = 0; i<mat.rows; ++i){
        for (int j = 0; j<mat.cols;++j){
            cv::Vec3f klustVal = ks[(int)klusts.at<uchar>(i,j)];
            //std::cout<<i<<" "<<j<<std::endl;
            mat.at<cv::Vec3b>(i,j) = cv::Vec3b((uchar)klustVal[0], (uchar)klustVal[1],(uchar)klustVal[2]);

        }
    }




    



}




#endif