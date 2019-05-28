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
Servo arriba;
const int S0 = 8;
const int S1 = 9;
const int S2 = 12;
const int S3 = 11;
const int sensorOut = 10;
 
int frequency = 0;
int color=0;

int rojo;
int amarillo;
int verde;


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
   arriba.attach(34);
   digitalWrite(S0, HIGH);
   digitalWrite(S1, LOW);
}
 
void loop() {
  
  arriba.write(0);
  rampa.write(65);
  selector.write(170);
  delay(1000);
  arriba.write(100);
  //delay(200);
  delay(180);
  arriba.write(0);
 
  
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
  //Serial.print("90 grados \n");
  //primero lo pone recto y luego lo gira
  delay(250); 
   switch (color) {
    
    case 1:
    Serial.print("RED");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("Rojo");
    rampa.write(50);
    delay(1200);
    lcd.clear();
    rojo++;
    break;

    
    case 2:
    Serial.print("GREEN");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("Verde");
    rampa.write(65);
    delay(1200);
    lcd.clear();
    verde++;
    break;

    
    case 3:
    Serial.print("YELLOW");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("Amarillo");
    rampa.write(90);
    delay(1200);
    lcd.clear();
    amarillo++;
    break;
    
    
    case 0:
    Serial.print("Color Extra");
    lcd.setCursor(0,0);
    lcd.print ("Color");
    lcd.setCursor(0,1);
    lcd.print ("No Encontrado");
    rampa.write(30);
  }
  delay(300);
  
  color=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("Verde:");
  lcd.print(verde);
  lcd.print("Rojo:");
  lcd.print(rojo);
  lcd.setCursor(0,1);
  lcd.print("Amarillo:");
  lcd.print(amarillo);
  delay(1500);
  lcd.clear();
    

}

int readColor() {
 
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
 
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
 
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
 
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);

  
  if(B<140 &B>90 & R<90 & R>50 ){
    color = 1; // Red  
  }
  if(G<155 & G>95 & R>100 & R<255){
    color = 2; // Green
  }
  if(R<40 & R>20 & G<70 & G>30){
    color = 3; // Yellow
  }
  return color;  
}
