#include <stdlib.h>
#include <string.h>
#include "motor.h"

MotorActuator::MotorActuator(int pinIn1, int pinIn2) {
    pinMode(pinIn1, OUTPUT);
    pinMode(pinIn2, OUTPUT);
    digitalWrite(pinIn1, LOW);
    digitalWrite(pinIn2, LOW);
    _pinMotor1 = pinIn1;
    _pinMotor2 = pinIn2;
}

void MotorActuator::EnableMotor(){
  digitalWrite(_pinMotor1, HIGH);
  digitalWrite(_pinMotor2, HIGH);
}

void MotorActuator::DisableMotor(){
  digitalWrite(_pinMotor1, LOW);
  digitalWrite(_pinMotor2, LOW);
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
