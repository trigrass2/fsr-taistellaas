#include <iostream>
#include <algorithm>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv)
{
        Mat src, dst;

	src = imread ( argv[1], 1 );
	cvtColor(src, dst, CV_BGR2HSV);

	// tresholding
	inRange(dst, Scalar(0, 160, 160), Scalar(10, 255, 255), dst);

	// dilation
	int dilation_size = 2;
	Mat element = getStructuringElement( MORPH_RECT,
                                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                       Point( dilation_size, dilation_size ) );
	dilate( dst, dst, element );

	// contours
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(dst, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

	for(int idx = 0; idx >= 0; idx = hierarchy[idx][0] )
	{
//		double area = contourArea(contours[idx]);
		Scalar color( rand()&255, rand()&255, rand()&255 );
//		if (area < 100) continue;
//		if (area > 1000) color = Scalar(0,0,255);

		Point2f center;
		float radius;
		minEnclosingCircle(contours[idx], center, radius);

		if (radius < 15) continue;
		std::cout << idx << ": " << center << " " << radius << std::endl;

//		drawContours( src, contours, idx, color, CV_FILLED, 8, hierarchy );
		circle( src, center, (int)radius * 1.2, color, 2);
	}

	imshow( "origin", src);
//        imshow( "padam", dst);
	waitKey(0);

}
