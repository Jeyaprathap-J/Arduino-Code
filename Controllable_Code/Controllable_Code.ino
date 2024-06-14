bool Wait = false;
bool PinSeven = false;
bool PinEight = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Please power PIN 13 to start");
  Serial.println("Arduino is waiting to start...");
  while(digitalRead(13) == LOW){
    //Wait for trigger
  }
  Serial.println("Arduino is started!");
  PinSeven = true;
  PinEight = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8) == HIGH && PinEight){
    PINEight();
    PinSeven = true;
    PinEight = false;
  }
  else if(digitalRead(7) == HIGH && PinSeven){
    PINSeven();
    PinEight = true;
    PinSeven = false;
  }
  else if(digitalRead(2) == HIGH){
    Serial.println("Resetting Arduino UNO...");
    reset();
  }
  else if(Wait && digitalRead(8) == LOW && digitalRead(7) == LOW){
    Serial.println("Waiting for inputs...");
    Wait = false;
    PinSeven = true;
    PinEight = true;
  }
}

void reset(){
  asm volatile (" jmp 0");
}

void PINEight(){
  Serial.println("Power incomming in PIN(8)");
  Wait = true;
}

void PINSeven(){
  Serial.println("Power incomming in PIN(7)");
  Wait = true;
}
