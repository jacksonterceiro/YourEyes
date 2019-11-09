#ifndef MOTOR_H
#define MOTOR_H

#include <stddef.h>
#include <Arduino.h>

class MotorActuator {
  public:
    MotorActuator(int pinIn1, int pinIn2);
    void EnableMotor();
    void DisableMotor();
    void EnableMotorWithTime(int milliseconds);
    void EnableMotorWithBreaks(int qnt);
    
  private:
    int _pinMotor1;
    int _pinMotor2;
};

#endif //MOTOR_H
