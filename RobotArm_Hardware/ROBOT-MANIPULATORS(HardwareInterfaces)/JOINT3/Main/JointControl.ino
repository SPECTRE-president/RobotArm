void PositionUpdate(int positionupdate) {
  
  adaptive_control_gap = positionupdate - servo.getActualPosition(); //Find gap
  
  if(adaptive_control_gap < 0)            //A motor will turn cw.
  {
      //Tune the servo feedback
      //Determined by trial and error
      servo.myPID->SetTunings(Kp_cw,Ki_cw,Kd_cw);  
      servo.setPWMSkip(setPWMSkip_cw);
      servo.setAccuracy(setAccuracy);
  }
  else{                                  //A motor will turn ccw.
      //Tune the servo feedback
      //Determined by trial and error
      servo.myPID->SetTunings(Kp_ccw,Ki_ccw,Kd_ccw); 
      servo.setPWMSkip(setPWMSkip_ccw);
      servo.setAccuracy(setAccuracy);
  }
  
  
  Serial.println(servo.getRequestedPosition());
  //wait 1s before starting
  static unsigned long motor_timeout = millis() + 1000;
  static bool motor_go = 0;

  
  servo.run();

  if (servo.finished()) {
    if(motor_go) {
      //stop disengages the motor feedback system, in which case if you moved the motor, it would fight you if you didn't "stop" it first (provided you were still running servo.run() operations)
      servo.stop();
      motor_timeout = millis() + 1500;
      motor_go = 0;
      
      position_update_release = true;
      hold_position = true;
      datafail = 1;
      requestEvent();
      
    }
    if(motor_timeout < millis()) {
      //Setting a move operation will ensure that servo.finished() no longer returns true
      servo.moveTo(positionupdate);
      motor_go = 1;
    }
  }
  
     
}
