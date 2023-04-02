#include <opencv2/opencv.hpp>
#include <iostream>

#define NEIGHBORHOOD_X 9
#define NEIGHBORHOOD_Y 9

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int f, void* userdata);
void meanNeighborhood(Mat* image, int x, int y);
	
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
	meanNeighborhood(image, x, y);	
}

void meanNeighborhood(Mat* image, int x, int y) {
	Mat input_image = *image;
	Mat image_out = input_image.clone();
	if( x + NEIGHBORHOOD_X > image->rows || y + NEIGHBORHOOD_Y > image->cols) return;
	Rect rect(x, y, NEIGHBORHOOD_X, NEIGHBORHOOD_Y);
	Scalar me = mean(image_out(rect));
	cout << me << endl;
	return;

}
