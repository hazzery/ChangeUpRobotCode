#include "main.h"
#include "setup.h"
#include "PID.h"

PID leftPID(17.5, 0, 0, "Left");
PID rightPID(17.5, 0, 0, "Right");
PID straightPID(50, 0, 0, "Straight");


void straight(double distance)
{

    leftPID.setTarget(distance);
    leftPID.startTimer();
    rightPID.setTarget(distance);
    rightPID.startTimer();
    straightPID.setTarget(0);

    while(!(leftPID.done() && rightPID.done() && straightPID.done()))
    {
        // std::cout << "yoza" << std::endl;
        // double straighten = 0;
        double straighten = straightPID.calculate(LBEncode.get() - RBEncode.get());
        // double leftOut = straighten;
        // double rightOut = -straighten;
        double leftOut = leftPID.calculate(LBEncode.get()) + straighten;
        double rightOut = rightPID.calculate(RBEncode.get()) - straighten;

        LDrive.moveVoltage(leftOut);
        RDrive.moveVoltage(rightOut);

        delay(15);
    }

    LDrive.moveVoltage(0);
    RDrive.moveVoltage(0);

}

void rotate(double angle)
{
    leftPID.setTarget(angle);
    rightPID.setTarget(-angle);

    while(!leftPID.done() && !rightPID.done())
    {
        double leftOut = leftPID.calculate(LBEncode.get());
        double rightOut = rightPID.calculate(RBEncode.get());

        LDrive.moveVoltage(leftOut);
        RDrive.moveVoltage(rightOut);
    }

}