#include "main.h"
#include "setup.h"
#include "robot.h"
#include "functions.h"

void initialize() {}
void disabled() {}
void competition_initialize() {}

void autonomous()
{
	testRun();
}

void opcontrol()
{
	while (true)
	{
		//Drives robot using tank control.
		LDrive.moveVoltage(leftSpeed());
		RDrive.moveVoltage(rightSpeed());

		runUptake();
		runIntake();

		delay(50);//Waits 50 milliseconds before rerunning.
	}
}