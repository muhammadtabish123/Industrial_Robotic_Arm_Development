#pragma once 

#include<Arduino.h>

#define PWM_FREQUENCY  500 //Hz
#define DUTY_CYCLE     50 
#define ON_TIME(PWM_FREQUENCY, DUTY_CYCLE)         1/(PWM_FREQUENCY * (DUTY_CYCLE/100))//second
#define OFF_TIME(PWM_FREQUENCY, DUTY_CYCLE)        1/(PWM_FREQUENCY * (1 - (DUTY_CYCLE/100))) //second

class AcServoMotor
{
  private:
    uint8_t acServoMotorPwmCw;
    uint8_t acServoMotorPwmCcw;
    uint8_t acServoMotorpushButtonCw; 
    uint8_t acServoMotorpushButtonCCw;
    uint8_t acServoMotorDutyCycle;
    uint16_t acServoMotorFrequency;

    void generatePwm(uint8_t portNum=NULL);
    bool pushButtonCwState();
    bool pushButtonCCwState();

  public:
     AcServoMotor(uint8_t PwmCw, uint8_t PwmCcw, uint8_t pushButtonCw, uint8_t pushButtonCCw,uint16_t freguency = PWM_FREQUENCY, uint8_t dutyCycle = DUTY_CYCLE); //Constructor
     void shaftRotation();    
};