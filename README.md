# ElanBT – Instructions for a DIY wireless ElanScan interface
Cheap Bluetooth to ALDL interface for GM cars and specifically the Lotus Elan M100

Join the community at https://www.lotuselancentral.com

Follow the discussion at https://forum.lotuselancentral.com/viewtopic.php?f=34&t=29379

ElanBT is a prototype for a wireless ElanScan interface that you can build yourself. 
It allows a laptop with Bluetooth to run ElanScan wirelessly via a virtual COM-Port.

This interface runs on power from the ALDL connector, so it is truely wireless.

It will also work with ALDLdroid and ALDL Scan on Android phones, given the right .adx/.aldl config file (and also for other GM cars that support 8192 baud ALDL).

It is a prototype, as the components are big and ugly, but can be purchased and put together easily. Nevertheless, this prototype fully works, and if you can live with its looks, or if you hide it under the glove box next to the ALDL connector, this can be made suitable for day to day use.

Comments on the photos of the prototype:
The three dangling lines on the right hand side picture go to the ALDL connector on the Elan (black to A[Ground], purple to G[data] and red to F[12volts]). 
For testing purposes, I chose to do without a proper OBD1 connector.

Parts list:

This is the list of parts, that you require. It is similar to the parts needed for ElanLogger (a separate project that provides a stand-alone data logger for the Elan).

- 1 	Arduino Uno development board
- 1 	HC-05 Bluetooth module
- 2 	100 ohm resistors
- 1 	5.1v zener diode (1N4733A)
- 1 	1k ohm resistor
- 1 	2k ohm resistor
- 1	OBD1 connector
- 1	power switch
- 9	jumper cables to connect everything

The two main components are the Arduino Uno R3 dev board and the HC-05 Bluetooth module. You can buy those online each for less than 10 GBP. You should also buy a 10-pin OBD1 connector and a small power switch to turn the interface on and off. For my prototype I  did not use either, though, but connected the lines directly to the ALDL connector on the car which also turns the interface on, as there is permanent 12 volts on the ALDL connector.

As you can see in the photos of the prototype, most connections can be done solderless with Arduino jumper cables. For the additional solder connections I used a 5x6 prototype board, but you could also solder the components and connect them directly.

The purpose of the Arduino Uno ist to translate the serial connection from the Bluetooth module with 9600 bits/s to the ALDL interface with 8192 bits/s. You need it to run a small software (called Sketch in Arduino‘s world). The source code for this sketch is on the bottom of this document. You need to put it in a file called „ElanBT.ino“ within a folder called „ElanBT“. You then can install it on your Arduino Uno via USB with the help of the „Arduino IDE“. This is free software that you will find online.

As soon as you switch ElanBT on (by connecting it to the ALDL connector on your car and the optional power switch) you will be able to connect your laptop to the Bluetooth device "HC-05" (pin:1234), and this will automatically add a COM-Port for ElanScan. You need to look up the COM-Port number in your Windows Bluetooth settings (under „More Bluetooth settings“).
Then you run ElanScan like you would with a wired connection.

Final Notes
If you want the whole thing in a less ugly and more compact form, you could replace the Arduino Uno with an Arduino Nano, add a simple voltage regulator (to bring down battery voltage to less than 12v for the Nano) and solder everything together inside an OBD1 connector.

Disclaimer
I have provided this information with best intentions, please use it at your own risk. In other words: try not to short your ECU. 
