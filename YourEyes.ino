//Button
#include "button.h"

//Motor
#include "motor.h"

//Ultrasonic HC-SR04
#include <Ultrasonic.h>

//Button pin
#define PIN_BUTTON 11

//Ultrasonic trigger and echo
#define PIN_TRIGGER 12
#define PIN_ECHO 13

//Motor pin
#define PIN_ACTUATOR_1 9
#define PIN_ACTUATOR_2 10

ButtonConfDistance buttonConfDistance(PIN_BUTTON);  //Initializing button
Ultrasonic ultrasonic(PIN_TRIGGER, PIN_ECHO);       //Initializing ultrasonic
MotorActuator motorActuator(PIN_ACTUATOR_1, PIN_ACTUATOR_2);          //Initializing actuador

float readUltrasonic(){
  long microsec = ultrasonic.timing();
  return ultrasonic.convert(microsec, Ultrasonic::CM);
}

void managementButton(ButtonConfDistance *clButton, MotorActuator *clMotor) {
  if(!clButton->pressTimeButton())
    return;

  Serial.println("Modificando distancia");
  clMotor->EnableMotorWithBreaks(clButton->changeConf() / 30); //Primeira distancia de reconhecimento;
}

void managementMotor(MotorActuator *clMotor){
  clMotor->EnableMotorWithTime(400);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop() {
  float cmMsec;

  managementButton(&buttonConfDistance, &motorActuator);
  
  cmMsec = readUltrasonic();
  Serial.print("Distancia: "); Serial.println(cmMsec);
  
  if(buttonConfDistance.getDistance() >= (int)readUltrasonic())
    managementMotor(&motorActuator);

  Serial.print("Status Button: "); Serial.println(buttonConfDistance.getDistance());
}
