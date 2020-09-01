#include "main.h"
#include "setup.h"

using pros::delay;

void initialize() {}
void disabled() {}
void competition_initialize() {}
void autonomous() {}

//Tests functionality of all drive motors by allowing the individual running of each motor
void motorTest() {
	if(controller.getDigital(ControllerDigital::up)) LFDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::down)) LFDrive.moveVoltage(-12000);

	if(controller.getDigital(ControllerDigital::left)) LBDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::right)) LBDrive.moveVoltage(-12000);

	if(controller.getDigital(ControllerDigital::X)) RFDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::B)) RFDrive.moveVoltage(-12000);

	if(controller.getDigital(ControllerDigital::Y)) RBDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::A)) RBDrive.moveVoltage(-12000);
}

void opcontrol() {
	while (true)
	{
    	drive->tank(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightY), 0.3);//Drives robot using tank control.
		
	    delay(100);//Waits 100ms before rerunning.
	}
}
