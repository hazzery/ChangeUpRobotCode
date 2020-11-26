#include "main.h"
#include "setup.h"
#include "functions.h"
#include "autonFunctions.hpp"

void testRun()
{
    double moveTarget = 400;

    straight(moveTarget);

    delay(2000);

    rotate(90);

}

// void tuneP(PID pid)
// {
//     bool direction;

//     int moveDistance;

//     int value;

//     while(true)
//     {
//         straight(moveDistance);

//         direction = (moveDistance > 0)? true: false;

//         value = (pid._maxError * (direction? 1:-1));

//         if(leftPID.calculateError(LBEncode.get()) > value)
//             leftPID._Kp += 2;
//         else if(leftPID.calculateError(LBEncode.get()) < -value)
//             leftPID._Kp -= 2;
//         else
//         {
//             if(pid._maxError > 5)
//                 pid._maxError -= 5;
//             else
//                 break;
//         }

//         delay(50);
//     }
// }

void autoTune()
{
    bool direction;

    int moveDistance = 750;

    int value;

    while(true)
    {
        leftPID._error = 26;
        rightPID._error = 26;

        straight(moveDistance);

        direction = (moveDistance > 0)? true: false;

        value = (leftPID._maxError * direction? 1:-1);

        if(leftPID._error > value)
            leftPID._Kp += (leftPID._error * 0.1);
        else if(leftPID._error < -value)
            leftPID._Kp -= (leftPID._error * 0.1);
        else
        {
            if(leftPID._maxError > 5)
                rightPID._maxError -= 5;
        }
        
        value = (rightPID._maxError * direction? 1:-1);

        if (rightPID._error > value)
            rightPID._Kp += (rightPID._error * 0.5);
        else if (rightPID._error < value)
            rightPID._Kp -= (rightPID._error * 0.5);
        else
        {
            if(rightPID._maxError > 5)
                rightPID._maxError -= 5;
        }

        if (leftPID._maxError == 5 && rightPID._maxError == 5)
            break;

        moveDistance = -moveDistance;

        std::cout << "Left:  kP value: " << leftPID._Kp << "  Error: " << leftPID._error << std::endl;
        std::cout << "Right:  kP value: " << rightPID._Kp << "  Error: " << rightPID._error << std::endl;

        delay(500);
    }

}

void red()
{

}

void blue()
{

}