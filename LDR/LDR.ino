#define PIN_LED 33
#define PIN_LDR 35
#define THRLD 400

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_signal = analogRead(PIN_LDR);

  if(ldr_signal > THRLD){
    digitalWrite(PIN_LED, LOW);    
  }
  else{
    digitalWrite(PIN_LED,HIGH);
  }
  Serial.println(ldr_signal);
  delay(50);
}
