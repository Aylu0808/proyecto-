#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

volatile int state = 0;

Servo miservo_1; // servo 1 derecha izquierda
Servo miservo_2; // Servo 2 y 3 hacen lo msimo por que es para estabilizacion
Servo miservo_3;

volatile int grados2 = 0;
volatile int grados3 = 0;
volatile int grados1 = 0; 

void izquierda();
void derecha();

void setup() {
  
  miservo_3.attach(9, 1000, 2000); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_3.write(grados3);//b 

  miservo_2.attach(5, 1000, 2000); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_2.write(grados2);

  miservo_1.attach(4 , 1000, 2000); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados1);//b 

  BTSerial.begin(9600);
}

void loop() {

  if(BTSerial.available()){

    state = BTSerial.read();
    
    if(state == "1"){
      izquierda();
    }
    if (state == "2"){
          derecha();
        }
    if(state == "3"){

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
  if(state == "4"){

    grados2--;
    if(grados2 >= 0){

      grados2 = 0;
    }
    miservo_2.write(grados2);
    delay(10);
  }
  if(state == "5"){
    
    grados3++;
    
    if(grados3 <= 30){
      
      grados3 = 30;
    }
    miservo_3.write(grados3);
    delay(10);
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
