#include <Servo.h>

#define p1 A0
#define p2 A1
#define p3 A2
#define p4 A3
#define p5 A4

Servo miservo_2; // SERVO A
Servo miservo_3;
Servo miservo_1;

volatile int grados2 = 0;
volatile int grados3 = 0;
volatile int grados1 = 0; 

void setup() {
  
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);
  pinMode(p4, INPUT);
  pinMode(p5, INPUT);
  
  Serial.begin(9600);

  miservo_2.attach(6, 1000, 2000);
  miservo_2.write(grados2);

  miservo_3.attach(11, 1000, 2000); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_3.write(grados3);//b 

  miservo_1.attach(10, 1000, 2000); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados1);//b

}

void loop() {
  
  if(digitalRead(p1) == HIGH){//adelante o atras

    grados2++;
    
    if(grados2 >= 180){
      grados2 == 180;
    }
    miservo_2.write(grados2);
    delay(10);
  }
   if(digitalRead(p2) == HIGH){ //adelante o atras

    grados2--;

    if(grados2 <= 0){
      grados2 = 0;
    }
    miservo_2.write(grados2);
    delay(10);
  }

 if(digitalRead(p4) == HIGH){//derecha

    grados1++;
  
  if(grados1 >= 270){  
    grados1 = 270;
  }
  
  miservo_1.write(grados1);
  delay(10);;
  } 
   if(digitalRead(p5) == HIGH){ //izquierda

    grados1--;
  
  if(grados1 <= 0){ 
    grados1 = 0;
  }
  
  miservo_1.write(grados1);
  delay(10);
  } 
}
