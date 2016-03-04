void setup()
{
  Wire.begin(5);                // join i2c bus with address 
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  pinMode(13,OUTPUT);           // LED TEST
  Serial.begin(9600);           // start serial for output
  
  JointSetup();                 // Initial motor
}

void loop()
{  
  if(position_update_release != true){  
      if(datafail != 3){
      datafail = 0;
      requestEvent();
      //datafail = 100;
      }
      //Serial.println("UPDATE MODE");    
      PositionUpdate(UPDATE_POSITION);
  }else {
      //Serial.println("HOLD MODE"); 
      PositionUpdate(UPDATE_POSITION);         //Hold Position.
      if(datafail != 3){
        datafail = 1;
        requestEvent();
        //datafail = 100;
      }
  }
  
//------------------------------- COMMUNICATION ---------------------------------------
  if(incomingdata == true){
    
  //Reset  
  if(inputString != "RP")  //fillter
  datafail = 0;
   
  Serial.print("Incoming data is => ");
  Serial.println(inputString);
  
  if(inputString == "SZ")                            //Set position equal to zero.
  {
    Serial.println("SET ZERO.");
    stepper.setCurrentPosition(0);
    UPDATE_POSITION = 0;
    
    datafail = 1;
    requestEvent();
     
  }else if(inputString == "ST")                      //Stop motor.
  {
    digitalWrite(13,HIGH);
    datafail = 1;
    requestEvent();
    
  }else if(inputString == "CW"){
   
   //TURN MOTOR CW OR UPDATE POSITION
   Serial.println("CW");
   UPDATE_POSITION += ACCURACY_TRAIN;
   datafail = 1;
    requestEvent();
    
  }else if(inputString == "AC"){
   
   //TURN MOTOR CWW OR UPDATE POSITION
   Serial.println("CWW");
   UPDATE_POSITION -= ACCURACY_TRAIN;
   datafail = 1;
    requestEvent();
    
  }else if(inputString == "RP"){
   
       datafail = 3;
       requestEvent();
       datafail = 1;
    
  }else if(inputString == "SI"){   //Speed Increase     
       
       CONSTANT_SPEED += 200;
       
       if(CONSTANT_SPEED >= 3200)
       CONSTANT_SPEED = 3200;
       
       datafail = 1;
    requestEvent();
    
  }else if(inputString == "SD"){   //Speed Decrease
    
       CONSTANT_SPEED -= 200;
       
       if(CONSTANT_SPEED <= 0)
       CONSTANT_SPEED = 100;
       
       datafail = 1;
    requestEvent();
    
  }else if(inputString == "PI"){    //Increase Precision move
    
       ACCURACY_TRAIN  += 20;
       
       if(ACCURACY_TRAIN >= 1000)
          ACCURACY_TRAIN = 1000;
          
          datafail = 1;
    requestEvent();
    
  }else if(inputString == "PD"){    //Decrease Precision move
    
       ACCURACY_TRAIN  -= 20;
       
       if(ACCURACY_TRAIN <= 0)
          ACCURACY_TRAIN = 1;
          
          datafail = 1;
    requestEvent();
       
    
  }else if(inputString == "AM"){    //Turn with Acceleration
    
    MOVE_WITH_ACCELERATION = true;
    datafail = 1;
    requestEvent();
    
  }else if(inputString == "NM"){    //Turn without Acceleration(Constant)
    
    MOVE_WITH_ACCELERATION = false;
    datafail = 1;
    requestEvent();
    
  }else {                                            //Move motor to expect position.
  
    UPDATE_POSITION = inputString.toInt(); 
    digitalWrite(13,LOW);
    reset();

  }
  incomingdata = false;
  }
//------------------------------------------------------------------------------------


}//END VOIDLOOP
