
#include "HID-Project.h"

void setup() {
  // Start the Serial1 which is connected with the IO MCU.
  // Make sure both baud rates are the same
  // you can go up to 2000000 for very fast data transmission.
  Serial1.begin(115200);

  // Sends a clean report to the host. This is important on any Arduino type.
  Consumer.begin();

  // Start the USB Serial for debugging
  Serial.begin(115200);
}

void loop() {
  // Check if any Serial data from the IO MCU was received
  // d - vol down, u - vol up, m - mute
  char c = Serial1.read();

  // If it's a character, print it!
  if (c >= 'a' && c <= 'z') {
    Serial.print("USB: ");
    Serial.print(c);
    Serial.println("\n");
  }
  if(c == 'd'){
    Consumer.write(MEDIA_VOL_DOWN);
  }
  if(c == 'u'){
    Consumer.write(MEDIA_VOL_UP);
  }
  if(c == 'm'){
    Consumer.write(MEDIA_VOL_MUTE);
  }
}
