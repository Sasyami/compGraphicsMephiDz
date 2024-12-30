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
#include "move.hpp"
int main(){
    cv::Mat mat = cv::Mat(600,800, CV_8UC3,Scalar(255,255,255));
   
    std::vector<std::vector<double>> up = {{250,250,50}, {300,300,0},{300,350,50},{250,300,100}, };
    std::vector<std::vector<double>> down = {{350,200,100}, {400,250,50}, {400,300,100},{350,250,150}, };
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
        if (i >= 700) break;
        ++i;
    }

    video.release();


    cv::VideoWriter video2("./rotating_and_moving_parallelepiped_perspective2.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(900, 900));
    //VideoWriter video("rotating_parallelepiped_parallel.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(800, 600));
    //cv::Mat psp = perspectiveProjection(0.02);
    i =0;
    double xMove = 0;
    double yMove = 0;
    double zMove = 1;
    while (true) {
        mat = cv::Mat(900,900, CV_8UC3,Scalar(255,255,255));
        rm = createRotationMatrix(angle,rotationAxisX,rotationAxisY,rotationAxisZ);
        cv::Mat mv= move(xMove*cos(angle),yMove*cos(angle),zMove*cos(angle));
        auto up1 = transform(up,rm*resize(1+0.5*sin(angle)));
        auto down1 = transform(down, rm*resize(1 + 0.5*sin(angle)));
        
        f = Figure(Polygon3d(up1), Polygon3d(down1));
        
        drawVisibleFaces(mat,f);
        video2.write(mat); 
        if (i >= 700) break;
        ++i;
        angle += 0.01f;
    }

    video2.release();

    
}
