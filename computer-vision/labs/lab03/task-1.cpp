#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showImage(Mat image, string name);


int main(int argc, char** argv){
	string fileName = "./robocup.jpg";
	Mat input = imread(fileName, -1);
	
	showImage(input, "Input");
	
	waitKey(0);
	
	return 0;
	
}


void showImage(Mat image, string name){
	namedWindow(name, WINDOW_AUTOSIZE);
	imshow(name, image);
}
