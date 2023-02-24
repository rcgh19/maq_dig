#define PIN_LED 33
#define PIN_BUTTON 34


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_BUTTON,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool button_status = digitalRead(PIN_BUTTON);
  if (button_status){
    digitalWrite(PIN_LED,HIGH);
  }
  else{
    digitalWrite(PIN_LED,LOW);
  }
  delay(100);
}
