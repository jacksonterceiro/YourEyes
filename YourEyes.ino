//Button
#include "button.h"

//Motor
#include "motor.h"

//Thread
#include <ThreadController.h>
#include <StaticThreadController.h>
#include <Thread.h>

//Ultrasonic HC-SR04
#include <Ultrasonic.h>

//Button pin
#define PIN_BUTTON 6

//Ultrasonic trigger and echo
#define PIN_TRIGGER 8
#define PIN_ECHO 9

//Motor pin
#define PIN_ACTUATOR 10

ButtonConfDistance buttonConfDistance(PIN_BUTTON);  //Initializing button
Ultrasonic ultrasonic(PIN_TRIGGER, PIN_ECHO);       //Initializing ultrasonic
MotorActuator motorActuator(PIN_ACTUATOR);          //Initializing actuador

float readUltrasonic(){
  long microsec = ultrasonic.timing();
  return ultrasonic.convert(microsec, Ultrasonic::CM);
}

//verificar a viabilidade de colocar isso dentro da lib button.cpp
void managementButton(ButtonConfDistance *clButton) {
  
  if(clButton->checkButton())
    clButton->changeConf();
  
    //Serial.println(buttonConfDistance.getDistance());
    //delay(200);
}

void managementMotor(MotorActuator *clMotor){
  clMotor->EnableMotor();
  delay(10);
  clMotor->DisableMotor();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop() {
  float cmMsec;

  managementButton(&buttonConfDistance);
  
  cmMsec = readUltrasonic();
  if(buttonConfDistance.getDistance() >= (int)readUltrasonic())
    managementMotor(&motorActuator);

}
