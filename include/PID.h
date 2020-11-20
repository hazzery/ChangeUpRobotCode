#pragma once

class PID {
    
    public:
        //Kp -  Proportional gain.
        //Ki -  Integral gain.
        //Kd -  Derivative gain.
        PID (double kp, double ki, double kd, const char* name);
        PID ();
        ~PID();
        
        //Returns power output for specified motor, given current sensor value.
        double calculate(double sensorVal);
        
        //Returns true if robot has successfully reached its target.
        bool done();
        
        //Returns PID error, given current sensor value value.
        double calculateError(double sensorVal);
        
        //Sets the robot's target distance. 
        void setTarget(double target);
        
        //Sets the PID's start time.
        void startTimer();
        
        double _target;

    public:
        const char* name;
    
    private:
        const double _Kp;
        const double _Ki;
        const double _Kd;
        const double _dt;
        const double _min;
        const double _max;
        const double _maxTime;
        const double _maxError;
        const double _integralLimit;
        const double _minDerivative;
        double _error = 11;
        double _pastError;
        double _integral;
        double _derivative = 11;
        double _startTime;
};