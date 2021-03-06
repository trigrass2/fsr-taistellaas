#ifndef _J2B2_CAMUTIL_HPP_
#define _J2B2_CAMUTIL_HPP_

#include "MachineCtrlClient.hpp"
#include "../J2B2-API.hpp"
#include "../SLAM/SLAM.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <Eigen/Dense>

/*
 * Camera Utility class
 * Toni Liski / 2012-10-17
*/

namespace cam {

class Camutil {

public:

	// constructor
	Camutil();

	static cv::Mat imgToMat (MaCI::Image::CImageContainer);
	static bool BallsInView (cv::Mat);
	static std::vector<SLAM::Location> FindBalls (cv::Mat, cv::Mat& drawing);
	static std::vector<SLAM::Location> FindBalls (cv::Mat, cv::Mat& drawing, bool targets);
	static std::vector<SLAM::Location> FindGoalArea (cv::Mat src, cv::Mat& drawing);

private:

};
}
#endif
