//Include Encoder and PID_v1 to enable DCMotorServo's usage of them.
//(see: http://stackoverflow.com/questions/6504211/is-it-possible-to-include-a-library-from-another-library-using-the-arduino-ide)
#include <Encoder.h>
#include <PID_v1.h>
#include <DCMotorServo.h>
#include <Wire.h>

namespace MOTOR{
  
  short IN1 = 7;
  short IN2 = 8;
  short PWMEN = 6;

  
  void SETUP()
  {
    pinMode(IN1 , OUTPUT);
    pinMode(IN2 , OUTPUT);
    pinMode(PWMEN, OUTPUT);    
  }
  
  void CW(int pwmcw)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(PWMEN, pwmcw);
  }
  
  void CCW(int pwmccw)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWMEN, pwmccw);
  }
  
  void BRAKE()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(PWMEN, 255);
  }
  
}

String inputString;
bool incomingdata = false;
short datafail = 0;
short int request = 0;   //1 success , 2 fail.
long UPDATE_POSITION;
bool position_update_release = false;

Encoder myEnc(3, 2);  //JOINT 5ONLY , other 2,3
long oldPosition  = -999;

bool hold_position = true;
int train_speed = 200;

#define pin_dcmoto_dir1 7
#define pin_dcmoto_dir2 8
#define pin_dcmoto_pwm_out 6
#define pin_dcmoto_encode1 3      //J2 2 , J3 3
#define pin_dcmoto_encode2 2      //J2 3 , J3 2

DCMotorServo servo = DCMotorServo(pin_dcmoto_dir1, pin_dcmoto_dir2, pin_dcmoto_pwm_out, pin_dcmoto_encode1, pin_dcmoto_encode2);

double Kp_cw = 0.1;
double Ki_cw = 0.5;
double Kd_cw = 0.0;

double Kp_ccw = 0.1;
double Ki_ccw = 1;
double Kd_ccw = 0.05;

int   adaptive_control_gap = 0;
short setAccuracy = 10;
int   setPWMSkip_cw  = 0;
int   setPWMSkip_ccw  = 50;

short joint_address = 4; // joint_address + 1 = JOINT NO.

