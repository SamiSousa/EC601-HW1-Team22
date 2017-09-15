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

VideoCapture openVideo(string filename)
{
	VideoCapture capture(filename);
	if (!capture.isOpened())
	{
		throw "Error - could not open the video";
	}

	return capture;
}




int main()
{

	VideoCapture video = openVideo("video.avi");

	Mat frame,frame1;
	for(;;)
	{
		video >> frame;
		if (frame.empty())
		{
			break;
		}
		frame1 = frame(Range(0,100),Range(50,200)); //cut
		imshow("video",frame1);
		waitKey(20);
	}

}
