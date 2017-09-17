#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/*
 * This function takes as input a string containing the video filename to open and opens it
 * If the video cannot be open an exception is thrown
 * The function returns an object that contains the video
 */
VideoCapture openVideo(string filename);


/*
 * This function takes as input a video object and plays it. That is it creates a window and displays all the frames of the video one after the
 * other. Frame_period is the time that passes from one frame to the other and therefore it can be used to reproduce the video in a faster way.
 */
void playVideo(VideoCapture video, int frame_period);
