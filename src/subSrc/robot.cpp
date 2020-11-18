#include "main.h"
#include "robot.h"
#include "functions.h"
#include "PID.h"
#include "setup.h"

Component::Component(MotorGroup& motors, IntegratedEncoder& encoder, Task* task)
    : _motors(motors), _sensor(encoder), _pid(PID(90,0,0,10)), asyncTask(task) {}
Component::Component()
    :_motors(MotorGroup({1, 2})), _sensor(IntegratedEncoder(1)) {}
Component::~Component() {}


void Component::move(double distance, bool async = false)
{
    _pid.startTimer();
    
    if (!async) 
        _pid.setTarget(distance);
    do
    {
        cout << "sending power to motor" << endl;

        double output = _pid.calculate(_sensor.get());
        _motors.moveVoltage(output);
        
        delay(20);
    }
    while(notDone());
    
    _motors.moveVoltage(0);
}

void Component::moveAsync(double distance)
{
    _pid.setTarget(distance);
    asyncTask->resume();

    if(asyncTask->get_state() == 0)
        cout << "Starting async Task" << endl;
    else
        cout << "Task Status: " << asyncTask->get_state() << endl;
    
}

void Component::asyncInstructions()
{
    cout << "It's async, innit" << endl;
    move(_pid._target, 1);
    
    asyncTask->suspend();
}

bool Component::notDone()
{ return !_pid.done(); }

double Component::getError()
{ return _pid.calculateError(_sensor.get()); }

Chassis::Chassis(Component& leftDrive, Component& rightDrive) 
    : _leftDrive(leftDrive), _rightDrive(rightDrive), _pid() {}

Chassis::~Chassis() {}

void Chassis::straight(double distance)
{
    _leftDrive.moveAsync(distance);
    _rightDrive.moveAsync(distance);

    cout << "Drive straight set" << endl;
    
    while(_leftDrive.notDone() && _rightDrive.notDone())
    {
        cout << "waiting for PID" << endl;
        delay(20);
    }
}
void Chassis::rotate(double angle)
{
    _leftDrive.moveAsync(angle);
    _rightDrive.moveAsync(-angle);
    
    while(_leftDrive.notDone() && _rightDrive.notDone())
        delay(20);
}

void leftDriveFunction();
void rightDriveFunction();
void intakeFunction();

Task leftDriveTask (&leftDriveFunction);
Task rightDriveTask (&leftDriveFunction);
Task intakeTask (&leftDriveFunction);

Component lDrive (LDrive, LBEncode, &leftDriveTask);
Component rDrive (RDrive, RBEncode, &rightDriveTask);
Component intake (Intake, InEncode, &intakeTask);

Chassis drivePID (lDrive, rDrive);

void leftDriveFunction()
{
    lDrive.asyncInstructions();
}
void rightDriveFunction()
{
    rDrive.asyncInstructions();
}
void intakeFunction()
{
    intake.asyncInstructions();
}