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

void MotorActuator::EnableMotorWithTime(int milliseconds){
  EnableMotor();
  delay(milliseconds);
  DisableMotor();
  delay(milliseconds/2);
}

void MotorActuator::EnableMotorWithBreaks(int qnt){
  int i = 0;
  for(i = 0; i < qnt; i++){
    EnableMotor();
    delay(700);
    DisableMotor();
    delay(300);
  }
}
