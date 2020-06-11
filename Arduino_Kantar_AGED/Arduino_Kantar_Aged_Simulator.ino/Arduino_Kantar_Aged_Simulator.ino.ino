#include <SoftwareSerial.h>
SoftwareSerial BTSerial(5,6);
int LED_PIN1=2;
int LED_PIN2=3;
int LED_PIN3=4;

void setup() {
  BTSerial.begin(9600);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  
}

 void loop() {

//delay(100);
  if(BTSerial.available()){
    int gelen= BTSerial.read();
    led_loop();
    }
  else{
    BTSerial.write("=150.000B0");
    BTSerial.write(0xFF);
    }

   
 }
 
void led_loop(){
  digitalWrite(LED_PIN1,HIGH);
  delay(20);
  digitalWrite(LED_PIN2,HIGH);
  delay(20);
  digitalWrite(LED_PIN1,LOW);
  delay(20);
  digitalWrite(LED_PIN3,HIGH);
  delay(20);
  digitalWrite(LED_PIN2,LOW);
  delay(20);
  digitalWrite(LED_PIN1,HIGH);
  delay(20);
  digitalWrite(LED_PIN3,LOW);
  delay(20);
  digitalWrite(LED_PIN2,LOW);
  delay(20);
  digitalWrite(LED_PIN1,LOW);
  delay(20);
  
  }


