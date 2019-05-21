//GND——GND
//S0——D3   
//S1——D4
//S2——D5   
//S3——D6
//OUT——D2


#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(32, 30, 28, 26, 24, 22);

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
  lcd.begin(16,2);
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
  
  rampa.write(90);
  selector.write(170);
  
  Serial.print("Esperando Esfera\n");
  lcd.setCursor(0,0);
  lcd.print ("Esperando Esfera");
  delay(4000);
  lcd.clear();
  
  selector.write(110);
  Serial.print("Leyendo Color\n");
  lcd.setCursor(0,0);
  lcd.print ("Leyendo Color");
  delay(3000);
  lcd.clear();

  color = readColor();
  
  selector.write(80);
  Serial.print("90 grados \n");
   switch (color) {
    
    case 1:
    Serial.print("RED");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("Rojo");
    rampa.write(40);
    delay(1200);
    lcd.clear();
    break;

    
    case 2:
    Serial.print("GREEN");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("Verde");
    rampa.write(120);
    delay(1200);
    lcd.clear();
    break;

    
    case 3:
    Serial.print("YELLOW");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("Amarillo");
    rampa.write(160);
    delay(1200);
    lcd.clear();
    break;
    
    
    case 0:
    Serial.print("Color Extra");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("No Encontrado");
    rampa.write(80);
    delay(1200);
    lcd.clear();
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

  
  if(G<135 & G>110 & B<135 &B>90 & R<70 & R>50 ){
    color = 1; // Red  
  }
  if(R<135 & R>120 & G<120 & G>95 & B>80 & B<125){
    color = 2; // Green
  }
  if(R<38 & R>24 & G<44 & G>30){
    color = 3; // Yellow
  }
  return color;  
}
