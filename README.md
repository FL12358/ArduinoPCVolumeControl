# ArduinoPCVolumeControl
Using arduino uno to control pc volume as a HID.

Hoodloader2 was used to be able to control the USB interface chip on the Uno (16u2 chip), this was needed for the device to act as a HID as the main Uno processor (ATmega328P) does not interface directly with the USB port.

16u2 chip waits for serial signal from the main processor then using the HID-Project libary (https://github.com/NicoHood/HID) outputs the correct change media signal to the PC. 

Main Uno device is waiting for an increment/decrement or push button signal from the rotary encoder. When these signals are detected the Uno sends a relevant signal over the internal serial connection to the 16u2. 

