void JointSetup()
{     
    stepper.setMaxSpeed(SET_MAXSPEED);
    stepper.setAcceleration(SET_ACCELERATION);
}

void PositionUpdate(int positionupdate)
{   
    //if(!(positionupdate > 1500 || positionupdate < 0))
        //stepper.runToNewPosition(positionupdate); 
    
    if(MOVE_WITH_ACCELERATION == false){    //Move without acceleration.  
          stepper.moveTo(positionupdate);
          while(stepper.distanceToGo() != 0){
            
                if(stepper.currentPosition() > positionupdate){
                    stepper.setSpeed(-CONSTANT_SPEED);
                    stepper.runSpeed();
                }
                
                if(stepper.currentPosition() < positionupdate){
                    stepper.setSpeed(CONSTANT_SPEED);
                    stepper.runSpeed();
                }
            
          }
              
          Serial.print("POSITION J6 : ");  
          Serial.print(stepper.currentPosition());
          Serial.print(" , Speed J6 : "); 
          Serial.println(CONSTANT_SPEED);
    }
    
    else if(MOVE_WITH_ACCELERATION == true){
      
              stepper.setMaxSpeed(SET_MAXSPEED);
              stepper.setAcceleration(SET_ACCELERATION);
              stepper.runToNewPosition(positionupdate);   
              
              Serial.print("POSITION J6 : ");  
              Serial.print(stepper.currentPosition());
              Serial.print(" , Maximum Speed J6 : "); 
              Serial.print(SET_MAXSPEED);
              Serial.print(" , Acceleration J6 : "); 
              Serial.println(SET_ACCELERATION);
    }   
    
    if(stepper.distanceToGo() == 0)
    position_update_release = true;
    
}
