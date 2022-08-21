#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "EHeIr49wMuUNofS7VDvGx8RzF5nBhnrd";
char ssid[] = "Power3";
char pass[] = "umidigi0809";

BlynkTimer timer;
#define EspSerial Serial
#define ESP8266_BAUD 115200
ESP8266 wifi(&EspSerial);

#include <Servo.h>
#define MAX_SERVO_NUM 8
Servo servo[MAX_SERVO_NUM+1];

const int myDelay = 130; //歩行速度
const int myDelay2 = 200; //trickSpeed
int command10,command11,command12,command13;
int pos_x,pos_y;

BLYNK_WRITE(V1){
  pos_x = param[0].asInt();
  pos_y = param[1].asInt();
  }
BLYNK_WRITE(V10){command10 = param.asInt();}
BLYNK_WRITE(V11){command11 = param.asInt();}
BLYNK_WRITE(V12){command12 = param.asInt();}
BLYNK_WRITE(V13){command13 = param.asInt();}
 
void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, wifi, ssid, pass);
    EspSerial.begin(ESP8266_BAUD);
    timer.setInterval(200,mycontrol);
      
  attachServo();
  detachServo();
}

void mycontrol(){

  if(command10 == 1){
    attachServo();    
       set8Pos(90,   70, 100,  75,  75,  90,  70,  90);    delay(myDelay2);
       set8Pos(180,  70, 100,   0,   0,  90,  70, 180);    delay(myDelay2);
       set8Pos(  0, 180,   0, 180, 180,  20, 160,   0);    delay(myDelay2);
       set8Pos(  0,  70, 100, 180, 180,  90,  70,  10);    delay(myDelay2);

       set8Pos(  0,  70, 100,  75, 180,  90,  70,  10);    delay(myDelay2);
       set8Pos(  0,  70, 100,  75, 180,  90,  70,  90);    delay(myDelay2);
       set8Pos( 90,  70, 100,  75, 180,  90,  70,  90);    delay(myDelay2);
       set8Pos( 90,  70, 100,  75,  75,  90,  70,  90);    delay(myDelay2);
 
       set8Pos(180,  70, 100,  75,  75,  90,  70, 180);    delay(myDelay2);
       set8Pos(180, 180, 100,  75,  75,  90, 180, 180);    delay(myDelay2);
       set8Pos(180, 180, 100,  75,  75,  90, 180, 180);    delay(myDelay2);
       set8Pos(180, 180,   0,   0,   0,   0, 180, 180);    delay(myDelay2);
//
       set8Pos(180, 180,   0,   0, 180,   0, 180,   0);    delay(myDelay2);
       set8Pos(  0, 180,   0, 180, 180,   0, 180,   0);    delay(myDelay2);
 
       set8Pos(  10, 115,  45, 165, 165, 045, 135,   15);    delay(myDelay2);   
    detachServo(); 
}
  else if(command11 == 1){
    attachServo();    
       set8Pos(  15, 115,  45, 165, 165, 045, 135,   15);    delay(myDelay2);
    detachServo();
}
  else if(command12 == 1){
    attachServo();    
    set8Pos(90,180,0,70,70,0,180,90);    delay(myDelay2);
    detachServo();
}
  else if(command13 == 1){
  attachServo();      
        set8Pos(  15, 150,   0, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,  75,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,   0,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,  45,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,   0,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,  75,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,   0,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 150,  45,   0, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos(  15, 115,  45, 165, 170, 045, 135,   15);    delay(myDelay2);

        set8Pos( 180, 180,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 170,  90,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 180, 180,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 170,  90,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 180, 180,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 170,  90,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 180, 180,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
        set8Pos( 170,  90,  45, 165, 165, 045, 90,   15);    delay(myDelay2);    
       
        
        set8Pos(  15, 115,  45, 165, 170, 045, 135,   15);    delay(myDelay2);
    detachServo();
    }

  else if (pos_y > 50 && pos_x < 78 && pos_x > -78) {
   attachServo();
   //        RF1,  Rf2,  Lf2,  Lf1,  Rb1,  Rb2, Lb2,  Lb1 
    set8Pos(    0,   60,   45,  170,  180,  100, 135,  10);   delay(myDelay);
    set8Pos(   60,  165,   45,  170,  165,  100, 135,  15);   delay(myDelay);
    set8Pos(   20,  130,  105,  180,  160,   45, 160,  50);   delay(myDelay); 
    set8Pos(   10,  130,  105,  170,  170,   45,  60,  10);   delay(myDelay);
    set8Pos(   15,  130,   20,  120,  165,   45,  60,  15);   delay(myDelay);
    set8Pos(   0,   55,  045,  150,  130,   10, 135,  20);   delay(myDelay);
    detachServo();
}
  else if (pos_y < -50 && pos_x < 78 && pos_x > -78){
   attachServo();
 //                RF1,  Rf2,  Lf2,  Lf1,  Rb1,  Rb2, Lb2,  Lb1 
        set8Pos(   15,  135,  110,  170,  165,   45,  70,  10);   delay(myDelay);//1
        set8Pos(   15,  135,  110,  170,  165,  045, 150,  60);   delay(myDelay);//2
        set8Pos(   40,  150,   45,  160,  170,  100, 135,  15);   delay(myDelay);//3
        set8Pos(   10,  070,  045,  160,  170,  100, 135,  15);   delay(myDelay);//4
        set8Pos(   10,  070,  045,  160,  110,   20, 135,  15);   delay(myDelay);//5
        set8Pos(   15,  135,  030,  130,  165,   20,  70,  10);   delay(myDelay);//6
   detachServo();
   }
    else if (pos_x > 50 && pos_y < 78 && pos_y > -78){
   attachServo();
//          RF1,  Rf2,  Lf2,  Lf1,  Rb1,  Rb2, Lb2,  Lb1 
    set8Pos( 10, 115,  45, 170, 170, 045, 135,   10);    delay(myDelay);
    set8Pos( 45,  70,  45, 170, 170, 045, 135,   10);    delay(myDelay);
    set8Pos( 10,  70,  45, 170, 170, 045, 135,   10);    delay(myDelay);
    set8Pos( 10,  70,  45, 170, 135,  0 , 135,   10);    delay(myDelay);
    set8Pos( 10,  70,  45, 170, 170,  0 , 135,   10);    delay(myDelay);
    set8Pos( 10,  70,  45, 170, 170,  0 , 135,   45);    delay(myDelay);
    set8Pos( 10,  70,  45, 170, 170,  0 ,  90,   10);    delay(myDelay);
    set8Pos( 10,  70,  45, 150, 170,  0 ,  90,   10);    delay(myDelay);
    set8Pos( 10,  70,  00, 170, 170,  0 ,  90,   10);    delay(myDelay);
    set8Pos( 10, 115,  45, 170, 170, 045, 135,   10);    delay(myDelay);   
   detachServo();
}
  else if (pos_x < -50 && pos_y < 78 && pos_y > -78){
   attachServo();
    //          RF1,  Rf2,  Lf2,  Lf1,  Rb1,  Rb2, Lb2,  Lb1 
    set8Pos( 15, 115,  45, 165, 165, 045, 135,   15);    delay(myDelay);
    set8Pos( 15, 115,  90, 135, 165, 045, 135,   15);    delay(myDelay);
    set8Pos( 15, 115,  90, 165, 165, 045, 135,   15);    delay(myDelay);
    set8Pos( 15, 115,  90, 165, 165, 045, 180,   45);    delay(myDelay);
    set8Pos( 15, 115,  90, 165, 165, 045, 180,   15);    delay(myDelay);
    set8Pos( 15, 115,  90, 165, 135,  90, 180,   15);    delay(myDelay);
    set8Pos( 15, 115,  90, 165, 165,  90, 180,   15);    delay(myDelay);
    set8Pos( 45, 180,  90, 165, 165,  90, 180,   15);    delay(myDelay);
    set8Pos( 15, 180,  90, 165, 165,  90, 180,   15);    delay(myDelay);
    set8Pos( 15, 115,  45, 165, 165,  45, 135,   15);    delay(myDelay);
   detachServo();
   }




/* 指示なし時のPOS
  else if (command3 == 0 && command4 == 0 && command6 == 0 && command7 == 0 && command10 == 0 && command11 == 0 && command12 == 0 && command13 == 0){
    attachServo();
    set8Pos(  15, 115,  45, 165, 165, 045, 135,   15);    delay(300);
    detachServo();
  }
*/
}

void attachServo(){
   // attach Pin to ServoMotor
  servo[1].attach(3);
  servo[2].attach(2);
  servo[3].attach(4);
  servo[4].attach(5);
  servo[5].attach(7);
  servo[6].attach(6);
  servo[7].attach(8);
  servo[8].attach(9);
}
void detachServo(){
  servo[1].detach();
  servo[2].detach();
  servo[3].detach();
  servo[4].detach();
  servo[5].detach();
  servo[6].detach();
  servo[7].detach();
  servo[8].detach();
}
void set8Pos(int a, int b, int c, int d, int e, int f, int g, int h){
  servo[1].write(a);
  servo[2].write(b);
  servo[3].write(c);
  servo[4].write(d);
  servo[5].write(e);
  servo[6].write(f);
  servo[7].write(g);
  servo[8].write(h);
}
void loop() {
   Blynk.run();
   timer.run();
}
