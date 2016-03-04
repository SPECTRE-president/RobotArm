#include <Wire.h>

String inputString;
bool incomingdata = false;
short datafail = 0;
short int request = 0;   //1 success , 2 fail.
int UPDATE_POSITION;
bool position_update_release = false;


//----------------------  ENCODER  ----------------------------
/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);  //JOINT 5ONLY , other 2,3
//   avoid using pins with LEDs attached
long oldPosition  = -999;
//-------------------------------------------------------------

int output = 30;

//----------------------  MOTOR ------------------------------
//Motor pin
short IN1 = 7;
short IN2 = 8;
short PWMEN = 6;

int speed_motor = 200;
bool hold_position = true;
int train_speed = 100;
int auto_pid_range = 1;
int accuracy_error = 20;
int RTH_SPEED = 200;
bool RTH = false;
int safe_speed_range = 180;
int safe_speed_range_cw = 105;
int RTH_SPEED_SAFE = 140;
int RTH_HIGH_SPEED = 220;

int cw_motion = 35;
int cw_soft = 35;
int cw_softest = 35;
int cw_speed = 35;


namespace MOTOR{
  void SETUP()
  {
    pinMode(IN1 , OUTPUT);
    pinMode(IN2 , OUTPUT);
    pinMode(PWMEN, OUTPUT);    
  }
  
  void CW2(int pwmcw)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(PWMEN, pwmcw);
  }
  
  void CCW2(int pwmccw)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWMEN, RTH_SPEED);
  }
   void CCW_T(int pwmccw)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWMEN, 255);
  }
  void CW_T(int pwmcw)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(PWMEN, pwmcw);
  }
  
  void CW(int pwmcw)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(PWMEN, pwmcw);
  }
  
  void CCW()
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWMEN, RTH_SPEED);    
  }
  
  void BRAKE()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(PWMEN, output);
  }
}

//-------------------------------------------------------------


// COMMUNICATION
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  inputString = "";
  while (Wire.available() > 0) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    inputString += c; 
  }
  incomingdata = true;
}

void requestEvent()
{
  if(datafail == 1){
  Wire.write("P");
  //Serial.println("PPPPPP");
  }
  
  if(datafail == 2)
  Wire.write("F");
  
  if(datafail == 0)
  Wire.write("A");
  
  if(datafail == 3){
   String Data = String(UPDATE_POSITION);
   char charBuf[50];
   Data.toCharArray(charBuf, 50);
   Wire.write(charBuf);
   Serial.print("SEND POSITION : ");
   Serial.println(charBuf); 
   delay(1000);
  }  
 
}


void reset(){
  
 position_update_release = false;

}

void PositionUpdate_setup()
{     
  Serial.begin(9600);
}

void PositionUpdate(int positionupdate)
{   
    //---------- ENCODER (INPUT) ---------------
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    //Serial.println(newPosition);
  }  
  
  int setpoint = positionupdate;
  //gap
  double gap = abs(setpoint-newPosition); //distance away from setpoint
  
  if(gap <= safe_speed_range){
    
    RTH_SPEED = RTH_SPEED_SAFE;
    cw_speed = cw_soft;
    
  }else if(gap <= safe_speed_range_cw){
    
    cw_speed = cw_softest;
    
  }else{
   
   RTH_SPEED = RTH_HIGH_SPEED;
   cw_speed = cw_motion;
    
  }
  
  if(newPosition > setpoint)
  {
      if(gap > auto_pid_range){
        if(RTH == false){
        MOTOR::CW2(cw_speed);
        }else if(RTH == true){
          
          MOTOR::CW2(cw_speed);      
        }
        
      }else{

      if(RTH == false){
        MOTOR::CW(cw_speed);
        }else if(RTH == true){
          
          MOTOR::CW2(cw_speed);
          
        }
      
      
      }
  }
  if(newPosition< setpoint)
  {      
      if(gap > auto_pid_range){
        
       
       if(RTH == false){
       MOTOR::CCW2(speed_motor); 
        }else if(RTH == true){
          
          MOTOR::CCW2(RTH_SPEED);
          
        }
       
       
      }else{
     
      if(RTH == false){
        MOTOR::CCW();
        }else if(RTH == true){
          
          MOTOR::CCW2(RTH_SPEED);
          
        }
      
      
      
      }
  } 
  
  if(gap <= accuracy_error)
  {
      MOTOR::BRAKE();
      position_update_release = true;
      hold_position = true;
      RTH = false;
      datafail = 1;
      requestEvent();
  }
    
}



void setup()
{
  Wire.begin(1);                // join i2c bus with address 
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  pinMode(13,OUTPUT);           // LED TEST
  Serial.begin(9600);           // start serial for output
  
  PositionUpdate_setup();       // Motion controller
  MOTOR::SETUP();               // Initial motor
}

void loop()
{ 
  //Serial.print("safe range:"); 
  //Serial.println(safe_speed_range);
  if(position_update_release != true){  
      datafail = 0;
      requestEvent();
      PositionUpdate(UPDATE_POSITION);
  }else {
      if(hold_position == true)
      PositionUpdate(UPDATE_POSITION);         //Hold Position.
  }
  
//------------------------------- COMMUNICATION ---------------------------------------
  if(incomingdata == true){
    
  //Reset  
  datafail = 0;
   
  //Serial.print("Incoming data is => ");
  //Serial.println(inputString);
  //Serial.println("MANUAL MODE !");
  //Serial.println("YOU CAN CONTROL THE ROBOT BY USING A REMOTE OR A SOFTWARE");
  
  if(inputString == "SZ")                            //Set position equal to zero.
  {
    Serial.println("SET ZERO.");
    myEnc.write(0); 
    UPDATE_POSITION = 0;
    
    void(* resetFunc) (void) = 0; //declare reset function @ address 0
    
    resetFunc();  //call reset

    
    datafail = 1;
    requestEvent();
     
  }else if(inputString == "ST")                      //Stop motor.
  {
    digitalWrite(13,HIGH);
    MOTOR::BRAKE();
    datafail = 1;
    requestEvent();
    
  }else if(inputString == "CW"){
   
   //TURN MOTOR CW OR UPDATE POSITION
   //Serial.println("TURN CW");
   hold_position = false;
   UPDATE_POSITION = myEnc.read();
   MOTOR::CW2(train_speed);
   Serial.println(UPDATE_POSITION);
   datafail = 1;
    requestEvent();
    
  }else if(inputString == "AC"){
   
   //TURN MOTOR CWW OR UPDATE POSITION
   //Serial.println("TURN CCW");
   hold_position = false;
   UPDATE_POSITION = myEnc.read();
   MOTOR::CCW_T(train_speed);
   Serial.println(UPDATE_POSITION);
   datafail = 1;
    requestEvent();
    
  }else if(inputString == "RP"){
   
       datafail = 3;
       requestEvent();       
       datafail = 1;
    
  }else if(inputString == "TR"){
    
       RTH = true;
      requestEvent();       
       datafail = 1; 
    
  }else if(inputString == "RD"){
    
      RTH = false;
      requestEvent();       
       datafail = 1;
    
    
  }else {                                            //Move motor to expect position.
    //speed_motor = 255;
    UPDATE_POSITION = inputString.toInt(); 
    digitalWrite(13,LOW);
    reset();
    
  }
  incomingdata = false;
  }
//------------------------------------------------------------------------------------


}//END VOIDLOOP


