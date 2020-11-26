#include "PID.h"
#include "main.h"
#include <iostream>

short sgn(double n)
{
    if (n > 0)
        return 1;
    else if (n = 0)
        return 0;
    else if (n < 0)
        return -1;
}

//PID class constructor, sets member variables
PID::PID(double kp, double ki, double kd, const char* nam = "PID")
    :name(nam), _Kp(kp), _Ki(ki), _Kd(kd), _dt(10), _min(-12000), _max(12000), _maxTime(9999), _maxError(25), _integralLimit(9999), _minDerivative(5) {}

PID::PID()
    :_Kp(1), _Ki(0), _Kd(0), _dt(10), _min(-127), _max(127), _maxTime(9999), _maxError(1),  _integralLimit(9999), _minDerivative(1) {}

PID::~PID() {}

//PID calculator function runs PID logic and returns power output
double PID::calculate(double sensorVal)
{
    // std::cout << name << ": " << "Target is: " << _target << "   Sensor is: " << sensorVal << std::endl;

    _error = _target - sensorVal;//Calculate error.
    
    // std::cout << "Error is: " << _error << std::endl;
    
    //Calculate integral (If conditions are met).
    if(abs(_error) > 750)
        _integral = 0;
    else if (_error == 0)
        _integral = 0;
    else if(abs(_integral) > _integralLimit)
        _integral = _integralLimit * sgn(_integral);
    else
        _integral += (_error * _dt);
    
    _derivative = (_error - _pastError) / _dt;//Calculate derivative.
    
    //Calculate PID values.
    double pOut = _Kp * _error;
    double iOut = _Ki * _integral;
    double dOut = _Kd * _derivative;
    
    double output = pOut + iOut + dOut;//Calculate Output.
    
    //Restrict output to max/min.
    if (output > _max)
        output = _max;
    else if (output < _min)
        output = _min;
    
    // std::cout << name << ": " << "Target is: " << _target << "   Sensor is: " << sensorVal << "   Outputting : " << output << "mV" << std::endl;
    // std::cout << "Outputting : " << output << "mV" << std::endl;
    
    
    //Save previous error.
    _pastError = _error;
    
    return output;
}

bool PID::done() 
{
    if(millis() - _startTime > _maxTime)
    {
        std::cout << name << ": " << " Done for: millis() - _startTime > _maxTime" << std::endl;
        return true;
    }
    // else if(_derivative < _minDerivative)
    // {
    //     std::cout << name << ": " << " Done for: _derivative < _minDerivative" << std::endl;
    //     return true;
    // }    
    if (abs(_error) <= _maxError)
    {
        std::cout << name << ": " << " Done for: abs(_error) <= _maxError" << std::endl;
        return true;
    }

    return false;
}

double PID::calculateError(double sensorVal)
{
    _error = _target - sensorVal;//Calculate error.
    
    return _error;
}

void PID::setTarget(double target)
{
    _target = target;
    // std::cout << name << ": " << " Target Has been set to: " << _target << std::endl;
}

void PID::startTimer()
{
    // std::cout << name << ": " << " Timer has started" << std::endl;
    _startTime = millis();
}