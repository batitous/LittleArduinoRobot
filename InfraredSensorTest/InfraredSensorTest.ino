// Test of infrared sensor on the Arduino Yun.
// How to use it :
// - open the Arduino serial console

#include <Arduino.h>
#include <Console.h>


#define INFRARED_SENSOR_INPUT	A0


void setup()
{
	Bridge.begin();
  	Console.begin();

	while (!Console)
  	{
  		// wait Arduino Console connection.
  	}

	Console.println("Simple loop for infrared sensor !");

	pinMode(INFRARED_SENSOR_INPUT, INPUT);

}


void loop()
{
	int analogValue = analogRead(INFRARED_SENSOR_INPUT);


	Console.println(analogValue);
	
	delay(50);
}

