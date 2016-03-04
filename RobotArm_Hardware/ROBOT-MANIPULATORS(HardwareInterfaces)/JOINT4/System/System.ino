#include <Wire.h>
#include <Stepper.h>

#define HELP

struct StepperMotorInfo{

        long   CURRENT_POSITION;
        int    ACCURACY_TRAIN = 5000;
        int    CONSTANT_SPEED = 500;
        const int stepsPerRevolution = 12800; 
        
        struct stepper_motor_pin{
          
          enum pin{clk = 7 , dir = 6};  
            
        }stepper_motor_pin;
  
}StepperMotorInfo;
Stepper myStepper(StepperMotorInfo.stepsPerRevolution, StepperMotorInfo.stepper_motor_pin.clk,StepperMotorInfo.stepper_motor_pin.dir);

struct Inter_Integrated_Circuit_Info{
  
        enum  Address{AddressJ4 = 3};
        short  datafail = 3;
         
}Inter_Integrated_Circuit_Info;

struct System_Info{
        enum System{Light_emitting_diode_onboard_pin = 13};  
}System_Info;

class StepperMotor
{
    private:
        long      last_position = 0;      
        int       position_mod_calculate = 0;
        int       position_repeat_calculate = 0;
        int       direction_of_stepper = StepperMotorInfo.stepsPerRevolution;
    
    public:
        void set_last_position(long last_position_set){
             last_position = last_position_set;
        }
        long return_last_position(){
              return last_position;
        }
        void set_position_mod_calculate(int position_mod_calculate_set){
              position_mod_calculate = position_mod_calculate_set;
        }
        int return_position_mod_calculate(){
              return position_mod_calculate;
        }
        void set_position_repeat_calculate(int position_repeat_calculate_set){
              position_repeat_calculate = position_repeat_calculate_set;
        }
        int return_position_repeat_calculate(){
              return  position_repeat_calculate;
        }
        void set_direction_of_stepper(int direction_of_stepper_set){
              direction_of_stepper = direction_of_stepper_set;
        }
        int return_direction_of_stepper(){
              return direction_of_stepper;
        }
        
};

class Inter_Integrated_Circuit
{
    public:
        Inter_Integrated_Circuit(){
            Wire.begin(Inter_Integrated_Circuit_Info.AddressJ4);                // join i2c bus with address 
            Wire.onReceive(receiveEvent); // register event
            Wire.onRequest(requestEvent); // register event      
        }

    private:
        short  request = 0;   //1 success , 2 fail.    
        String inputString;
        bool   incomingdata;

    public:
        void set_datafail(short mode){
              Serial.print("datafail change to ");Serial.println(mode);
              Inter_Integrated_Circuit_Info.datafail = mode;
        }
        void set_request(short request_set){
              request = request_set;
        }
        void set_inputString(String String_set){
              inputString = String_set;
        }
        String return_inputString(){
              return inputString;
        }
        void set_incomingdata(bool incomingdata_set){
              incomingdata = incomingdata_set;
        }
        bool return_incomingdata(){
              return incomingdata; 
        }
};


class MotionController  :public StepperMotor
{ 
      public:
          void Control(long step_to_go,int speed_rm) {
                  long gap = step_to_go - return_last_position();
                  Serial.print("LAST POS:");                  
                  Serial.println(return_last_position());           
                  
                  myStepper.setSpeed(1000);
                  myStepper.step(gap);
                  set_last_position(step_to_go);
                  StepperMotorInfo.CURRENT_POSITION = return_last_position();
      
           }
};

namespace System{
      class Help :public Inter_Integrated_Circuit{  
        public:
              #ifdef HELP
                  Help(){
                       Serial.begin(9600);
                       Serial.println("KING MONGKUT'S UNIVERSITY OF TECHNOLOGY NORTH BANGKOK.");
                       Serial.println("INDUSTRIAL ROBOT FOR SME. \n");        
                  }
                  void IncomingData(){
                       Serial.print("INCOMING DATA: ");  Serial.println(return_inputString());
                  }
                  void MotionController_SetZero(){
                       Serial.println("MOTION CONTROLLER: SET ZERO.");
                  }
                  void ReturnPosition(){
                        Serial.println("SYSTEM: RETURN POSITION.");
                  }
                  void MotionController_MotorOn(){
                        Serial.println("MOTION CONTROLLER: MOTOR ON.");
                  }
              #endif 
                   
      };

      class Onboard{
        public:
              Onboard(){
                  pinMode(System_Info.Light_emitting_diode_onboard_pin,OUTPUT);
              }
      };
}
