This program was originally created in conjunction with an ESP32 based
VFO program that I have been developing along with Glenn (VK3PE) and
Jim (G2ZQC). The Si5351 software is a modified version of the code used
in TJ Uebo’s (JF3HZB) digital VFO.

Before using the Si5351 module, its output frequencies should be calibrated.

The crystal frequency of the Si5351 is nominally 25 MHz (27 MHz on some),
but all of the Si5351 modules we’ve tested have been off by a little bit
(some much more than others).

The original version of the program was designed to only work on the
ESP32, but realizing that the application has more general uses, I
modified it to also run on an Arduino. I’ve only tested it on a UNO,
but there’s no reason it won’t work on other versions that I can see.
The program’s user interface is the Arduino IDE’s Serial Monitor.

The full details are in the Calibrate_Si5351 Manual.

John
WA2FZW