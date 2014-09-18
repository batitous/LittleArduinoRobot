// Communication test between Arduino and Wifi with the Bridge
//
// After uploading, you can connect to your Arduino Yun with :
// - from the command : ssh root@yourArduinoName.local 'telnet localhost 6571'
// - from the Arduino serial console
// - from a web browser to http://yourArduinoName.local/arduino/toto/1234

#include <Arduino.h>
#include <Console.h>
#include <YunServer.h>
#include <YunClient.h>


YunServer server;


void setup()
{
	Bridge.begin();
  	Console.begin(); 


  	server.listenOnLocalhost();
  	server.begin();

//	while (!Console)
//  	{
//  		// wait for Console port to connect.
//  	}

  	Console.println("You're connected to the console !");

}

void loop()
{
	YunClient client = server.accept();

	// Get command from the url: http://yourArduinoYun.local/arduino/toto
	if (client)
	{
    	executeUrlCommand(client);
    	client.stop();
  	}

	// Get command from the Console :
	if (Console.read()!=-1)
	{
		Console.println("Receive something...");
	}
	
}

void executeUrlCommand(YunClient client)
{
	String command = client.readStringUntil('/');

	Console.print("Execute ");
	Console.print(command);
	Console.print(" arg: ");

	if (command=="toto")
	{
		Console.println(client.readString());
	}
	else if (command=="titi")
	{
		Console.println(client.readString());
	}
	else if (command=="tutu")
	{
		Console.println(client.readString());
	}
	else
	{
		Console.print("Huuu?? ");
		Console.println(client.readString());
	}

	// send answer to the client:
	client.print("Got your command : ");
	client.print(command);

}
