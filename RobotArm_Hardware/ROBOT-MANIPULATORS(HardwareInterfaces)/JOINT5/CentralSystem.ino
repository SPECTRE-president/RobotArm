void setup()
{
  Wire.begin(joint_address);                // join i2c bus with address 
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  pinMode(13,OUTPUT);           // LED TEST
  Serial.begin(9600);           // start serial for output
 
  //Tune the servo feedback
  //Determined by trial and error
  servo.myPID->SetTunings(Kp_cw,Ki_cw,Kd_cw);  //0.1 , 0.15 , 0.05
  servo.setPWMSkip(setPWMSkip_cw);
  servo.setAccuracy(setAccuracy);
  servo.setCurrentPosition(0);
}

void loop()
{  
  Serial.println(servo.getActualPosition());    //show actual positoon.
    
  if(position_update_release != true){  
      datafail = 0;
      requestEvent();
      PositionUpdate(UPDATE_POSITION);
  }else {
      if(hold_position == true){
      PositionUpdate(UPDATE_POSITION);         //Hold Position.
    }  
}
  
//------------------------------- COMMUNICATION ---------------------------------------
  if(incomingdata == true){

  datafail = 0;                                      //For serial communication
 
  if(inputString == "SZ")                            //Set position equal to zero.
  {
    Serial.println("SET ZERO.");
   
    void(* resetFunc) (void) = 0; //declare reset function @ address 0
    
    resetFunc();  //call reset

    
    hold_position = false;
    datafail = 1;
    requestEvent();
     
  }else if(inputString == "ST")                      //Stop motor.
  {
    digitalWrite(13,HIGH);
    MOTOR::BRAKE();
    servo.stop();
    datafail = 1;
    requestEvent();
    
  }else if(inputString == "CW"){
   
   //TURN MOTOR CW OR UPDATE POSITION
   //Serial.println("CW");
   hold_position = false;
   UPDATE_POSITION = servo.getActualPosition();
   MOTOR::CW(train_speed);
   Serial.println(UPDATE_POSITION);
   datafail = 1;
    requestEvent();
    
  }else if(inputString == "AC"){
   
   //TURN MOTOR CWW OR UPDATE POSITION
   //Serial.println("CWW");
   hold_position = false;
   UPDATE_POSITION = servo.getActualPosition();
   MOTOR::CCW(train_speed);
   Serial.println(UPDATE_POSITION);
   datafail = 1;
    requestEvent();
    
  }else if(inputString == "RP"){
   
       datafail = 3;
       requestEvent();  
  datafail = 1;     
    
  }else if(inputString == "TR"){
    
       requestEvent();       
       datafail = 1;
    
  }else if(inputString == "RD"){
    
      requestEvent();       
      datafail = 1;
    
    
  }else {                                            //Move motor to expect position.

    UPDATE_POSITION = inputString.toInt(); 
    digitalWrite(13,LOW);
    reset();
    
  }
  incomingdata = false;
 }
//------------------------------------------------------------------------------------


}//END VOIDLOOP



void reset(){
 position_update_release = false;
}
