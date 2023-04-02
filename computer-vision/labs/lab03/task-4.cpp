#include <opencv2/opencv.hpp>
#include <iostream>

#define NEIGHBORHOOD_X 9
#define NEIGHBORHOOD_Y 9

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int f, void* userdata);
Vec3b meanNeighborhood(Mat* image, int x, int y);
Mat segmentImage(Mat* image, Vec3b me, double threshold);
void showImage(Mat image, string window); 

int main(int argc, char** argv){
	string fileName = "./robocup.jpg"; 
	Mat image = imread(fileName, -1);
	resize(image, image, Size(), .3, .3);
	string window = "input";
	showImage(image, window);
	setMouseCallback(window, onMouse, (void*) &image);
	waitKey(0);
	return 0;
}

void showImage(Mat image, string window) {
	namedWindow(window, WINDOW_AUTOSIZE);
	imshow(window, image);
}

void onMouse(int event, int x, int y, int f, void* userdata) {
	if(event != EVENT_LBUTTONDOWN) return;
	Mat* image = (Mat*) userdata;
	Vec3b me = meanNeighborhood(image, x, y);
	int threshold = 30;
	Mat maskedImage = segmentImage(image, me, threshold);	
	showImage(maskedImage, "masked");
}

Vec3b meanNeighborhood(Mat* image, int x, int y) {
	Mat input_image = *image;
	Mat image_out = input_image.clone();
	Rect rect(x, y, NEIGHBORHOOD_X, NEIGHBORHOOD_Y);
	Scalar average = mean(image_out(rect));
	Vec3b me(average[0], average[1], average[2]);
	return me;
}

Mat segmentImage(Mat* image, Vec3b me, double threshold) {
	Mat input_image = *image;
	Mat mask(input_image.size(), CV_8UC1);
	for(int i = 0; i < input_image.rows; i++) {
		for(int j = 0; j < input_image.cols; j++) {
			double dist = norm(me, input_image.at<Vec3b>(i, j), NORM_L2);
			mask.at<uchar>(i, j) = threshold > dist ? 255 : 0;
		}
	}
	return mask;
}
