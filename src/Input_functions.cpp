/**
This file will contain a function to load a video in OpenCV
*/

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <math.h>
#include <string>

using namespace cv;
using namespace std;

VideoCapture openVideo(string filename);

void playVideo(VideoCapture video);


VideoCapture openVideo(string filename)
{
	VideoCapture capture(filename);
	if (!capture.isOpened())
	{
		throw "Error - could not open the video";
	}

	return capture;
}

void playVideo(VideoCapture video)
{
	Mat frame;
	for(;;)
	{
		video >> frame;
		if (frame.empty())
		{
			break;
		}
		imshow("video",frame);
		waitKey(20);
	}
}


int main()
{

	VideoCapture video = openVideo("video.avi");

	playVideo(video);


}
