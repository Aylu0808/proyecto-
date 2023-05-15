//MAESTRO

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX
int LED = 13; // LED en el pin 13
int pulsador = 2; // Pulsador en el pin 2
bool estado_previo = false; // Estado previo del pulsador

void setup() {
  pinMode(LED, OUTPUT); // Configura el pin LED como salida
  pinMode(pulsador, INPUT_PULLUP); // Configura el pin del pulsador como entrada con pull-up
  BTSerial.begin(9600); // Configura la comunicación serial con el módulo HC-05
}

void loop() {
  bool estado_actual = digitalRead(pulsador); // Lee el estado actual del pulsador
  if (estado_actual == LOW && estado_previo == HIGH) { // Si el pulsador ha sido presionado
    digitalWrite(LED, !digitalRead(LED)); // Invierte el estado del LED
    BTSerial.write(digitalRead(LED) ? "1" : "0"); // Envía el estado actual del LED al módulo remoto
    delay(50); // Espera para evitar rebotes del pulsador
  }
  estado_previo = estado_actual; // Guarda el estado previo del pulsador
}
