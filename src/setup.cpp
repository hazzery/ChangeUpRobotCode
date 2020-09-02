#include "main.h"

//The Vex V5 robot controller
Controller controller;

//Up button (↑)
ControllerButton upBtn (up);

//Down button (↓)
ControllerButton downBtn (down)

//Left button (←)
ControllerButton leftBtn (left);

//Right button (→)
ControllerButton rightBtn (right);

//Button (A)
ControllerButton ABtn (A);

//Button (B)
ControllerButton BBtn (B);

//Button (X)
ControllerButton XBtn (X);

//Button (Y)
ControllerButton YBtn (Y);

//Top left trigger (L1)
ControllerButton leftUp (L1);

//Bottom left trigger (L2)
ControllerButton leftDown (L2);

//Top right trigger (R1)
ControllerButton rightUp (R1);

//Bottom right trigger (R2)
ControllerButton rightDown (R2);

//Left front motor
Motor LFDrive (-20);

//Left back motor
Motor LBDrive (10);

//Right front motor
Motor RFDrive (11);

//Right back motor
Motor RBDrive (-1);


//Integrated encoder of left front motor
IntegratedEncoder LFEncode (20);

//Integrated encoder of left back motor
IntegratedEncoder LBEncode (10);

//Integrated encoder of right front motor
IntegratedEncoder RFEncode (11);

//Integrated encoder of right back motor
IntegratedEncoder RBEncode (1);


//Left drive train
MotorGroup LDrive({LFDrive, LBDrive});

//Right drive train
MotorGroup RDrive({RFDrive, RBDrive});


//Okapi Chassis Controller
auto chassis = ChassisControllerBuilder()
  .withMotors(LDrive, RDrive)
  .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 17.5_in}, imev5GreenTPR})
  .build();

//The robot's chassis model
auto drive = std::dynamic_pointer_cast<SkidSteerModel>(chassis->getModel());
