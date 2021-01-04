/*
 * Author: @Genozen 01/03/2021
 * This is the arduino code for controlling motorized prosthetic hand using servos
 */

//servo
#include <Servo.h>
Servo serv1; //Thumb
Servo serv2; //Index Finger
Servo serv3; //Middle Finger
Servo serv4; //Ring Finger
Servo serv5; //Pinky Finger

//offset initial servo angles to keep string in tension
int serv1_ang = 0;
int serv2_ang = 0;
int serv3_ang = 0;
int serv4_ang = 0;
int serv5_ang = 60;

int incomingByte = 0; // for incoming serial data

//map key press using ASCII input from serial monitor
int key = 0;
int key1on = 49;
int key2on = 50;
int key3on = 51;
int key4on = 52;
int key5on = 53;
int key6on = 54; //Flex all fingers
int key1off = 113; //q
int key2off = 119; //w
int key3off = 101; //e
int key4off = 114; //r
int key5off = 116; //t

void setup() {
   Serial.begin(9600);
   serv1.attach(2); //attach Thumb to A02
   serv2.attach(3); //attach Index Finger to A03
   serv3.attach(4); //attach Middle Finger to A04
   serv4.attach(5); //attach Ring Finger to A05
   serv5.attach(6); //attach Pinky to A06
//   myservoX.attach(9);  // attaches the servo on pin 9 to the servo object
//   myservoY.attach(8);
   delay(10);
   initializeAllFinger();
}

void loop() {
key = serialRead();
Serial.println(key);
moveFinger(key);
key = 0;

delay(1000);
}

//to keep wires in tension
void initializeAllFinger(){
  serv1.write(serv1_ang);
  serv2.write(serv2_ang);
  serv3.write(serv3_ang);
  serv4.write(serv4_ang);
  serv5.write(serv5_ang);
}

//serious of movements for the fingers
void moveFinger(int n){
  //if input is 0, do nothing
  if(n == 0){
    serv1.write(serv1_ang);
    serv2.write(serv2_ang);
    serv3.write(serv3_ang);
    serv4.write(serv4_ang);
    serv5.write(serv5_ang);
  }
  if(n == 1){
    serv1.write(150);
  }
  if(n == 2){
    serv2.write(140);  
  }
  if(n == 3){
    serv3.write(180);  
  }
  if(n == 4){
    serv4.write(180);  
  }
  if(n == 5){
    serv5.write(360);  
  }
  if(n == 6){
    serv1.write(150);
//    delay(1000);
//    initializeAllFinger();
    serv2.write(140);
//    delay(1000);
//    initializeAllFinger();
    serv3.write(180);
//    delay(1000);
//    initializeAllFinger();
    serv4.write(180);
//    delay(1000);
//    initializeAllFinger();
    serv5.write(360);
//    delay(1000);   
//    initializeAllFinger();
  }
}

//helper function to read which key is pressed
int serialRead(){
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //print which finger is on or off
    if(incomingByte == key1on){
      key = 1; 
    }
    if(incomingByte == key2on){
      key = 2; 
    }
    if(incomingByte == key3on){
      key = 3;  
    }
    if(incomingByte == key4on){
      key = 4; 
    }
    if(incomingByte == key5on){
      key = 5; 
    }
    if(incomingByte == key6on){
      key = 6; 
    }
  }  

  return key;
}
