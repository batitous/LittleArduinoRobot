# A Custom Robot Arduino


Code and libraries for a custom little Robot Arduino.


## Structure

* `3D_Files` stores the CAO files in STEP and EASM format. Open it with a free CAO viewer.
* `Adafruit_Motor_Shield` contains a patched version for the Arduino Leonardo / Yun with Adafruit Motor Shield v1.
* `Adafruit_Motor_Shield_V2` must be used for Adafruit Motor Shield v2.
* `Datasheets` stores the hardware files of the robots.
* `BridgeTest`, `InfraredSensorTest` and `StepperMotorTest` contains basic examples for stepper motors, for infrared sensor and wifi communication.  


## How to use it

* Clone this repo.
* Copy the `Adafruit_Motor_Shield_V2` repertory into your Arduino libraries repertory.
* Launch your Arduino IDE, the `Adafruit_Motor_Shield_V2` must appears in the libraries menu list.


## License

Most of the code are under the MIT license, public domain or GPL.
