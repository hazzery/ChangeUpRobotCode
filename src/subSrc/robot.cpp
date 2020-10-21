#include "main.h"
#include "robot.h"
#include "functions.h"
#include "PID.h"
#include "setup.h"

Component::Component(MotorGroup& motors, IntegratedEncoder& encoder)
    : _motors(motors), _sensor(encoder), _pid(PID(30,0,0,10,-12000,12000)), asyncTaskPointer(Component::asyncInstructions), asyncMovement(asyncTaskPointer) {}
Component::Component()
    :_motors(MotorGroup({1, 2})), _sensor(IntegratedEncoder(1)), asyncMovement(asyncTaskPointer) {}
Component::~Component() {}

void Component::move(double distance)
{
    while(notDone()) {

        _pid.setTarget(distance);
        double output = _pid.calculate(_sensor.get());
        _motors.moveVoltage(output);
    
        delay(20);
    }

    _motors.moveVoltage(0);

}

void Component::moveAsync(double distance)
{
    _pid.setTarget(distance);
    asyncMovement.resume();
}

void Component::asyncInstructions()
{
    while(notDone()) {

        double output = _pid.calculate(_sensor.get());
        _motors.moveVoltage(output);
    
        delay(20);
    }

    _motors.moveVoltage(0);
    asyncMovement.suspend();

}

bool Component::notDone()
{ return !_pid.done(); }

double Component::getError()
{ return _pid.calculateError(_sensor.get()); }

Chassis::Chassis(Component& leftDrive, Component& rightDrive) 
    : _leftDrive(leftDrive), _rightDrive(rightDrive) {}

Chassis::~Chassis() {}

void Chassis::straight(double distance)
{
    _leftDrive.moveAsync(distance);
    _rightDrive.moveAsync(distance);

    while(_leftDrive.notDone() && _rightDrive.notDone())
        delay(20);
}
void Chassis::rotate(double angle)
{
    _leftDrive.moveAsync(angle);
    _rightDrive.moveAsync(-angle);
    
    while(_leftDrive.notDone() && _rightDrive.notDone())
        delay(20);
}


Component lDrive (LDrive, LBEncode);
Component rDrive (RDrive, RBEncode);
Component intake (Intake, InEncode);

Chassis drivePID (lDrive, rDrive);