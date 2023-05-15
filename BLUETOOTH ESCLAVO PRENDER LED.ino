///ESCLAVO 
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX
int LED = 13; // LED en el pin 13

void setup() {
  pinMode(LED, OUTPUT); // Configura el pin LED como salida
  BTSerial.begin(9600); // Configura la comunicación serial con el módulo HC-05
}

void loop() {
  if (BTSerial.available()) { // Si se recibe algún dato desde el módulo HC-05
    char c = BTSerial.read(); // Lee el primer byte recibido
    if (c == '1') { // Si el byte es '1'
      digitalWrite(LED, HIGH); // Enciende el LED
    } else if (c == '0') { // Si el byte es '0'
      digitalWrite(LED, LOW); // Apaga el LED
    }
  }
}
