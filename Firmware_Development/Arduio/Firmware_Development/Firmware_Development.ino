#include "AcServo.hpp"
#include "RoboticArmParameters.h"

AcServoMotor elbowJoint(CW_PWM_PIN,
                        CCW_PWM_PIN, 
                        CW_PUSH_BUTTON,
                        CCW_PUSH_BUTTON,
                        PWM_FREQUENCY,
                        PWM_DUTY_CYCLE
);

void setup() 
{
}

void loop() 
{
  // put your main code here, to run repeatedly:
  elbowJoint.shaftRotation();

}
