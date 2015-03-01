#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_StepperMotor *motor1 = AFMS.getStepper(200, 1); // Define motor 1
Adafruit_StepperMotor *motor2 = AFMS.getStepper(200, 2); // Define motor 2

int spd = 5;
int steps = 10;
int steptype = MICROSTEP;

void setup(){
  motor1.setSpeed(spd); // Set speeds of motors 1 and 2 (rotations per minute)
  motor2.setSpeed(spd);
}

void loop(){
  if (a == 1){ //made up random variable to separate cases
    // Rotate right
    motor1.step(steps, FORWARD, steptype); //step(#steps, direction, steptype)
    motor2.step(steps, BACKWARD, steptype);
  }
  else if (a == 2){
    // Rotate left
    motor1.step(steps, BACKWARD, steptype);
    motor2.step(steps, FORWARD, steptype);
  }
  else if (a == 3){
    // Move forward
    motor1.step(steps, FORWARD, steptype);
    motor2.step(steps, FORWARD, steptype);
  }
  else {
    // Move backward
    motor1.step(steps, BACKWARD, steptype);
    motor2.step(steps, BACKWARD, steptype);
  }
  
}
