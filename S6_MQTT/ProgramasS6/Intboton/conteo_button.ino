#define PIN_LED 33
#define PIN_BUTTON 34
int  numBotPres = 0;

uint32_t lastMillis = 0 ; 

void IRAM_ATTR ISR(){

  if(millis()-lastMillis > 10){
    numBotPres += 1;
    lastMillis = millis();
  }
  
  //x = millis() // 100
  //instruc // 2 ms
  //instruc // 3 ms
  //instruc // 5 ms
  //x = millis() // 110
  
  
  //numBotPres += 1; 
  //numBotPres ++;   
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_BUTTON,INPUT);

  //void * arg
  attachInterrupt(PIN_BUTTON,ISR,RISING);
  //attachInterrruptArg(PINN_BUTTON,)
}

void loop() {
  // put your main code here, to run repeatedly:
  //bool button_status = digitalRead(PIN_BUTTON);
  //  if (button_status){
  //  digitalWrite(PIN_LED,HIGH);
  //}
  //else{
  // digitalWrite(PIN_LED,LOW);
  //}
  //delay(100);
  Serial.printf("El boton ha precionado %u veces\n",numBotPres);
  delay(100);

}
