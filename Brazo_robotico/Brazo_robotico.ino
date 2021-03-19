/*  AnalogReadSerial  Reads an analog input on pin 0, prints the result to the serial monitor.  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground. This example code is in the public domain. */
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  while(analogRead(A0)){
      int sensorValue = analogRead(A0);
      Serial.println(sensorValue);
      if(sensorValue < 530){
        myservo.write(0);
      }else if (sensorValue > 600){
        myservo.write(180);
      }else if (sensorValue >= 530 && sensorValue <= 600){
      sensorValue = map(sensorValue, 530, 600, 0, 180);
      myservo.write(sensorValue);}
 // }
//  else{
  //  myservo.write(0);
  //}
  }
  delay(50);        // delay in between reads for stability
}
