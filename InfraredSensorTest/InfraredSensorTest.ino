

#include <Arduino.h>


#define INFRARED_SENSOR_INPUT	1


void setup()
{
	Serial.begin(115200);
	/*while (!Serial) {
    	; // wait for serial port to connect. Needed for Leonardo only
  	}*/


	Serial.println("Simple loop for infrared snesor !");

	pinMode(INFRARED_SENSOR_INPUT, INPUT);

}


void loop()
{
	int analogValue = analogRead(INFRARED_SENSOR_INPUT);


	Serial.println(analogValue);
	
}

