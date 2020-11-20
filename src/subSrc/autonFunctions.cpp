#include "main.h"
#include "setup.h"
#include "PID.h"

PID leftPID(17.5, 0, 0, "Left");
PID rightPID(17.5, 0, 0, "Right");
PID straightPID(50, 0, 0, "Straight");
PID rotatePID(5, 0, 0, "Rotate");


void straight(double distance)
{

    leftPID.setTarget(distance);
    rightPID.setTarget(distance);
    straightPID.setTarget(0);

    while(!leftPID.done() && !rightPID.done())
    {
        // double straighten = 0;
        double straighten = straightPID.calculate(LBEncode.get() - RBEncode.get());
        double leftOut = straighten;
        double rightOut = -straighten;
        // double leftOut = leftPID.calculate(LBEncode.get()) - straighten;
        // double rightOut = rightPID.calculate(RBEncode.get()) + straighten;

        LDrive.moveVoltage(leftOut);
        RDrive.moveVoltage(rightOut);
    }

}