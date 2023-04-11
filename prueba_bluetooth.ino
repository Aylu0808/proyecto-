#include <Servo.h>

/*
 * PRUEBA TOUCH CON SERVOS ¡¡¡¡NO SE PROBO NADA!!!
 * 
 */
//Cada sensor esta simulado con pulsadores hasta que encuentre la libreria para los sensores
#define TTP223_1 A0 //Suma 8 para la izquierda o derecha
#define TTP223_2 A1 //Resta 9 para la derecha o izquierda
#define TTP223_3 A2
#define TTP223_4 A3

int sensorState;

Servo miservo_1; // servo 1 derecha izquierda
Servo miservo_2; //Servo 2 y 3 hacen lo msimo por que es para estabilizacion
Servo miservo_3;//servo 2 y 3 arriab y abajo 

int grados = 90;

void derecha_izquierda();
void arriba_abajo();

void setup() {
  

  pinMode(TTP223_1, INPUT);
  pinMode(TTP223_2, INPUT);
  pinMode(TTP223_3, INPUT);
  pinMode(TTP223_4, INPUT);

  miservo_1.attach(3,750,1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_1.write(grados);

  miservo_2.attach(5,750,1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_2.write(grados);

  miservo_3.attach(6,750,1800); // EL 2 ES EL PIN DONDE ESTA CONECTADO EL 750 ES EL 0 Y EL 1800 POR LOS 180°
  miservo_3.write(grados);

}

void loop() {

  /*int sensorState = digitalRead(TTP223);

  if (sensorState == HIGH){
  digitalWrite(LED, HIGH);
  }
  else{
  digitalWrite(LED,LOW);
}*/

}

void derecha_izquierda(){

  if(digitalRead(TTP223_1) == HIGH){

    grados++;

    if(grados >= 180){ // Protege el sero de no sobreexigirlos 

      grados = 180;
    }
  }
  if(digitalRead(TTP223_2) == HIGH){

    grados--;
    if(grados <= 0){ //Protege el servo

      grados = 0;
    }
  }
  
  miservo_1.write(grados);
  delay(10);
  
}
void arriba_abajo(){

  if(digitalRead(TTP223_3) == HIGH){

    grados++;

    if(grados >= 180){ // Protege el sero de no sobreexigirlos 

      grados = 180;
    }
  }
  if(digitalRead(TTP223_4) == HIGH){

    grados--;
    if(grados <= 0){ //Protege el servo

      grados = 0;
    }
  }
  
  miservo_2.write(grados);
  delay(10);
  
  miservo_3.write(grados);
  delay(10);
}
