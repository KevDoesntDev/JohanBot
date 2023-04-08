/*
Register all header files and globals for the bot
*/

#include "main.h"

#include "opcontrol/drivetrain.hpp"
#include "opcontrol/mechanisms.hpp"

#pragma once
// Controller
extern Controller controller;

// Chassis
extern std::shared_ptr<ChassisController> chassis;

// Drivetrain
extern std::shared_ptr<SkidSteerModel> drivetrain;

// Intake
extern Motor intake;

// Catapult
extern Motor catapult;

// Limit switch
extern ADIButton limitSwitch;