#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <math.h>
#include <string>
#include "readVideoFunctions.hpp"

using namespace cv;
using namespace std;


/*
 * This function takes as input a string containing the video filename to open and opens it
 * If the video cannot be open an exception is thrown
 * The function returns an object that contains the video
 */
VideoCapture openVideo(string filename)
{
	VideoCapture capture(filename);
	if (!capture.isOpened())
	{
		throw "Error - could not open the video";
	}

	return capture;
}


/*
 * This function takes as input a video object and plays it. That is it creates a window and displays all the frames of the video one after the
 * other. Frame_period is the time that passes from one frame to the other and therefore it can be used to reproduce the video in a faster way.
 */
void playVideo(VideoCapture video, int frame_period)
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
		waitKey(frame_period);
	}
}
