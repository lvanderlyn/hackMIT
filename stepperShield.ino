#include <Servo.h>

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_StepperMotor *motor1 = AFMS.getStepper(20, 1); // Define motor 1 getStepper(#steps per revolution, stepper#)
Adafruit_StepperMotor *motor2 = AFMS.getStepper(20, 2); // Define motor 2

int spd = 1000; //Revolution per minute
int steptype = MICROSTEP;
int state = 0;
String incomingString = '';
String bufferString = '';


void setup(){
  Serial.begin(9600);
  AFMS.begin();
  motor1->setSpeed(spd); // Set speeds of motors 1 and 2 (rotations per minute)
  motor2->setSpeed(spd);
}

void right_turn(int steps){
  for (int i = 0; i < steps; i++){
      motor1->step(1, FORWARD, steptype); //step(#steps, direction, steptype)
      motor2->step(1, BACKWARD, steptype);
    }
  }
  
void left_turn(int steps){
  for (int i = 0; i < steps; i++){
      motor1->step(1, BACKWARD, steptype);
      motor2->step(1, FORWARD, steptype);
    }

void forward(int steps){
    for (int i = 0; i < steps; i++){
      motor1->step(1, FORWARD, steptype);
      motor2->step(1, FORWARD, steptype);
    }
  
void loop(){
  switch(state) {
    // CASE 0 = Arduino reading mode
    case 0: {
      if (Serial.available() > 0) {
      	// get one char from what Python sent
        int incoming = Serial.read();

        // was it end character?
        if (char(incoming)=='/') {
          state = 1; // switch to writing mode - DO NOT MODIFY
        } else {
          incomingString = incomingString + char(incoming); // add to string of notes
        }
      }
      break;
    }
    case 1:{
      char array = char[incomingString.length()];
      incomingString.toCharArray(array, incomingString.length())
      for(int i = 0; i < incomingString.length()*0.5; i+=2){
        if (array[i] == 'f'){
          forward(array[i+1]);
        }
        else if(array[i] == 'r'{
          right_turn(array[i+1]);
        }
        else if(array[i] == 'l'{
          left_turn(array[i+1]);
        }
        else{
          
        }
      incomingStrign = '';
      state = 0;
 
}
