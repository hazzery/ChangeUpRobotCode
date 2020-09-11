#pragma once

class PID {

    public:

        //Kp -  Proportional gain.
        //Ki -  Integral gain.
        //Kd -  Derivative gain.
        //dt -  loop interval time.
        //max - Maximum output value. 
        //min - Minimum output value.
        PID (double kp, double ki, double kd, double dt, double max, double min);
        PID ();
        ~PID();

        //Returns power output for specified motor, given a target sensor value and current sensor value value
        double calculate(double target, double sensor);

        //Returns true if PID is still in process.
        bool notDone();
        
        //Returns true if target has successfully reached its target.
        bool done();

    
    private:
        double _Kp;
        double _Ki;
        double _Kd;
        double _dt;
        double _min;
        double _max;
        double _pastError;
        double _integral;
        double _integralLimit;
};