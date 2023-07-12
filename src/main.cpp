#include <Arduino.h>
#include "GyverFilters.h"

// указываем размер окна и тип данных в <>
GMedian<128, int> testFilter;    

int calc_floor(int i);
int pind=3;
int analogPin=A3;
int freqPin =12;
int zero=0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(freqPin,OUTPUT);
  digitalWrite(freqPin,HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  zero=analogRead(analogPin);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  int a=analogRead(analogPin);
  a=calc_floor(a);
  int fa =testFilter.filtered(a);
  Serial.print("Var_a:");
  Serial.print(a);
  Serial.print(",");
  Serial.print("Var_fa:");
  Serial.print(fa);
  Serial.print(",");
  
  Serial.print("Freq:");
  
  if(a<=50){
      noTone(freqPin);
      Serial.println(0);}
  else{
    if(a>=250){
      tone(freqPin,2500);
      Serial.println(2500);}
    else {
      tone(freqPin,a*10);
      Serial.println(a*10);}
  }
  delay(10);                       // wait for a second
  
}
int calc_floor(int i)
{
  return i-zero;
}