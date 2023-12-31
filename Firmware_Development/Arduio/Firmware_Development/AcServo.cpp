#include"AcServo.hpp"

AcServoMotor::AcServoMotor(uint8_t PwmCw, uint8_t PwmCcw, uint8_t pushButtonCw, uint8_t pushButtonCCw,uint16_t freguency = PWM_FREQUENCY, uint8_t dutyCycle = DUTY_CYCLE)//Constructor
  :acServoMotorPwmCw(PwmCw), acServoMotorPwmCcw(PwmCcw), acServoMotorpushButtonCw(pushButtonCw), acServoMotorpushButtonCCw(pushButtonCCw), acServoMotorFrequency(freguency), acServoMotorDutyCycle(dutyCycle) 
{
  pinMode(acServoMotorPwmCw, OUTPUT);
  pinMode(acServoMotorPwmCcw, OUTPUT);
  pinMode(acServoMotorpushButtonCw, INPUT_PULLUP);
  pinMode(acServoMotorpushButtonCCw, INPUT_PULLUP);
}

void AcServoMotor::generatePwm(uint8_t portNum)
{
  digitalWrite(portNum, HIGH);
  delayMicroseconds(ON_TIME(acServoMotorFrequency, acServoMotorDutyCycle));
  digitalWrite(portNum, LOW);
  delayMicroseconds(OFF_TIME(acServoMotorFrequency, acServoMotorDutyCycle));
}

void AcServoMotor::shaftRotation()
{
 while(pushButtonCwState())
     generatePwm(acServoMotorPwmCw); 

  while(pushButtonCCwState())
     generatePwm(acServoMotorPwmCcw);   
}

bool AcServoMotor::pushButtonCwState()
{
  return LOW == digitalRead(acServoMotorpushButtonCw);//push button is pullup when it push the logic will be low 
}

bool AcServoMotor::pushButtonCCwState()
{
  return LOW == digitalRead(acServoMotorpushButtonCCw);//push button is pullup when it push the logic will be low 
}