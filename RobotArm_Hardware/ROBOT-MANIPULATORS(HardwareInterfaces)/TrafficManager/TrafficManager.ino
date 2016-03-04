/*
    JATUPON  HONGWEING  MAE
    5701001622132
    KMUTNB
  
    Remote Control
        SW 1 turn CW
        SW 2 turn CCW
        SW 3-8 Select number of a joint to control,from 3 to 8 are a joint 1-6 respectively.

    Command Example.
        J10;J20;J30;J40;J50;#
        J1400;J20;J30;J40;J50;#J1400;J2-400;J3-100;J5400;#
*/

bool stringComplete = false;
bool wrongformat = false;
bool endtransmission = false;
bool receivedone = false;
bool serialcommunicationsuccess = false;
bool targetcomplete = false;
int i=0;
int DeviceNO;
const int CommandQuery = 1;
const int NumberDevice = 6;  // 6 device real situation.
String inputString;
String Data[NumberDevice][CommandQuery];
String devicecheck;
String callbackstr;

#include <Wire.h>


//JOINT
long JOINTPOSITION[6];

/*    Remote Control   */
// --------------------
const short buttonPin[8] = {2,3,4,5,6,7,8,9};     // the number of the pushbutton pin
// variables will change:
short buttonState[8] = {0,0,0,0,0,0,0,0};         // variable for reading the pushbutton status
short JointControl = -1;

short button_count = 0;
short count = 0;
short longpress = 20;

//I2C
bool errorread = false;
bool training = false;


//ALL JOINT CONTROL
bool JOINT_READY[6] = {false,false,false,false,false,false};
bool ALL_JOINT_READY = false;

//GRIPER
bool griper = true;
namespace GRIPER{
  
  void SETUP(){
    pinMode(12, OUTPUT);
  
  }
  void ON(){
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  void OFF(){
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  }
  
}

namespace RemoteControl{
   
    void SETUP(){
          
         for(short i=0;i<8;i++)
         pinMode(buttonPin[i], INPUT);
         
    }
    
    void READ(){  
      
         // read the state of the pushbutton value:
         for(short i=0;i<8;i++)
         buttonState[i] = digitalRead(buttonPin[i]);
         
    }
  
    void DECISION(){
       // check if the pushbutton is pressed.
       // if it is, the buttonState is HIGH:
       for(short i=0;i<8;i++){
           if(i==4)
           continue;
         
           if (buttonState[i] == HIGH) {
             training = true;
             //Serial.println(count);
             if(i==6){                        //TURN CCW  
             
                   TurnCCW();     
                   
             }
                 
             if(i==7){                        //TURN CW
             
                 TurnCW();
               
             }
                 
             if(i==0){                        //Select Joint6       
                     if(button_count == i){
                     count++;
                     
                     if(count > longpress){
                       RequestJointPosition();
                       count = 0;  
                   }
                 }   
                 else {
                    button_count = i;
                    count = 0;                      
                 }  
                 JointControl = 5;
                 //Serial.print("Request  count: ");
                 //Serial.println(count); 
                 delay(100);   
             }
             
             if(i==1){                        //Select Joint5
             
                   if(button_count == i){
                   count++;
                   
                   if(count > longpress){
                       RequestJointPosition();
                       count = 0;  
                   }
                  }
                 else {
                     button_count = i;
                    count = 0; 
                 }  
                 JointControl = 4;
                 //Serial.print("Request  count: ");
                 //Serial.println(count);
                 delay(100); 
             }
             
             if(i==2){                        //Select Joint4            
                     if(button_count == i){
                       count++;                    
                     if(count > longpress){
                       RequestJointPosition();
                       count = 0;  
                   }
                     }
                 else {
                     button_count = i;
                    count = 0; 
                 } 
                 JointControl = 3;
                 //Serial.print("Request count: ");
                 //Serial.println(count); 
                 delay(100); 
             }
             
             if(i==3){                        //Select Joint3
                 if(button_count == i){
                      
                       count++;                     
                       if(count > longpress){
                       RequestJointPosition();
                       count = 0;  
                   }
                 }
                 else {
                     button_count = i; 
                     count = 0;
                 } 
                 JointControl = 2;
                 //Serial.print("Request  count: ");
                 //Serial.println(count); 
                 delay(100); 
             }
             
             if(i==4){                        //Select Joint2
                 if(button_count == i){
                 
                     count++;                     
                    if(count > longpress){
                       RequestJointPosition();
                       count = 0;  
                   }
                 }
                 else {
                     button_count = i; 
                     count = 0;
                 } 
                 JointControl = 1;
                 //Serial.print("Request  count: ");
                 //Serial.println(count);
                 delay(100); 
             } 
             
             if(i==5){                        //Select Joint1

              void(* resetFunc) (void) = 0; //declare reset function @ address 0   
              resetFunc();  //call reset
    
                 if(button_count == i){            
                     count++;                     
                     if(count > longpress){
                       RequestJointPosition();
                       count = 0;  
                   }
                 }
                 else {
                     button_count = i; 
                     count = 0;
                 } 
                 JointControl = 0;
                 //Serial.print("Request  count: ");
                 //Serial.println(count); 
                 delay(100); 
             }
             
             //Request Position From a Joint target
             
             
           }  
            else{ 
             // ELSE, BUTTON HASN'T PRESSED. 
             /*
               ..........
               ..........
             */
            }
         }   
         
    }  
}
