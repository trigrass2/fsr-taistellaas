#ifndef _J2B2_CAMERA_HPP_
#define _J2B2_CAMERA_HPP_

#include <iostream>

#include "MachineCtrlClient.hpp"
#include "../J2B2-API.hpp"
#include "../SLAM/SLAMutil.hpp"
#include "../motion/ServoControl.hpp"
#include "Camutil.hpp"

#define dPan Motion::ServoControl::KServoCameraPTUPan
#define dTilt Motion::ServoControl::KServoCameraPTUTilt

#define FOV 50.0

/*
 * Camera and object recognition module
 * Toni Liski / 2012-09-28
*/

namespace cam {

class Location { };

class Camera {

public:

	enum Exception {
		ERR_CAMERA_CLIENT_INITIALIZATION,
		ERR_GET_IMAGE_DATA,
		ERR_GET_IMAGE
	};

	// constructor initialises the Camera module
	// takes CImageClient and ServoPosition as parameter
	Camera(MaCI::MachineCtrl::CMachineCtrlClient *machine, Motion::ServoControl& servos);

	// copy constructor
	Camera(const cam::Camera&);
	Camera operator=(const Camera&);

	// destructor
	~Camera();

	// returns the array of location of the detected objects
	// TODO: let's make a class for locations instead of array
	Location* getDistanceToObjects();

	// updates data from the camera and recognise objects
	void updateCameraData();

	// Calibrate camera
	bool calibrateCamera();


private:

	MaCI::MachineCtrl::CMachineCtrlClient *machineCtrl;
	MaCI::Image::CImageClient *cameraClient;
	MaCI::Image::CImageContainer cameraImage;


//	MaCI::JointGroupCtrl::CJointGroupCtrlClient *iServoCtrl

	// distances
//	MaCI::Ranging::TDistance lastDistance;
//	MaCI::Ranging::TDistanceArray lastLaserDistanceArray;

	bool calibrated;
	bool show_image;

	Motion::ServoControl& servoCtrl;



	void getCameraData();
	void checkCalibration();

	// TODO: add some functions to recognise objects

	void showImage();

	Eigen::Vector2f getCamRotation();
	Eigen::Matrix3f getObjectRotation(const float, const float);
	void getPositionOfTargets();
};

}

#endif
