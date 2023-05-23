///ESCLAVO 10
#include <SoftwareSerial.h>
#include<Servo.h>



Servo miservo_1;
Servo miservo_2;

volatile int grados1 = 0;
volatile int grados2 = 0;
volatile int state = 0;

void setup() {
  
  miservo_1.attach(9, 350, 2900); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados1);//b

  miservo_2.attach(6, 1000, 2000);
  miservo_2.write(grados2);
  
  Serial.begin(57600); // Configura la comunicación serial con el módulo HC-05
}

void loop() {
  if (Serial.available()) { // Si se recibe algún dato desde el módulo HC-05
    
    state = Serial.read(); // Lee el primer byte recibido

    if(state == '1'){//derecha
  
      grados1++;

      miservo_1.write(grados1);
      delay(10);;
    }
    if(state == '2'){//derecha
  
      grados1--;

      miservo_1.write(grados1);
      delay(10);;
    }
    if(state = '3'){

       grados2++;
    
    if(grados2 >= 180){
      grados2 == 180;
    }
    miservo_2.write(grados2);
    delay(10);
  }
  if(state = '4'){
    grados2--;

    if(grados2 <= 0){
      grados2 = 0;
    }
    miservo_2.write(grados2);
    delay(10);
  }
    }
    }
