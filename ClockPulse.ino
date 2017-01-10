
/*
 Clock Pulse

 This sketch sends impulses to a modified quartz clock movement.

 Created  6 Dec 2016
 By Seppo Alanärä

 http://www.arduino.cc/en/Tutorial/TimeCheck
*/

#include "TimerOne.h"

extern unsigned long timer0_overflow_count;
 
int clockA = 4; // 22;         // Pins attached to the clock coil wires
int clockB = 5; // 23;         // Order is not important.
 
int tickPin = clockA;          // Select which clock pin is pulsed first.
 
// Initialize the IO ports
void setup()
{ 
  Timer1.initialize();             // initialize timer1, and set a 1 second period
  Timer1.attachInterrupt(doTick);  // attaches doTick() as a timer overflow interrupt
    
  pinMode(clockA, OUTPUT);
  pinMode(clockB, OUTPUT);
 
  digitalWrite(clockA, LOW);
  digitalWrite(clockB, LOW);
 
  Serial.begin(9600);
}
  
// Move the second hand forward one step (one second on the clock face).
void doTick() {
  // Serial.println(millis());
  digitalWrite(tickPin, HIGH);
  delay(3700);                  
  digitalWrite(tickPin, LOW);  
  // Invert the impulse polarity.
  if (tickPin == clockA) {
    tickPin = clockB;
  } else {
    tickPin = clockA;
  }
}
 
// Main loop
void loop() {  
  //  nothing to see here
}

