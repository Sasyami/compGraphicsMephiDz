#include "perspective.hpp"
#include "rotation.hpp"
#include "transform.hpp"
#include "back_face_culling.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/videoio.hpp"
int main(){
    cv::Mat mat = cv::Mat(600,800, CV_8UC3,Scalar(255,255,255));
   
    std::vector<std::vector<double>> up = {{150,150,50}, {200,200,0},{200,250,50},{150,200,100}, };
    std::vector<std::vector<double>> down = {{250,100,100}, {300,150,50}, {300,200,100},{250,150,150}, };
    Figure f = Figure(Polygon3d(up), Polygon3d(down));
    //drawFigureOnZ(mat,f,0);
    
    
    
    /*  for (int i =0; i<down.size();++i){
        std::cout<<down[i][0]<<" "<<down[i][1]<<" "<<down[i][2]<<std::endl;
    } */
   
    //drawFigureOnZ(mat,f,0);
    
    //cv::imwrite("test.jpg",mat);

    cv::VideoWriter video("./rotating_parallelepiped_perspective.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(800, 600));
    //VideoWriter video("rotating_parallelepiped_parallel.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(800, 600));
    double angle = 0.01f;
    double rotationAxisX = 1.0f, rotationAxisY = 1.0f, rotationAxisZ = 1.0f;
    cv::Mat rm = createRotationMatrix(angle,rotationAxisX,rotationAxisY,rotationAxisZ);
    int i =0;
    while (true) {
        mat = cv::Mat(600,800, CV_8UC3,Scalar(255,255,255));
        up = transform(up,rm);
        down = transform(down,rm);
        f = Figure(Polygon3d(up), Polygon3d(down));
        drawVisibleFaces(mat,f);
        
        video.write(mat); 
        if (i >= 100) break;
        ++i;
    }

    video.release();


    cv::VideoWriter video2("./rotating_parallelepiped_perspective2.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(500, 300));
    //VideoWriter video("rotating_parallelepiped_parallel.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(800, 600));
    cv::Mat psp = perspectiveProjection(0.02);
    i =0;
    while (true) {
        mat = cv::Mat(300,500, CV_8UC3,Scalar(255,255,255));
        rm = createRotationMatrix(angle,rotationAxisX,rotationAxisY,rotationAxisZ);
        auto up1 = transform(up,rm * psp);
        auto down1 = transform(down,rm*psp);
        
        f = Figure(Polygon3d(up1), Polygon3d(down1));
        
        drawVisibleFaces(mat,f);
        video2.write(mat); 
        if (i >= 100) break;
        ++i;
        angle += 0.01f;
    }

    video2.release();

    
}
