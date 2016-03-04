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


void setup() {
SerialCommunication::USE_SERIAL_COMMUNICATION(); //Turn on serial communication.
I2C::USE_I2C_COMMUNICATION();                    //Turn on i2c transmission.
RemoteControl::SETUP();
GRIPER::SETUP();
pinMode(13, OUTPUT);
//Serial.println("ROBOTICS MANIPULATORS.");
//Serial.println("KING MONGKUT'S UNIVERSITY OF TECHNOLOGY NORTH BANGKOK \n");

//Serial.println("Please select joint to training a robot.");
//Serial.println("or input your code to control robot.");
} 


void loop() {

//---------------  Robot Training  ------------------------  
RemoteControl::READ();                           // Check button state.
RemoteControl::DECISION();                       // TraningRobot.
//---------------  Code Command -------------------------
SerialCommunication::RECEIVE_COMMAND();          //Receive serial data.

if(receivedone == true && griper != true)
{
    for(int i=0;i<6;i++){
       JOINT_READY[i] = false;    
    }  
    training = false;
  
    for(int r=0;r<CommandQuery;r++)
    {
      //Serial.print("CommandNo.");
      //Serial.println(r+1);     
        for(int j=0;j<NumberDevice;j++)
        {
          I2C::I2C_DATA_TRANSMISSION(j,Data[j][r]);
          receivedone = false;
          targetcomplete = false;
        }
     
        //-------  Wait for a joint turned complete ---------   
        for(int R=0;R<NumberDevice;R++)  
        {                                       
         targetcomplete = false;
         while(targetcomplete != true){
              callbackstr = "";
              
              Wire.requestFrom(R, 2);    // request 2 bytes from slave device #R
              if(Wire.available() >= 2)   // if two bytes were received
              {            
                  char callback = Wire.read();
                  callbackstr += callback;
                  //Serial.println(callbackstr);
                  if(callbackstr == "P"){//Complete
                      Serial.print("P");
                      targetcomplete = true;
                      JOINT_READY[R] = true;
                      callbackstr = "";                      
                      //I2C::I2C_DATA_TRANSMISSION(R,"RP");
                  }
                  
                  if(callbackstr == "F"){//Send again.
                      //Serial.println("Sender call : Fail");
                      I2C::I2C_DATA_TRANSMISSION(r,Data[R][r]);
                      R=0;
                       continue;
             }
           }
           
           if(JOINT_READY[0] == true && JOINT_READY[1] == true && JOINT_READY[2] == true && JOINT_READY[3] == true && JOINT_READY[4] == true && JOINT_READY[5] == true)      
           {
                 Serial.print("F");
           }
        
        } 
      }      
    }
  }
  
  
  
  if(training == true){
    
    for(int i=0;i<6;i++){
        
        if(i==0 || i==3 || i==5)
        continue;
      
        I2C::I2C_DATA_TRANSMISSION(i,"ST"); 
    }
    
  }
  
}
