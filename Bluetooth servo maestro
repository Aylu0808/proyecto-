#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(10, 11);

int pulsador1 = A0;
int pulsador2 = A1;
int pulsador3 = A2;
int pulsador4 = A3;

volatile int state = 0;

Servo miservo_1; // servo 1 derecha izquierda
Servo miservo_2; // Servo 2 y 3 hacen lo msimo por que es para estabilizacion
Servo miservo_3;

volatile int grados2 = 0;
volatile int grados3 = 0;
volatile int grados1 = 0; 

void setup() {

  pinMode(pulsador1, INPUT);
  pinMode(pulsador2, INPUT);
  pinMode(pulsador3, INPUT);
  pinMode(pulsador4, INPUT);

  BTSerial.begin(11500);

  miservo_3.attach(9, 750, 1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_3.write(grados3);//b 

  miservo_2.attach(5, 750, 1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_2.write(grados2);

  miservo_1.attach(4, 750, 2700); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados1);//b 
}

void loop() {

  if(digitalRead(pulsador1) == HIGH){

    BTSerial.write("1");
    delay(50);
  }
    if(digitalRead(pulsador2) == HIGH){

    BTSerial.write("2");
    delay(50);
  }
    if(digitalRead(pulsador3) == HIGH){

    BTSerial.write("3");
    delay(50);
  }
    if(digitalRead(pulsador4) == HIGH){

    BTSerial.write("4");
    delay(50);
  }
  
}
