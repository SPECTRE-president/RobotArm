void setup() {
    
}

void loop() {
  StepperMotor StepperMotor;
  MotionController MotionController;
  System::Onboard Onboard;
  System::Help Help;
  
  for(;;){
      Serial.println(Inter_Integrated_Circuit.return_inputString()); 
      if(Inter_Integrated_Circuit.return_incomingdata() == true){
                       
            #ifdef HELP
               Help.IncomingData();
            #endif 
            Inter_Integrated_Circuit.set_datafail(0);
      
            if(Inter_Integrated_Circuit.return_inputString() == "SZ")     {
                  #ifdef HELP
                      Help.MotionController_SetZero();
                  #endif  

                  Inter_Integrated_Circuit.set_datafail(1); 
                  requestEvent(); 

                  void(* resetFunc) (void) = 0; //declare reset function @ address 0   
                  resetFunc();
            }
            else if(Inter_Integrated_Circuit.return_inputString() == "CW"){
                 StepperMotorInfo.CURRENT_POSITION += StepperMotorInfo.ACCURACY_TRAIN;
                 MotionController.Control(StepperMotorInfo.CURRENT_POSITION,StepperMotorInfo.CONSTANT_SPEED);     
                 Inter_Integrated_Circuit.set_datafail(1); 
                 requestEvent();
            }
            else if(Inter_Integrated_Circuit.return_inputString() == "AC"){
                 StepperMotorInfo.CURRENT_POSITION -= StepperMotorInfo.ACCURACY_TRAIN;
                 MotionController.Control(StepperMotorInfo.CURRENT_POSITION,StepperMotorInfo.CONSTANT_SPEED);     
                 Inter_Integrated_Circuit.set_datafail(1); 
                 requestEvent();        
            }
            else if(Inter_Integrated_Circuit.return_inputString() == "RP"){
                  #ifdef HELP
                    Help.ReturnPosition();
                  #endif  
                  Inter_Integrated_Circuit.set_datafail(3);
                  Serial.println(Inter_Integrated_Circuit_Info.datafail);
                  requestEvent();
                  Inter_Integrated_Circuit.set_datafail(1);   
                  Serial.println(Inter_Integrated_Circuit_Info.datafail);       
            }
            else{
                  #ifdef HELP
                    Help.MotionController_MotorOn();
                  #endif 
                  StepperMotorInfo.CURRENT_POSITION = Inter_Integrated_Circuit.return_inputString().toInt();
                  MotionController.Control(StepperMotorInfo.CURRENT_POSITION,StepperMotorInfo.CONSTANT_SPEED);
                  Inter_Integrated_Circuit.set_datafail(1); 
                  requestEvent();
            }
      
            Inter_Integrated_Circuit.set_incomingdata(false); 
       }
     
      else{
     
        
      }
  }
      
}
