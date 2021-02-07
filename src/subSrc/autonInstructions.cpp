#include "main.h"
#include "robot.h"
#include "setup.h"
#include "PID.h"

float p = 10;//Finished at 10 - using 5
float i = 0.03;
float d = 0;
PID leftPID (p, i, d, "Left");
PID rightPID (p, i, d, "Right");

void moveStraight(int target)
{
    
    leftPID.setTarget(target);
    rightPID.setTarget(target);
    
    while(!leftPID.done() && !rightPID.done())
    {
        int leftOut = leftPID.calculate(LBEncode.get());
        LDrive.moveVoltage(leftOut);
        int rightOut = rightPID.calculate(RBEncode.get());
        RDrive.moveVoltage(rightOut);

        // cout << "Left Error: " << leftPID.calculateError(LBEncode.get()) << " Right Error: " << rightPID.calculateError(LBEncode.get()) << endl;

        delay(20);
    }

    LDrive.moveVoltage(0);
    RDrive.moveVoltage(0);

    leftPID.resetPID();
    rightPID.resetPID();

}

void testRun()
{
    for(int i = 0; i < 5; i++)
    {
        moveStraight(1500);
        delay(500);
        moveStraight(0);
    }
}

void red()
{
}

void blue()
{

}