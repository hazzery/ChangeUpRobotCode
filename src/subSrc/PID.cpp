#include "PID.h"

double abs(float n)
{
    if (n >= 0)
        return n;
    else if (n < 0)
        return -n;
}

//PID class constructor, sets member variables
PID::PID(double kp, double ki, double kd, double dt, double min, double max )
    :_Kp(kp), _Ki(ki), _Kd(kd), _dt(dt), _min(min), _max(max), _pastError(0), _integral(0) {}

PID::PID() {}

//PID calculator function runs PID logic and returns power output
double PID::calculate( double target, double sensorVal )
{
    double error = target - sensorVal;//Calculate error.

    //Calculate integral (If conditions are met).
    if(abs(error) > 750)
        _integral = 0;
    else if (error = 0)
        _integral = 0;
    else if(_integral > _integralLimit)
        0;
    else
        _integral += (error * _dt);

    double derivative = (error - _pastError) / _dt;//Calculate derivative.

    //Calculate PID values.
    double pOut = _Kp * error;
    double iOut = _Ki * _integral;
    double dOut = _Kd * derivative;

    double output = pOut + iOut + dOut;//Calculate Output.

    //Restrict output to max/min.
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;

    //Save error to previous error.
    _pastError = error;

    return output;
}

bool PID::done() 
{
    //Unfinished
}

bool PID::notDone() 
{ return !done(); }

PID::~PID() {}