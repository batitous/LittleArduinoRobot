// Test of infrared sensor on the Arduino Yun.
// How to use it :
// - open the Arduino serial console

#include <Arduino.h>


#define INFRARED_SENSOR_INPUT	A0


void setup()
{
	Serial.begin(115200);

	Serial.println("Simple loop for infrared sensor !");

	pinMode(INFRARED_SENSOR_INPUT, INPUT);

}


void loop()
{
	int analogValue = analogRead(INFRARED_SENSOR_INPUT);


	Serial.println(analogValue);
	
	delay(50);
}

