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

void TurnCW(){ 
  
  if(JointControl >= 0){
  I2C::I2C_DATA_TRANSMISSION(JointControl,"CW");
  //Serial.println("CW");
  }
}


void TurnCCW(){
  
   if(JointControl >= 0){
   I2C::I2C_DATA_TRANSMISSION(JointControl,"AC");
   //Serial.println("CCW");
   }
   
}

char jointpos;
void RequestJointPosition(){  //Request Position from a joint target. 
  
      for(int h=0;h<6;h++){      
           
            //if(h == 4 || h == 5 || h==3 || h==0 || h==2)
            //    continue;  
              
            //Serial.print("Request position from a joint");
            //Serial.println(h+1);  
            
              
            I2C::I2C_DATA_TRANSMISSION(h,"RP");  //request position.
            Wire.requestFrom(h, 32);    // request 2 bytes from slave device #R    
            while(Wire.available() >= 2)   // if two bytes were received
             {
                  //Serial.println("WAIT CALL BACK");              
                  char callback = Wire.read();

                  //Serial.print(callback);
                 
                  if(callback == 'P' || callback == 'A' || callback == 0){
                    errorread = true;
                    break;
                  }else{
                    errorread = false;
                  }
                 
                  //fillter incoming data.
                  int a = callback;
                  
                  
                  
                  if(a != -1)
                  {
                    callbackstr += callback;                     
                  }
                
             }
             
             if(errorread == true){
              h=h-1;
              continue;  
             }
      
            
            JOINTPOSITION[h] = callbackstr.toInt();
            callbackstr = "";        
      }
      
      for(int i=0;i<6;i++)
      {     
            Serial.print("J");
            Serial.print(i+1);
            Serial.print(JOINTPOSITION[i]); 
            Serial.print(";");
      }
      Serial.print("#");
      count = 0;  
     
}
