/**
@file warpPerspective_demo.cpp
@brief a demo program shows how perspective transformation applied on an image
@based on a sample code http://study.marearts.com/2015/03/image-warping-using-opencv.html
@modified by Suleyman TURKMEN
*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include <string>
#include <unistd.h>
#include "readVideoFunctions.hpp"

using namespace std;
using namespace cv;


static void help(char** argv)
{
    // print a welcome message, and the OpenCV version
    cout << "\nThis is a demo program that cuts a square section from a video and applies to it a perspective transformation,  \n"
         "using OpenCV version " << CV_VERSION << endl;

    cout << "\nUsage:\n" << argv[0] << " [video_name]\n" << endl;

}

Mat warping(Mat image, Size warped_image_size, vector< Point2f> srcPoints, vector< Point2f> dstPoints);

String windowTitle = "Perspective Transformation Demo";
String labels[4] = { "TL","TR","BR","BL" };
vector< Point2f> roi_corners;
vector< Point2f> dst_corners(4);
int roiIndex = 0,i=0;
bool dragging;
int selected_corner_index = 0;
bool validation_needed = true;

int main(int argc, char** argv)
{
    help(argv);
    CommandLineParser parser(argc, argv, "{@input}");

    string filename = parser.get<string>("@input");

    VideoCapture video = openVideo(filename);
    Mat image;


    Mat f;
    video >> f;

    // calculate the transformation
    float original_image_cols = (float)f.cols;
	float original_image_rows = (float)f.rows;
	// square coordinates
	roi_corners.push_back(Point2f( (float)(original_image_cols / 1.95), (float)(original_image_rows / 4.20) ));
	roi_corners.push_back(Point2f( (float)(f.cols / 1.15), (float)(f.rows / 3.32) ));
	roi_corners.push_back(Point2f( (float)(f.cols / 1.33), (float)(f.rows / 1.10) ));
	roi_corners.push_back(Point2f( (float)(f.cols / 1.93), (float)(f.rows / 1.36) ));

	dst_corners[0].x = 0;
	dst_corners[0].y = 0;

	dst_corners[1].x = (float)std::max(norm(roi_corners[0] - roi_corners[1]), norm(roi_corners[2] - roi_corners[3]));
	dst_corners[1].y = 0;

	dst_corners[2].x = (float)std::max(norm(roi_corners[0] - roi_corners[1]), norm(roi_corners[2] - roi_corners[3]));
	dst_corners[2].y = (float)std::max(norm(roi_corners[1] - roi_corners[2]), norm(roi_corners[3] - roi_corners[0]));

	dst_corners[3].x = 0;
	dst_corners[3].y = (float)std::max(norm(roi_corners[1] - roi_corners[2]), norm(roi_corners[3] - roi_corners[0]));

	Size warped_image_size = Size(cvRound(dst_corners[2].x), cvRound(dst_corners[2].y));

	Mat H = findHomography(roi_corners, dst_corners); //get homography


	namedWindow(windowTitle, WINDOW_NORMAL);
	namedWindow("Warped Image", WINDOW_AUTOSIZE);
	moveWindow("Warped Image", 20, 20);
	moveWindow(windowTitle, 330, 20);

	for(;;){//add a loop here so the program will deal with the frames one by one

		Mat original_image;
		// get the next frame
		video >> original_image;
		if (original_image.empty())
		{
			break;
		}




		image = original_image.clone();
		// draw the cut section on the image
		for ( int i = 0; i < 4; ++i )
		{
			line(image, roi_corners[i], roi_corners[(i + 1) % 4], Scalar(0, 0, 255), 2);
			circle(image, roi_corners[i], 5, Scalar(0, 255, 0), 3);
			putText(image, labels[i].c_str(), roi_corners[i], QT_FONT_NORMAL, 0.8, Scalar(255, 0, 0), 2);
		}

		imshow( windowTitle, image );

		// apply the perspective transformation
		Mat warped_image;
		warpPerspective(original_image, warped_image, H, warped_image_size);
		imshow("Warped Image", warped_image);

		waitKey( 20 );


	}/////////
    return 0;
}
