/*

Map Data Object

Antti 26.9.

*/

#ifndef _J2B2_MAPDATA_HPP_
#define _J2B2_MAPDATA_HPP_

#include "utilities.hpp"

class MapData {

public:

// type of observation
enum ObservationType {
        WALL=0,
        TARGET=1,
        OBSTACLE=2,
        GOAL=3,
        OBS_TYPE_SIZE=4  // the size of this enumeration
};

// constructor
MapData(int xdim, int ydim, 
        double xsize, double ysize,
        RobotLocation initial);

// destructor
~MapData();

// used to set the value of one cell of the map to another
void setCellValue(GridPoint xy, ObservationType type, double value);

// used to get the value of one cell of the map
double getCellValue(GridPoint xy, ObservationType type);

// used to set the value at some location of the map to another (from nearest cell)
void setValue(Location xy, ObservationType type, double value);

// used to get the value at some location of the map (goes to nearest cell)
double getValue(Location xy, ObservationType type);

// used to set the location of the robot
void setLocation(RobotLocation xyt);

// used to get the robot location
RobotLocation getLocation();


private:

int xdim, ydim;			// dimension of the map (cells)
double xsize, ysize;		// actual size of the map (meters)
double cellxsize, cellysize;	// size of one cell (meters)

RobotLocation robotLocation;	// robot location in the map

double map [100][100][OBS_TYPE_SIZE];  // map data

};

#endif
