#pragma once
#include "main.h"

extern Controller controller;

extern Motor LFDrive;
extern Motor LBDrive;
extern Motor RFDrive;
extern Motor RBDrive;

extern IntegratedEncoder LFEncode;
extern IntegratedEncoder LBEncode;
extern IntegratedEncoder RFEncode;
extern IntegratedEncoder RBEncode;

extern MotorGroup LDrive;
extern MotorGroup RDrive;

extern std::shared_ptr<okapi::ChassisController> chassis;
extern std::shared_ptr<okapi::SkidSteerModel> drive;
