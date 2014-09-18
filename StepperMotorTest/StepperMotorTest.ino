
#include <Arduino.h>
#include <AFMotor.h>


// 20 = 360deg / 18deg
AF_Stepper motor1(20, 1);
AF_Stepper motor2(20, 2);


void setup()
{
	Serial.begin(115200);
	/*while (!Serial) {
    	; // wait for serial port to connect. Needed for Leonardo only
  	}*/


	Serial.println("Test of Stepper Motor !");
	
	// rotation per min
	motor1.setSpeed(300); 
	motor2.setSpeed(300);  


	motor1.step(20, FORWARD, SINGLE); 
	delay(500);
	motor1.step(20, BACKWARD, SINGLE);

}

void loop()
{
	if (Serial.read()!=-1)
	{
		Serial.println("Turn 360 deg !");

//		motor.step(20, FORWARD, DOUBLE);
		motor1.step(20, FORWARD, SINGLE);

		motor2.step(20, BACKWARD, SINGLE); 

		Serial.println("End of turn !");
	}

}
