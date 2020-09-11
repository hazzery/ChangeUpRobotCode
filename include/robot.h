#include "main.h"
#include "PID.h"

class Component {

    public:
        Component();
        Component(Motor& motor, IntegratedEncoder& encoder);
        ~Component();

        void move(double distance);

        void waitFor(PID& pid);

    private:
        Motor _motor;
        IntegratedEncoder _sensor;
        PID _pid;
};

class DriveTrain: public Component {

    public:
        DriveTrain(MotorGroup& motor, IntegratedEncoder& encoder);
        ~DriveTrain();

    private:
        MotorGroup _motor;
        IntegratedEncoder _sensor;
        PID _pid;
};

class Chassis {

    public:

        Chassis(DriveTrain& leftDrive, DriveTrain& rightDrive);
        ~Chassis();

        void straight(double distance);
        void rotate(double angle);

    private:
        DriveTrain _leftDrive;
        DriveTrain _rightDrive;
};

extern DriveTrain lDrive;
extern DriveTrain rDrive;
extern Chassis drivePID;