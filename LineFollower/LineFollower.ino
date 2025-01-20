//  SAIF UR REHMAN (211275)
//  HAMZA ABRAR KHAN (191041)
//  HASSAN ALI JANJUA (211223)
//  ALI TORAB (211242)


#include <SPI.h>
#include <SD.h>

#define RIN1_DCM1 6
#define RIN2_DCM1 5
#define R_EN_DCM1 3

#define LIN1_DCM2 8
#define LIN2_DCM2 10
#define L_EN_DCM2 9
#define L_SEN 2
#define M_SEN 4
#define R_SEN 7
#define echo A0   //Echo pin
#define trigger A1
long Ultrasonic_read();
void motors_left();
void motors_right();
void motors_forward();
void motors_sharp_right();
void motors_sharp_left();
void motors_stop();
void movement_read();
 
void setup() {
  Serial.begin(9600);
  if (!SD.begin(1)) {
    Serial.println("initialization failed!");
    
  }
  // put your setup code here, to run once:
  pinMode(RIN1_DCM1, OUTPUT);    // sets the digital pin 13 as output
  pinMode(RIN2_DCM1, OUTPUT);    // sets the digital pin 13 as output
  pinMode(R_EN_DCM1, OUTPUT);    // sets the digital pin 13 as output
 
  pinMode(LIN1_DCM2, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LIN2_DCM2, OUTPUT);    // sets the digital pin 13 as output
  pinMode(L_EN_DCM2, OUTPUT);
  pinMode(L_SEN, INPUT);    // sets the digital pin 13 as output
 pinMode(M_SEN, INPUT);    // sets the digital pin 13 as output
 pinMode(R_SEN, INPUT);
   pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
pinMode(trigger, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long distance=Ultrasonic_read();
  long predis;
  if(distance>0){
    predis=distance;
  }
  
   if(distance==0){
    distance=predis;
  }
  
Serial.println(distance);
 movement_read();

  if(distance<=7){
  motors_stop();
} 
else if((digitalRead(M_SEN) == HIGH && digitalRead(L_SEN ) !=HIGH  && digitalRead(R_SEN) != HIGH) || (digitalRead(M_SEN) == HIGH && digitalRead(L_SEN ) == HIGH && digitalRead(R_SEN) == HIGH))
{
      motors_forward();
     
}
else if(digitalRead(R_SEN) == HIGH && digitalRead(M_SEN) != HIGH)
{
      motors_sharp_right();
}
else if(digitalRead(M_SEN) == HIGH && digitalRead(R_SEN) == HIGH)
{
      //motors_forward();
      motors_right();
}
else if(digitalRead(L_SEN ) == HIGH && digitalRead(M_SEN) != HIGH)
{
       motors_sharp_left();


}
else if(digitalRead(M_SEN) == HIGH && digitalRead(L_SEN ) == HIGH
)
{
      //motors_forward();
      motors_left();
}

else{
  motors_stop();
}
}
void motors_forward()
{
     digitalWrite(LIN1_DCM2,HIGH );
     digitalWrite(LIN2_DCM2,LOW );
     analogWrite(L_EN_DCM2, 200);
     
     digitalWrite(RIN1_DCM1, HIGH);
     digitalWrite(RIN2_DCM1, LOW);
     analogWrite(R_EN_DCM1, 200);
}
void motors_sharp_right()
{
     digitalWrite(LIN1_DCM2, HIGH);
     digitalWrite(LIN2_DCM2, LOW);
     analogWrite(L_EN_DCM2, 100);
     
     digitalWrite(RIN1_DCM1, LOW);
     digitalWrite(RIN2_DCM1, HIGH);
     analogWrite(R_EN_DCM1, 70);
}
void motors_sharp_left()
{
     digitalWrite(LIN1_DCM2, LOW);
     digitalWrite(LIN2_DCM2, HIGH);
     analogWrite(L_EN_DCM2, 70);
     
     digitalWrite(RIN1_DCM1, HIGH);
     digitalWrite(RIN2_DCM1, LOW);
     analogWrite(R_EN_DCM1, 100);
}
void motors_left()
{
     digitalWrite(LIN1_DCM2, LOW);
     digitalWrite(LIN2_DCM2, LOW);
     digitalWrite(L_EN_DCM2, LOW);
     
     digitalWrite(RIN1_DCM1, HIGH);
     digitalWrite(RIN2_DCM1, LOW);
     analogWrite(R_EN_DCM1, 80);
     
}
void motors_right()
{
     digitalWrite(LIN1_DCM2, HIGH);
     digitalWrite(LIN2_DCM2, LOW);
     analogWrite(L_EN_DCM2, 80);
     
     digitalWrite(RIN1_DCM1, LOW);
     digitalWrite(RIN2_DCM1, LOW);
     digitalWrite(R_EN_DCM1, LOW);
}
void motors_stop()
{
     digitalWrite(LIN1_DCM2, LOW);
     digitalWrite(LIN2_DCM2, LOW);
     digitalWrite(L_EN_DCM2, LOW);
     
      digitalWrite(RIN1_DCM1, LOW);
     digitalWrite(RIN2_DCM1, LOW);
     digitalWrite(R_EN_DCM1, LOW);
}
long Ultrasonic_read(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  long duration = pulseIn (echo, HIGH);
  return duration * 0.034 / 2;
}
void movement_read(){
   String lmfString = "";
   String lmbString = "";
   String rmfString = "";
   String rmbString = "";
   
  int lmf=map(analogRead(A2),0,1023,0,255);
  
   lmfString+=String(lmf);

File lmfFile = SD.open("lmf.txt", FILE_WRITE);

  // if the file is available, write to it:
  lmfFile.println(lmfString);
    lmfFile.close();

int lmb=map(analogRead(A3),0,1023,0,255);
   lmbString+=String(lmb);

File lmbFile = SD.open("lmb.txt", FILE_WRITE);

  // if the file is available, write to it:
  lmbFile.println(lmbString);
  
    lmbFile.close();
    
int rmf=map(analogRead(A4),0,1023,0,255);
   rmfString+=String(rmf);

File rmfFile = SD.open("rmf.txt", FILE_WRITE);

  // if the file is available, write to it:
  rmfFile.println(rmfString);
    rmfFile.close();
    int rmb=map(analogRead(A5),0,1023,0,255);
   rmbString+=String(rmb);

File rmbFile = SD.open("rmb.txt", FILE_WRITE);

  // if the file is available, write to it:
  rmbFile.println(rmbString);
    rmbFile.close();
    Serial.print(lmfString);
    Serial.print(lmfString);
    Serial.print(lmfString);
    Serial.println(lmfString);
}
