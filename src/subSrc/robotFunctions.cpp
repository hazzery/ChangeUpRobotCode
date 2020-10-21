#include "main.h"
#include "setup.h"

float leftSpeed() { return controller.getAnalog(ControllerAnalog::leftY) * 12000; }
float rightSpeed() { return controller.getAnalog(ControllerAnalog::rightY) * 12000; }

void runIntake ()
{
	static int intakeMode = 0;

	if (rightUp.changedToPressed())
	{
		if (intakeMode != 1)
		{
			intakeMode = 1;
			Intake.moveVoltage(10000);
		}
		else
		{
			intakeMode = 0;
			Intake.moveVoltage(0);
		}
	}
	else if (rightDown.changedToPressed())
	{
		if (intakeMode != -1)
		{
			intakeMode = -1;
			Intake.moveVoltage(-10000);
		}
		else
		{
			intakeMode = 0;
			Intake.moveVoltage(0);	
		}
	}
}

void runUptake ()
{
	static int uptakeMode = 0;

	if (ABtn.changedToPressed())
	{
		if (uptakeMode != 1)
		{
			uptakeMode = 1;
			Uptake.moveVoltage(10000);
		}
		else
		{
			uptakeMode = 0;
			Uptake.moveVoltage(0);
		}
	}
	else if (BBtn.changedToPressed())
	{
		if (uptakeMode != -1)
		{
			uptakeMode = -1;
			Uptake.moveVoltage(-10000);
		}
		else
		{
			uptakeMode = 0;
			Uptake.moveVoltage(0);	
		}
	}
}