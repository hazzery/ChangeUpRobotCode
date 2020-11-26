#include "main.h"
#include "setup.h"
#include "functions.h"

void initialize() {}
void disabled() {}
void competition_initialize() {}

void autonomous()
{
	// testRun();
	autoTune();
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

		delay(20);//Waits 50 milliseconds before rerunning.
	}
}