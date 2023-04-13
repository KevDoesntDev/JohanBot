#include "main.h"

int INTAKE_VOLTAGE = 8500;
int CATAPULT_VOLTAGE = 12000;

void MechanismsTask(void *_)
{
    bool intakeStopped = false;
    while (true)
    {
        // Intake
        if (controller.getDigital(ControllerDigital::L2))
        {
            intakeStopped = false;
            intake.moveVoltage(INTAKE_VOLTAGE);
        }
        else if (controller.getDigital(ControllerDigital::L1))
        {
            intakeStopped = false;
            intake.moveVoltage(-INTAKE_VOLTAGE);
        }
        else
        {
            if (!intakeStopped)
            {
                intake.moveVoltage(0);
                intakeStopped = true;
            }
        }

        // Catapult
        if ((controller.getDigital(ControllerDigital::R2) && !limitSwitch.isPressed()) || controller.getDigital(ControllerDigital::A)) {
            catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }

        pros::delay(20);
    }
}