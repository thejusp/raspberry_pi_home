#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <raspicam/raspicam_cv.h>
#include <iostream>
#include <ros/ros.h>
//#include <ros/ros.h>
using namespace cv;
using namespace std;
 
int main(int argc, char **argv) {
ros::init(argc, argv, "pi_camera_node");
raspicam::RaspiCam_Cv Camera;
cout<<"Searchin for Pi Camera..."<<endl;
if (!Camera.open()) { //check if video device has been initialised
cout << "cannot open camera";
}
 
//unconditional loop
while (true) {
Mat cameraFrame;
Camera.grab();
Camera.retrieve (cameraFrame);
imshow("cam", cameraFrame);
waitKey(2);
/*if (waitKey(30) >= 0)
break;*/
}
return 0;
}
