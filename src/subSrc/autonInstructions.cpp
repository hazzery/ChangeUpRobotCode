#include "main.h"
#include "robot.h"

void testRun()
{
    double moveTarget = 300;
    drivePID.straight(moveTarget);
    drivePID.rotate(200);

	drivePID.straight(moveTarget);
	cout << "done" << endl;

	// std::cout << "Left Error: " << lDrive.getError(moveTarget) << "   Right Error: " << rDrive.getError(moveTarget)<< std::endl;
}

void red()
{

}

void blue()
{

}