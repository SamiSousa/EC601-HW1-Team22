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


int main()
{

	VideoCapture video = openVideo("video.avi");

	/*Mat frame;
	Mat frame2;
	for(int i = 0;i < 4700; i++)
	{
		video >> frame;
	}
	video >> frame;
	for (int i = 0; i < 30; i++)
		video >> frame2;
	video >> frame2;
	imshow("frame1",frame);
	imshow("frame2",frame2);
	imshow("diff",frame-frame2);
	waitKey(0);*/
	playVideo(video,20);


}
