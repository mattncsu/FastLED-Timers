//***************************************************************
// This example blinks a controller's onboard LED and prints
// some stuff to the console.  
// Check your controller's details to confirm which pin the 
// onboard LED is attached to.
//
// The EVERY_N_* timer functions used here come from the 
// FastLED library by Daniel Garcia and Mark Kriegsman.
// https://github.com/FastLED/FastLED
//
//
// Marc Miller, May 2020
//***************************************************************

#include "FastLED_timers.h"  // FastLED timer functions

uint8_t ledPin = 13;  // pin number for controller's onboard LED

//---------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  delay(2000);
  pinMode(ledPin, OUTPUT);
}

//---------------------------------------------------------------
void loop() {
  static bool toggle1;
  static bool toggle2;

  EVERY_N_SECONDS(2) {
    toggle1 = !toggle1;
  }

  EVERY_N_MILLISECONDS(60) {
    toggle2 = !toggle2;
  }

  if (toggle1 && toggle2) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  EVERY_N_SECONDS(5) {
    Serial.print("Current millis: ");
    Serial.println( millis() );
  }

  EVERY_N_SECONDS_I( timingObj, 15) {
    // This initally defaults to 15 seconds, but then will change the run
    // period to a new random number of seconds from 10 to 20 seconds.
    // You can name "timingObj" whatever you want.
    timingObj.setPeriod( random(10,21) );
    uint16_t newRandomTime = timingObj.getPeriod();
    Serial.print("  New random time = ");
    Serial.println(newRandomTime);
  }

}
