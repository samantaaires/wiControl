/*
VCC - 5V
GND - GND
TXD - TX
RXD - RX
IR - 3
*/

#include <IRremote.h>
IRsend irsend;
void setup(){
  Serial.begin(9600);
  Serial.println("Iniciando");
}
void loop(){
  if(Serial.available()){
    int resp = Serial.read();
    if(resp == 'a'){
      send1();
    }
    else if(resp == 'b'){
      send2();
    }
  }
}

void send1() {
  unsigned int raw[] = {9400, 4400, 600, 1650, 550, 550, 500, 600, 550, 550, 500, 1700, 500, 600, 500, 600, 500, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 500, 600, 550, 550, 550, 550, 550, 550, 550, 1650, 500, 1700, 550, 550, 500, 600, 550, 1650, 550, 550, 500, 600, 550, 1650, 550, 550, 500, 1700, 500, 600, 550};
  irsend.sendRaw(raw, 59, 38);
  Serial.println("Ligar Ar");
  delay(1000);
}

void send2() {
  unsigned int raw[] = {9400, 4450, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1500, 650, 600, 550, 550, 550, 550, 550, 550, 550, 550, 500, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 1650, 550, 550, 500, 600, 500, 600, 450, 1700, 550};
  irsend.sendRaw(raw, 59, 38);
  Serial.println("Desligar Ar");
  delay(1000);
}
