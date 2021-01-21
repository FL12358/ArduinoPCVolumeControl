#include <HID-Project.h>

#define encoder0PinA 0
#define encoder0PinB 1
#define encoder0Btn 2

int encoder0Pos = 0;
int valRotary,lastValRotary;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  pinMode(encoder0PinA, INPUT_PULLUP);
  pinMode(encoder0PinB, INPUT_PULLUP);
  pinMode(encoder0Btn, INPUT_PULLUP);
  attachInterrupt(0, doEncoder, CHANGE);

  Consumer.begin();
}

void loop() {
  int btn = digitalRead(encoder0Btn);
  
  Serial.print(btn);
  Serial.print(" : ");
  Serial.print(valRotary);
  
  if(valRotary>lastValRotary){
    Serial.print("  CW");
    Consumer.write(MEDIA_VOL_UP);
  }
  if(valRotary){
    Serial.print("  CCW");
    Consumer.write(MEDIA_VOL_UP);
  }

  if(!btn){
    Consumer.write(MEDIA_VOL_MUTE);
  }
  lastValRotary = valRotary;
  
  Serial.println("");
  delay(100);
}

void doEncoder(){
  if(digitalRead(encoder0PinA) == digitalRead(encoder0PinB)){
    encoder0Pos++;
  }else{
    encoder0Pos--;
  }
  valRotary = encoder0Pos/2.5;
}
