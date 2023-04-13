#include "main.h"

void DrivetrainTask(void *_)
{
    while (true)
    {
        drivetrain->arcade(controller.getAnalog(ControllerAnalog::rightX), controller.getAnalog(ControllerAnalog::leftY));

        pros::delay(20);
    }
}