ArduinoNesController
====================

A simple way to read data from a NES controller with an Arduino

Mathieu Jouhet (@daformat)
 http://digitalcuisine.fr
 http://mathieujouhet.com

Inspired by Big Oil
http://forum.arduino.cc/index.php/topic,8481.0.html

Rough schematic of the NES controller:
 ```
                  _____
                 /
                /     0  ---  0v (ground)
       +5V  ---  0    0  ---  CLOCK
   nothing  ---  0    0  ---  LATCH
   nothing  ---  0    0  ---  SERIAL OUT
                 ______ 
 ```

The example sketch uses the following pins:
 ```
		int latch = 2; // set the latch pin
		int clock = 3; // set the clock pin
		int datin = 4; // set the serial out pin
 ```

Don't forget to hook the controller the the +5V and ground pins as well...