//MAESTRO
#include <SoftwareSerial.h>



int pulsador1 = 3; // Pulsador en el pin 2
int pulsador2 = 4;
int pulsador3 = A0; // Pulsador en el pin 2
int pulsador4 = A1;

void setup() {
  
  pinMode(pulsador1, INPUT);
  pinMode(pulsador2, INPUT);
  pinMode(pulsador3, INPUT);
  pinMode(pulsador4, INPUT);
  
  Serial.begin(57600); // Configura la comunicación serial con el módulo HC-05
}

void loop() {

  if(digitalRead(pulsador1) == HIGH){

     Serial.write('1');
     delay(50);
  }
 
  if(digitalRead(pulsador2) == HIGH){

     Serial.write('2');
     delay(50);
  }
  if(digitalRead(pulsador3) == HIGH){

     Serial.write('3');
     delay(50);
  }
  if(digitalRead(pulsador4) == HIGH){

     Serial.write('4');
     delay(50);
  }
}
