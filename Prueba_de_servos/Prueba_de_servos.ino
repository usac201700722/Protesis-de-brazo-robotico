/*  AnalogReadSerial  Reads an analog input on pin 0, prints the result to the serial monitor.  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground. This example code is in the public domain. */
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
Servo myservo2;

int potenciometro_1 = 0;  // Pin usado para conectar el potenciómeto
int valor_potenciometro_1;    // Esta variable definirá la posición del servo
int valor_potenciometro_2;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(9);  // SERVOMOTOR PARA EL PULGAR Y EL INDICE
  myservo2.attach(10);  //SERVOMOTOR PARA ANULAR, MEÑIQUE Y EN MEDIO
}

// the loop routine runs over and over again forever:
void loop(){
valor_potenciometro_1 = analogRead(potenciometro_1);
valor_potenciometro_2 = analogRead(potenciometro_1);
valor_potenciometro_1 = map(valor_potenciometro_1, 0, 1023, 180, 0);
valor_potenciometro_2 = map(valor_potenciometro_2, 0, 1023, 0, 180);
Serial.println(valor_potenciometro_1);
Serial.println(valor_potenciometro_2);
myservo.write(valor_potenciometro_1);
myservo2.write(valor_potenciometro_2);

delay(10);  // Esperamos para reiniciar el bucle
}
