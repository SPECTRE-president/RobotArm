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

// I2C COMMUNICATION
// WRITER : H.JATUPON
// AT BANGKOK THAILAND 14-03-15 20:28 PM 
namespace I2C{
  
  void USE_I2C_COMMUNICATION()
  {
    Wire.begin(); // join i2c bus (address optional for master)
  }
    
  void I2C_DATA_TRANSMISSION(short address,String Data){
    
  Wire.beginTransmission(address); // transmit to device #4
  char charBuf[50];
  Data.toCharArray(charBuf, 50);
  Wire.write(charBuf);        // sends five bytes 
  Wire.endTransmission();    // stop transmitting 
  delay(10);
 

      //Serial.print("Transmit data to joint : ");
      //Serial.print(address+1);
      //Serial.print("   Data is :");
      //Serial.println(charBuf);
 
  
  }
  
  
}

// SERIAL COMMUNICATION
// WRITER : H.JATUPON
// AT BANGKOK THAILAND 14-03-15 20:28 PM
// J CODE.
namespace SerialCommunication{
  void USE_SERIAL_COMMUNICATION()
  {
        // put your setup code here, to run once:
        Serial.begin(9600);
   }
  
  void RECEIVE_COMMAND()
  {
      if(Serial.available() > 0)
      {
          for(int loopcount = 0; loopcount < CommandQuery; loopcount ++)
          {
                  //Serial.print("Input your command NO.");
                  //Serial.println(loopcount+1);
                  bool receivedata = true;
                  griper = false;
                  
                  while(receivedata)
                  {
                      if(Serial.available() > 0)
                      {
                            endtransmission = false;
                            // get the new byte:
                            char inChar = Serial.read();
                            //Serial.println(inChar);  
                            
                            if (inChar != ';' && inChar != '#')
                            {
                                inputString += inChar;
                                //Serial.println(inputString);  
                            }
                            //Serial.println(inputString);
                            
                            for(int a=1;a<=NumberDevice;a++)
                            {
                                  String substringvariableA = "J";
                                  substringvariableA += a;
                                
                                  if(inputString == substringvariableA)
                                  {
                                      devicecheck = inputString;
                                      //Serial.print("Joint=>");
                                      //Serial.println(devicecheck);
                                  }
                                
                                  if(devicecheck == substringvariableA)
                                  {
                                      if (inChar == ';') {
                                        //Serial.println("Loop=> ;");
                                        stringComplete = true;
                                        DeviceNO = a;
                                        
                                      }  
                                      if(stringComplete == true)
                                      {
                                        //Serial.println("Loop=> stringComplete");
                                        //Serial.println(i);
                                        Data[DeviceNO-1][loopcount] = inputString;
                                        Data[DeviceNO-1][loopcount] = Data[DeviceNO-1][loopcount].substring(2);
                                        i += 1;
                                        inputString = "";
                                        stringComplete = false;
                                      }    
                                      
                                  }
                            }
                            
                            if(inputString == "DELAY"){
                              
                              delay(1500);
                              Serial.println("F");
                              inputString = "";
                              stringComplete = false;
                               
                              //endtransmission = true;
                              receivedone = true;
                              griper = true;
                              break;
                              
                            }                            
                            
                            if(inputString == "GPON"){
                               
                               GRIPER::ON();
                               Serial.println("F");
                               inputString = "";
                               stringComplete = false;
                               
                               //endtransmission = true;
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "GPOFF"){ 
                               GRIPER::OFF();
                               Serial.println("F");
                               inputString = "";
                               stringComplete = false;
                               
                               //endtransmission = true;
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "TRJ1"){
                               JointControl = 0;
                               //Serial.println("F");
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "TRJ2"){
                               JointControl = 1;
                               //Serial.println("F");
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "TRJ3"){
                               JointControl = 2;
                               //Serial.println("F");
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "TRJ4"){
                               JointControl = 3;
                               //Serial.println("F");
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "TRJ5"){
                               JointControl = 4;
                               //Serial.println("F");
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "TRJ6"){
                               JointControl = 5;
                               //Serial.println("F");
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             if(inputString == "LEARN"){
                               RequestJointPosition();
                               inputString = "";
                               stringComplete = false;                               
                               
                               receivedone = true;
                               griper = true;
                               break;
                             }
                             
                             
                            if (inChar == '#')
                            {
                                //Serial.println(Data[0][0]);
                                //Serial.println("Loop=> #");
                                //Serial.print(loopcount);
                                //Serial.print(" : ");
                                //Serial.println(CommandQuery-1);
                                if(loopcount == CommandQuery-1)
                                {        
                                    //Serial.println("Data lauched");
                                    endtransmission = true;
                                    break;
                                }
                                receivedata = false;
                                continue;
                            }
                  
                     }//if(Serial.available() > 0)
               }//while(receivedata)     
       }//for(loopcount)
   }//if(Serial.available() > 0)

  
    if(endtransmission == true)  //End transmission
    {
        for(int loopcount = 0; loopcount < CommandQuery; loopcount ++)
        {
            //Serial.print("Command No.");
            //Serial.println(loopcount+1);
            for(int a=0;a<NumberDevice;a++)
            {  
              //Serial.print("Joint");
              //Serial.print(a);
              //Serial.print(" Data is =>");
              //Serial.println(Data[a][loopcount]); 
               
            }
            endtransmission = false;
            receivedone = true;    
        }
      }


   }//void RECEIVE_COMMAND()
 
}//END NAMESPACE SERIAL
