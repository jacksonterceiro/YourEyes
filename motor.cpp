#include <stdlib.h>
#include <string.h>
#include "motor.h"

MotorActuator::MotorActuator(int pinIn) {
    pinMode(pinIn, OUTPUT);
    digitalWrite(pinIn, LOW);
    _pinMotor = pinIn;
}

void MotorActuator::EnableMotor(){
  digitalWrite(_pinMotor, HIGH);
}

void MotorActuator::DisableMotor(){
  digitalWrite(_pinMotor, LOW);
}
