#define encoder0PinA 3
#define encoder0PinB 2
#define encoder0Btn 4

int encoder0Pos = 0;
int valRotary,lastValRotary;

void setup() {
  // Start the Serial which is connected with the USB MCU.
  // Make sure both baud rates are the same
  // you can go up to 2000000 for very fast data transmission.
  Serial.begin(115200);
  
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder0Btn, INPUT_PULLUP);
  attachInterrupt(0, doEncoder, CHANGE);
}

void loop() {
  int btn = digitalRead(encoder0Btn);
  
  if(valRotary>lastValRotary){
    Serial.print("uu");
  }
  if(valRotary<lastValRotary){
    Serial.print("dd");
  }
  lastValRotary = valRotary;
  if(!btn){
    Serial.print("m");
    delay(100);
  }
  //Serial.println("");
  delay(200);
}

void doEncoder(){
  if(digitalRead(encoder0PinA) == digitalRead(encoder0PinB)){
    encoder0Pos++;
  }else{
    encoder0Pos--;
  }
  valRotary = encoder0Pos/2.5;
}
