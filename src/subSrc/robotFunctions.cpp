#include "main.h"
#include "setup.h"

//Tests functionality of all drive motors by allowing the individual running of each motor
void driveMotorTest() {
	//Run left front drive motor using up + down buttons
	if(upBtn.isPressed())
		LFDrive.moveVoltage(12000);
	else if(downBtn.isPressed())
		LFDrive.moveVoltage(-12000);

	//Run left back drive motor using left + right buttons
	if(leftBtn.isPressed())
		LBDrive.moveVoltage(12000);
	else if(rightBtn.isPressed())
		LBDrive.moveVoltage(-12000);

	//Run right front drive motor using X + B buttons
	if(XBtn.isPressed())
		RFDrive.moveVoltage(12000);
	else if(BBtn.isPressed())
		RFDrive.moveVoltage(-12000);

	//Run Right Back drive motor using Y + A buttons
	if(YBtn.isPressed())
		RBDrive.moveVoltage(12000);
	else if(ABtn.isPressed())
		RBDrive.moveVoltage(-12000);
}