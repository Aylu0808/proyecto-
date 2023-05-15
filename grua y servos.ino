#include <Servo.h>


Servo miservo_3;
Servo miservo_2;
Servo miservo_1;

volatile int grados2 = 0;
volatile int grados3 = 0;
volatile int grados1 = 0; 

#define p3 A2
#define p4 A3
#define p2 A1
#define p1 A0

void derecha();
void izquierda();

void setup() {

  miservo_3.attach(9, 750, 1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_3.write(grados3);//b 

  miservo_2.attach(5, 750, 1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_2.write(grados2);

  miservo_1.attach(10, 750, 2700); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados1);//b 

  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p1, OUTPUT);
}

void loop() {

  if(digitalRead(p3) == HIGH){

    grados2++;
    grados3 = 0;
    
    if(grados2 >= 180 and grados3 >= 0){
      grados2 == 180;
    }
    miservo_2.write(grados2);
    delay(10);
    miservo_3.write(grados3);
    delay(10);
  }
  if(digitalRead(p4) == HIGH){

    grados2--;
    grados3++;
    if(grados2 >= 0 and grados3 >= 60){

      grados2 = 0;
      grados3 = 60;
    }
    miservo_2.write(grados2);
    delay(10);
    miservo_3.write(grados3);
    delay(10);
  }
  if (digitalRead(p2) == HIGH){
          derecha();
        }
 if (digitalRead(p1) == HIGH){
          izquierda();
}
}
void derecha(){
  grados1++;
  
  if(grados1 >= 270){  
    grados1 = 270;
  }
  
  miservo_1.write(grados1);
  delay(10);
}
void izquierda(){
  grados1--;
  
  if(grados1 <= 0){ 
    grados1 = 0;
  }
  
  miservo_1.write(grados1);
  delay(10);
}
