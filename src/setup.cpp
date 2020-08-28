#include "main.h"

Controller controller;

Motor LFDrive (-20);
Motor LBDrive (10);
Motor RFDrive (11);
Motor RBDrive (-1);

IntegratedEncoder LFEncode (20);
IntegratedEncoder LBEncode (10);
IntegratedEncoder RFEncode (11);
IntegratedEncoder RBEncode (1);

MotorGroup LDrive({LFDrive, LBDrive});
MotorGroup RDrive({RFDrive, RBDrive});

auto chassis = ChassisControllerBuilder()
  .withMotors(LDrive, RDrive)
  .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 17.5_in}, imev5GreenTPR})
  .build();

auto drive = std::dynamic_pointer_cast<SkidSteerModel>(chassis->getModel());
