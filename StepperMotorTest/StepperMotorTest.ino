// Test of stepper motor on the Arduino Yun.
// How to use it :
// - open the Arduino serial console

#include <Wire.h>
#include <Arduino.h>
#include <Console.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"


#define DEFAULT_STEP_NUMBER		100


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor * motor1 = AFMS.getStepper(200, 2);
Adafruit_StepperMotor * motor2 = AFMS.getStepper(200, 1);



void motorInitialize()
{
	AFMS.begin();
	
	// rotation per min
	motor1->setSpeed(50); 
  	motor2->setSpeed(50);
  	motor1->release();
  	motor2->release(); 
}

void motorForward()
{
	for (int i=0; i < DEFAULT_STEP_NUMBER; i++)
	{
		motor1->step(1, FORWARD, SINGLE); 
		motor1->release();
		motor2->step(1, BACKWARD, SINGLE); 
		motor2->release();
	}
}

void motorBackward()
{
	for (int i=0; i < DEFAULT_STEP_NUMBER; i++)
	{
		motor1->step(1, BACKWARD, SINGLE); 
		motor1->release();
		motor2->step(1, FORWARD, SINGLE); 
		motor2->release();
	}
}


void setup()
{
	Bridge.begin();
  	Console.begin();

	while (!Console)
  	{
  		// wait Arduino Console connection.
  	}

	Console.println("Test of Stepper Motor !");
	
	motorInitialize();

}

void loop()
{
	int command = Console.read();
	if (command!=-1)
	{
		switch(command)
		{
			//--------- move forward
			case 'f':
				Console.println("Move forward...");
				motorForward();
			break;
			//--------- move backward
			case 'b':
				Console.println("Move backward...");
				motorBackward();
			break;
			default:
				Console.println("Unknown command !");
			break;
		}
	}

}
