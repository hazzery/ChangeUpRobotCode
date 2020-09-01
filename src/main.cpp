#include "main.h"
#include "setup.h"

void autonomous() {}

void opcontrol() {
	while (true)
	{
    	drive->tank(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightY), 0.3);//Drives robot using tank control.
		
	    delay(100);//Waits 100ms before rerunning.
	}
}