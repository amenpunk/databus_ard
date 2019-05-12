// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;
Servo servoDos;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(7);
  servoDos.attach(6);
}
 
void loop() {
  servoDos.write(0);
  // Desplazamos a la posición 0º
  delay(100);
  servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  servoDos.write(180);
   delay(100);
  // Desplazamos a la posición 90º
  servoMotor.write(90);
  // Esperamos 1 segundo
  delay(1000);
  servoDos.write(0);
   delay(100);
  // Desplazamos a la posición 180º
  servoMotor.write(180);
   delay(100);
  servoDos.write(180);
  // Esperamos 1 segundo
  delay(1000);
}
