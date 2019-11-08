#include <stdlib.h>
#include <string.h>
#include "button.h"


ButtonConfDistance::ButtonConfDistance(int pinIn) {
    pinMode(pinIn, INPUT);
    digitalWrite (pinIn, HIGH);
    _pinButton = pinIn;
    _statusDistanceButton = DISTANCE_30;
    _timeButton = 2; //second
}

bool ButtonConfDistance::checkButton(){
  return !digitalRead(_pinButton); //invertido pois o curto do botao realizado eh de 1 -> 0
}

int ButtonConfDistance::changeConf(){
  if (_statusDistanceButton == DISTANCE_120)
    _statusDistanceButton = DISTANCE_30;
  else
    _statusDistanceButton = (enStatusDistanceButton)((int)_statusDistanceButton + DISTANCE_30);
  return (int)_statusDistanceButton;
}

int ButtonConfDistance::getDistance(){
  return (int)_statusDistanceButton;
}

void ButtonConfDistance::setTimeButton(int timeSecond){
  _timeButton = timeSecond;
}

bool ButtonConfDistance::pressTimeButton(){
  int seconds = 0, i = 0;

  for(i = 0; i <= _timeButton; i++){
    if(checkButton())
      seconds++;
    else
      return false;
    delay(1000); //1 second
  }

  return true;
}
