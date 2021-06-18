#include "main.h"
#include "PID.h"

class Component {

    public:
        Component();
        Component(MotorGroup& motors, IntegratedEncoder& encoder, Task* task);
        ~Component();

        void move(double distance, bool async);
        void moveAsync(double distance);

        void asyncInstructions();

        Task* asyncTask;

        void waitFor(PID& pid);

        bool notDone();

        double getError();

    private:
        PID _pid;
        IntegratedEncoder _sensor;
        MotorGroup _motors;
};

class Chassis {

    public:

        Chassis(Component& leftDrive, Component& rightDrive);
        ~Chassis();

        void straight(double distance);
        void rotate(double angle);

    private:
        PID _pid;
        Component _leftDrive;
        Component _rightDrive;
};

extern Component lDrive;
extern Component rDrive;
extern Chassis drivePID;