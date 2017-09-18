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

	playVideo(video,20);


}
