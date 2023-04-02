#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int f, void* userdata);

int main(int argc, char** argv){
	string fileName = "./robocup.jpg"; 
	Mat image = imread(fileName, -1);
	resize(image, image, Size(), 0.5, 0.5);
	string window = "input";
	namedWindow(window, WINDOW_AUTOSIZE);
	imshow(window, image);
	setMouseCallback(window, onMouse, (void*) &image);

	waitKey(0);
	
	return 0;
	
}

void onMouse(int event, int x, int y, int f, void* userdata) {
	if(event != EVENT_LBUTTONDOWN) return;
	
	Mat* image = (Mat*) userdata;
	Vec3b pixelValues = image->at<Vec3b>(x ,y);
	cout << (int)  pixelValues[0]<< " " <<  (int) pixelValues[1] << " " << (int) pixelValues[2] << endl;
		
} 
