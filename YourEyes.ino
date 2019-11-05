#include "button.h"

#define PIN_BUTTON 6

ButtonConfDistance buttonConfDistance(PIN_BUTTON);

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop() {

  if(buttonConfDistance.checkButton())
    buttonConfDistance.changeConf();

   Serial.println(buttonConfDistance.getDistance());
   delay(200);

}
