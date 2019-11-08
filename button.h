#ifndef BUTTON_H
#define BUTTON_H

#include <stddef.h>
#include <Arduino.h>

class ButtonConfDistance {
  public:
    ButtonConfDistance(int pinIn);
    enum enStatusDistanceButton {DISTANCE_30 = 30, DISTANCE_60 = 60, DISTANCE_90 = 90, DISTANCE_120 = 120};
    bool checkButton();
    int changeConf();
    int getDistance();
    void setTimeButton(int timeSecond);
    bool pressTimeButton();
    
  private:
    int _pinButton;
    int _timeButton;
    enStatusDistanceButton _statusDistanceButton;
};

#endif //BUTTON_H
