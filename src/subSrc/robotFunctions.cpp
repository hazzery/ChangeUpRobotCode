#include "main.h"
#include "setup.h"

//Tests functionality of all drive motors by allowing the individual running of each motor
void driveMotorTest() {
	//Run left front drive motor using up + down buttons
	if(controller.getDigital(ControllerDigital::up)) LFDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::down)) LFDrive.moveVoltage(-12000);

	//Run left back drive motor using left + right buttons
	if(controller.getDigital(ControllerDigital::left)) LBDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::right)) LBDrive.moveVoltage(-12000);

	//Run right front drive motor using X + B buttons
	if(controller.getDigital(ControllerDigital::X)) RFDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::B)) RFDrive.moveVoltage(-12000);

	//Run Right Back drive motor using Y + A buttons
	if(controller.getDigital(ControllerDigital::Y)) RBDrive.moveVoltage(12000);
	else if(controller.getDigital(ControllerDigital::A)) RBDrive.moveVoltage(-12000);
}