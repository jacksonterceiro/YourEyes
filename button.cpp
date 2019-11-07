#include <stdlib.h>
#include <string.h>
#include "button.h"


ButtonConfDistance::ButtonConfDistance(int pinIn) {
    pinMode(pinIn, INPUT);
    digitalWrite (pinIn, HIGH);
    _pinButton = pinIn;
    _statusDistanceButton = DISTANCE_30;
}

bool ButtonConfDistance::checkButton(){
  return !digitalRead(_pinButton); //invertido pois o curto do botao realizado eh de 1 -> 0
}

void ButtonConfDistance::changeConf(){
  if (_statusDistanceButton == DISTANCE_120)
    _statusDistanceButton = DISTANCE_30;
  else
    _statusDistanceButton = (enStatusDistanceButton)((int)_statusDistanceButton + DISTANCE_30);
}

int ButtonConfDistance::getDistance(){
  return (int)_statusDistanceButton;
}
