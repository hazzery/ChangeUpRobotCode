#pragma once

class PID {

    public:

        //Kp -  Proportional gain.
        //Ki -  Integral gain.
        //Kd -  Derivative gain.
        //dt -  loop interval time.
        //min - minimum output value. 
        //max - maximum output value.
        PID (double kp, double ki, double kd, double dt, double min, double max);
        PID ();
        ~PID();

        //Returns power output for specified motor, given a target sensor value and current sensor value value
        double calculate(double sensorVal);
        
        //Returns true if target has successfully reached its target.
        bool done();

        //Returns PID error, given a target sensor value and current sensor value value
        double calculateError(double sensorVal);

        double setTarget(double target);
    
    private:
        const double _Kp;
        const double _Ki;
        const double _Kd;
        const double _dt;
        const double _min;
        const double _max;
        const double _maxError;
        const double _integralLimit;
        double _target;
        double _error;
        double _pastError;
        double _integral;
};