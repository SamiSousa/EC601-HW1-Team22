/*
 * Sami_harris_contour.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: engineer
 */

//10:43pm

/*
 * contours.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: engineer
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;


/// Global variables
Mat canny_output;
int h_thresh = 200;
int h_max_thresh = 255;

char* source_window = "Source image";
char* corners_window = "Corners detected";

/// Function header
void cornerHarris_demo( int, void* );

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
void thresh_callback(int, void* );
int main( int, char** argv )
{
  src = imread("./res/page_4_dwn.png");
  if (src.empty())
  {
    cerr << "No image supplied ..." << endl;
    return -1;
  }
  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) );
  //const char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );
  //imshow( source_window, src );
  //createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
  thresh_callback( 0, 0 );
  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
   createTrackbar( "Threshold: ", source_window, &h_thresh, h_max_thresh, cornerHarris_demo );
   imshow( source_window, src );

   cornerHarris_demo( 0, 0 );

  waitKey(0);
  return(0);
}
void thresh_callback(int, void* )
{
  //Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  Canny( src_gray, canny_output, thresh, thresh*2, 3 );
  namedWindow( "Canny", WINDOW_AUTOSIZE );
    imshow( "Canny", canny_output );
  findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( size_t i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, (int)i, color, 2, 8, hierarchy, 0, Point() );
     }
  //namedWindow( "Contours", WINDOW_AUTOSIZE );
  //imshow( "Contours", drawing );
}


// @function cornerHarris_demo
void cornerHarris_demo( int, void* )
{

  Mat dst, dst_norm, dst_norm_scaled;
  dst = Mat::zeros( canny_output.size(), CV_32FC1 );

  /// Detector parameters
  int blockSize = 2;
  int apertureSize = 3;
  double k = 0.04;

  /// Detecting corners
  cornerHarris( canny_output, dst, blockSize, apertureSize, k, BORDER_DEFAULT );

  /// Normalizing
  normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
  convertScaleAbs( dst_norm, dst_norm_scaled );

  /// Drawing a circle around corners
  for( int j = 0; j < dst_norm.rows ; j++ )
     { for( int i = 0; i < dst_norm.cols; i++ )
          {
            if( (int) dst_norm.at<float>(j,i) > h_thresh )
              {
               circle( dst_norm_scaled, Point( i, j ), 5,  Scalar(0), 2, 8, 0 );
              }
          }
     }
  /// Showing the result
  namedWindow( corners_window, CV_WINDOW_AUTOSIZE );
  imshow( corners_window, dst_norm_scaled );
}
