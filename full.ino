//VCC——5V   
//GND——GND
//S0——D3   
//S1——D4
//S2——D5   
//S3——D6
//OUT——D2

#include <Servo.h>


Servo rampa;
Servo selector; 
const int S0 = 8;
const int S1 = 9;
const int S2 = 12;
const int S3 = 11;
const int sensorOut = 10;
 
int frequency = 0;
int color=0;
 
void setup() {
   Serial.begin(9600);
   pinMode(S0, OUTPUT);
   pinMode(S1, OUTPUT);
   pinMode(S2, OUTPUT);
   pinMode(S3, OUTPUT);
   pinMode(sensorOut, INPUT);
   rampa.attach(7);
   selector.attach(6);
   digitalWrite(S0, HIGH);
   digitalWrite(S1, LOW);
}
 
void loop() {
  selector.write(90);
  Serial.print("cero grados \n");
  delay(5000);
  selector.write(35);
  Serial.print("treita y cinco grados \n");
  delay(3000); 

  //selector.write(85);
  color = readColor();
  //delay(5000);
  //selector.write(45);
  //delay(1000);
  selector.write(0);
  Serial.print("90 grados \n");
  //delay(5000);
   switch (color) {
    case 1:
    Serial.print("RED");
    //bottomServo.write(50);
     rampa.write(90);
    delay(5000);
    break;
    case 2:
    Serial.print("ORANGE");
    //bottomServo.write(75);
    break;
    case 3:
   // bottomServo.write(100);
    Serial.print("GREEN");
    break;
    case 4:
    //bottomServo.write(125);
    Serial.print("YELLOW");
    rampa.write(0);
    delay(2000);
    break;
    case 5:
    //bottomServo.write(150);
    Serial.print("BROWN");
    break;
    case 6:
    //bottomServo.write(175);
     Serial.print("BLUE");
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  color=0;

}

int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  //Serial.print("R= ");//printing name
  //Serial.print(frequency);//printing RED color frequency
  //Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  //Serial.print("G= ");//printing name
  //Serial.print(frequency);//printing RED color frequency
  //Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  //Serial.print("B= ");//printing name
  //Serial.print(frequency);//printing RED color frequency
  //Serial.println("  ");
  delay(50);
  if(G<135 & G>110 & B<110 &B>90){
    color = 1; // Red
    
  }
  if(G<55 & G>43 & B<47 &B>35){
    color = 2; // Orange
  }
  if(R<53 & R>40 & G<53 & G>40){
    color = 3; // Green
  }
  if(R<38 & R>24 & G<44 & G>30){
    color = 4; // Yellow
  }
  if(R<56 & R>46 & G<65 & G>55){
    color = 5; // Brown
  }
  if (G<58 & G>45 & B<40 &B>26){
    color = 6; // Blue
  }
  return color;  
}
