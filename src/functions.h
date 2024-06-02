#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <Arduino.h>
#include <M5Stack.h>

bool action_say_hello()
{
  Serial.println("Me the agent");
  return true;
}

bool action_swear()
{
  Serial.println("Booyaka");
  M5.Lcd.fillScreen(RED);
  sleep(1000);
  M5.Lcd.fillScreen(BLACK);
  return true;
}

bool update_pressed(bool var){
  return M5.BtnA.isPressed() == 1 ? true : false;
}

#endif /* FUNCTIONS_H_ */