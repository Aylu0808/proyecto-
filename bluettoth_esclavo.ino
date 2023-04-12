#include <Servo.h>

Servo miservo_1; // servo 1 derecha izquierda
Servo miservo_2; //Servo 2 y 3 hacen lo msimo por que es para estabilizacion
Servo miservo_3;//servo 2 y 3 arriab y abajo 

int grados = 90;
int state = 0;

void derecha();
void arriba();
void abajo();
void izquierda();

void setup() {

  Serial.begin(9600);
  
  miservo_1.attach(3,750,1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados);

  miservo_2.attach(5,750,1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_2.write(grados);

  miservo_3.attach(6,750,1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_3.write(grados);

}

void loop() {

  if(Serial.available() > 0){
    
    state = Serial.read();
    Serial.write(state);   
  }

  if(state == '1'){

    grados++;

    if(grados >= 180){ // Protege el sero de no sobreexigirlos 

      grados = 180;  
  }
   miservo_1.write(grados);
  delay(10);
  state = 0;
}
  
  if(state == '2'){

    grados--;
    if(grados <= 0){ //Protege el servo

      grados = 0;
  }
  miservo_1.write(grados);
  delay(10);
}
  if(state == '3'){

    grados++;

    if(grados >= 180){ // Protege el sero de no sobreexigirlos 

      grados = 180;
    }
  miservo_2.write(grados);
  delay(10);
  
  miservo_3.write(grados);
  delay(10);
}
  if(state == '4'){

    grados--;
    if(grados <= 0){ //Protege el servo

      grados = 0;
    }
  miservo_2.write(grados);
  delay(10);
  
  miservo_3.write(grados);
  delay(10);
}
  }
