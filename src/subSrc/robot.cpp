#include "main.h"
#include "robot.h"
#include "functions.h"
#include "PID.h"
#include "setup.h"


Component::Component(Motor& motor, IntegratedEncoder& encoder) 
    : _motor(motor), _sensor(encoder), _pid(PID(1.0, 0.0, 0.0, 1.0, 1.0, 1.0)) {}
Component::Component()
    :_motor(Motor(1)), _sensor(IntegratedEncoder(1)) {}

Component::~Component() {}

void Component::move(double distance)
{
    while(_pid.notDone()) {

        double output = _pid.calculate(distance, _sensor.get());
        _motor.moveVoltage(output);
    
        delay(20);
    }

}
DriveTrain::DriveTrain(MotorGroup& motor, IntegratedEncoder& encoder) 
    : _motor(motor), _sensor(encoder), _pid(PID(1.0, 0.0, 0.0, 1.0, 1.0, 1.0)) {}

DriveTrain::~DriveTrain() {}




Chassis::Chassis(DriveTrain& leftDrive, DriveTrain& rightDrive) 
    : _leftDrive(leftDrive), _rightDrive(rightDrive) {}

Chassis::~Chassis() {}

void Chassis::straight(double distance)
{
    while(false)//Should be while(notDone)
    {
        _leftDrive.move(distance);
        _rightDrive.move(distance);

        delay(20);
    }

}
void Chassis::rotate(double angle)
{
    while(false)//Should be while(notDone)
    {
        _leftDrive.move(angle);
        _rightDrive.move(-angle);

        delay(20);
    }
}


DriveTrain lDrive (LDrive, LBEncode);
DriveTrain rDrive (RDrive, RBEncode);

Chassis drivePID (lDrive, rDrive);