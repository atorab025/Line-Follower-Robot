

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define outPin 4
#define sendsig 11

 void vcdisp();
 void readRGB();
 void colordetect();
 int red = 0;
int green = 0;
int blue = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.init();
lcd.backlight();
pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sendsig, OUTPUT);
  pinMode(outPin, INPUT);

  
   digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
vcdisp(); 
colordetect();
}
void vcdisp(){
float voltage = 0.0, vin = 0.0, vout = 0.0, volsensorval = 0.0;
  float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, curin = 0.0;
  const float factor = 5.128, vcc = 5.0;

  AcsValue = analogRead(A1);
  volsensorval = analogRead(A0);

  vout = (volsensorval / 1023.0) * vcc;
  vin = vout * factor;

  curin = (2.5 - (AcsValue * (5.0 / 1024.0))) / 0.185;

  // Clear the display
  lcd.clear();

  // Display voltage
  lcd.setCursor(0, 0);
  lcd.print("V= ");
  lcd.print(vin);
  lcd.print("V");

  // Display current below voltage
  
  lcd.print("C= ");
  lcd.print(curin);
  lcd.print("A");

  delay(1000);}
  void readRGB(){

  
  
  
    //read red component
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    red =  pulseIn(outPin, LOW);
  
   //read green component
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    green = pulseIn(outPin, LOW);
    
   //let's read blue component
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blue =pulseIn(outPin, LOW);
  
 
}
void colordetect(){
readRGB();
lcd.setCursor(0, 1);
  
if(red<blue && red<green && red<25){
  lcd.print("Color detected : RED ");
    Serial.print("Color detected : RED\n\tFrequency: ");
    Serial.println(red);
    delay(100);
  }
  else if(blue < red && blue < green && blue<25) {
    lcd.print("Color detected : BLUE ");
    Serial.print("Color detected : BLUE\n\tFrequency: ");
    Serial.println(blue);
    delay(100);
  }
  else if (green < red && green < blue && green<25) {
    lcd.print("Color detected : GREEN ");
    Serial.print("Color detected : GREEN\n\tFrequency: ");
    Serial.println(green);
    delay(100);
  }  
  else {
    Serial.print("NO COLOR DETECTED\n");
    Serial.println(red);
    Serial.println(blue);
    Serial.println(green);
    delay(100);
  }


}
