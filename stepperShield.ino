#include <Servo.h>

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_StepperMotor *motor1 = AFMS.getStepper(20, 1); // Define motor 1 getStepper(#steps per revolution, stepper#)
Adafruit_StepperMotor *motor2 = AFMS.getStepper(20, 2); // Define motor 2

int spd = 1000; //Revolution per minute
int steps = 200; 
int steptype = MICROSTEP;
int a = 1;
int i = 0;

void setup(){
  Serial.begin(9600);
  AFMS.begin();
  motor1->setSpeed(spd); // Set speeds of motors 1 and 2 (rotations per minute)
  motor2->setSpeed(spd);
}

void loop(){
  if (a == 1){ //made up random variable to separate cases
    // Rotate right
    Serial.println("right");
    for (int i = 0; i < steps; i++){
      motor1->step(1, FORWARD, steptype); //step(#steps, direction, steptype)
      motor2->step(1, BACKWARD, steptype);
    }
    a = 2;
  }
  else if (a == 2){
    // Rotate left
    Serial.println("left");
    for (int i = 0; i < steps; i++){
      motor1->step(1, BACKWARD, steptype);
      motor2->step(1, FORWARD, steptype);
    }
    a = 3;

  }
  else if (a == 3){
    // Move forward
    Serial.println("forward");
    for (int i = 0; i < steps; i++){
      motor1->step(1, FORWARD, steptype);
      motor2->step(1, FORWARD, steptype);
    }
    a = 4;

  }
  else {
    // Move backward
    Serial.println("backward");
    for (int i = 0; i < steps; i++){
      motor1->step(1, BACKWARD, steptype);
      motor2->step(1, BACKWARD, steptype);
    }
    a = 1;

  }
  
}
