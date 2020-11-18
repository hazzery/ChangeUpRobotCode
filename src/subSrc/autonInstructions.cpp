#include "main.h"
#include "robot.h"

void testRun()
{
    double moveTarget = 900;
    // drivePID.straight(moveTarget);
    rDrive.moveAsync(moveTarget);
    // lDrive.moveAsync(moveTarget);
    // drivePID.rotate(moveTarget);


	// drivePID.straight(moveTarget);
	// cout << "The program should end now" << endl << endl;

	// std::cout << "Left Error: " << lDrive.getError(moveTarget) << "   Right Error: " << rDrive.getError(moveTarget)<< std::endl;
}

void red()
{

}

void blue()
{

}