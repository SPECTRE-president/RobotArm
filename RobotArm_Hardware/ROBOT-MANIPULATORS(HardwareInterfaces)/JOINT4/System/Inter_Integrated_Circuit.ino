Inter_Integrated_Circuit Inter_Integrated_Circuit;
void receiveEvent(int howMany)
{
     Inter_Integrated_Circuit.set_inputString("");
     while (Wire.available() > 0) // loop through all but the last
     {
           char c = Wire.read(); // receive byte as a character
           String combine_str = Inter_Integrated_Circuit.return_inputString() += c; 
           Inter_Integrated_Circuit.set_inputString(combine_str);
     }
     Inter_Integrated_Circuit.set_incomingdata(true);
}

void requestEvent()
{
    if(Inter_Integrated_Circuit_Info.datafail == 1)
        Wire.write("P");
               
    if(Inter_Integrated_Circuit_Info.datafail == 2)
        Wire.write("F");
    
    if(Inter_Integrated_Circuit_Info.datafail == 0)
        Wire.write("A");
    
    if(Inter_Integrated_Circuit_Info.datafail == 3){
        String strs = String(StepperMotorInfo.CURRENT_POSITION);
        char charBuf[50];
        strs.toCharArray(charBuf, 50);
        Wire.write(charBuf);
    }
}


