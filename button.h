#ifndef BUTTON_H
#define BUTTON_H

#include <stddef.h>
#include <Arduino.h>

class ButtonConfDistance {
  public:
    ButtonConfDistance(int pinIn);
    enum enStatusDistanceButton {DISTANCE_30, DISTANCE_60, DISTANCE_90, DISTANCE_120};
    bool checkButton();
    void changeConf();
    int getDistance();
    
  private:
    int _pinButton;
    enStatusDistanceButton _statusDistanceButton;
};

#endif //BUTTON_H
