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
  Serial.print("SEND CURRENT POSTION : ");
  Serial.println(stepper.currentPosition());
  String strs = String(stepper.currentPosition());
  char charBuf[50];
  strs.toCharArray(charBuf, 50);
  Wire.write(charBuf);
  
  }
  
}
