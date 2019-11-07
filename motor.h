#ifndef MOTOR_H
#define MOTOR_H

#include <stddef.h>
#include <Arduino.h>

class MotorActuator {
  public:
    MotorActuator(int pinIn);
    void EnableMotor();
    void DisableMotor();
    
  private:
    int _pinMotor;
};

#endif //MOTOR_H
