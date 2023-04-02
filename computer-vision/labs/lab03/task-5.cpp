#include <opencv2/opencv.hpp>
#include <iostream>

#define NEIGHBORHOOD_X 9
#define NEIGHBORHOOD_Y 9

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int f, void* userdata);
void showImage(Mat image, string window);
Vec3b meanNeighborhood(Mat* image, int x, int y);
Mat replaceColor(Mat* image, Vec3b me, int threshold, Vec3b subColor);

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
	Vec3b subColor(92, 37, 201);
	Mat subImage = replaceColor(image, me, threshold, subColor);
	showImage(subImage, "Sub Image");
}

Vec3b meanNeighborhood(Mat* image, int x, int y) {
	Mat input_image = *image;
	Mat image_out = input_image.clone();
	Rect rect(x, y, NEIGHBORHOOD_X, NEIGHBORHOOD_Y);
	Scalar average = mean(image_out(rect));
	Vec3b me(average[0], average[1], average[2]);
	return me;
}

Mat replaceColor(Mat* input_image, Vec3b me, int threshold, Vec3b subColor) {
	Mat image = *input_image;
	Mat newImage = image.clone();
	int maskColor {};
	double dist {};
	for(int i {0}; i < image.rows; i++){
		for(int j {0}; j < image.cols; j++){
			dist = norm(me, image.at<Vec3b>(i, j), NORM_L2);
			maskColor = threshold > dist ? 255 : 0;
			newImage.at<Vec3b>(i, j) = !maskColor ? image.at<Vec3b>(i, j) : subColor;
		}
	}
	
	return newImage;
}
