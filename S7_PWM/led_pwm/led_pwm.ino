#define PIN_LED 33  // PIN DE PWM
#define PIN_POT 36  // PIN ADC (ANALOG TO DIGITAL CONVERTED) POTENCIOMETRO
#define PIN_LDR 35  // FOTO RESISTOR 
int pwm_in = 0;
int ldr_in = 0;
void setup() {
  // CONFIGURACION PARA EL LED
  Serial.begin(115200);
  pinMode(PIN_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pwm_in = analogRead(PIN_POT);

  ldr_in = analogRead(PIN_LDR);

  Serial.println(ldr_in/16);

  //Serial.println(pwm_in);
  // controlamos con el 
  // potenciometro la senal del led
  // 
  //analogWrite(PIN_LED,pwm_in/16);
  analogWrite(PIN_LED,ldr_in/16);
  //for(int i =0; i < 255; i++){  
  //  analogWrite(PIN_LED, i);
  //  delay(10);
  //  }

  // for(int i =255; i > 0; i--){  
  //   analogWrite(PIN_LED, i);
  //   delay(10);
  //   }


  delay(100);
}
