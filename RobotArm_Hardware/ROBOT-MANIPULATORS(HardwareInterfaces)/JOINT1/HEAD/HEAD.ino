#include <Wire.h>

String inputString;
bool incomingdata = false;
short datafail = 3;
short request = 0;   //1 success , 2 fail.
int UPDATE_POSITION;
bool position_update_release = false;


// Blocking.pde
// -*- mode: C++ -*-
//
// Shows how to use the blocking call runToNewPosition
// Which sets a new target position and then waits until the stepper has 
// achieved it.
//
// Copyright (C) 2009 Mike McCauley
// $Id: HRFMessage.h,v 1.1 2009/08/15 05:32:58 mikem Exp mikem $

#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1,6,7); // Defaults to 4 pins on 2, 3, 4, 5


//Training
int ACCURACY_TRAIN = 60;
int SET_MAXSPEED = 500;
int SET_ACCELERATION = 300;
int CONSTANT_SPEED = 1000;

bool MOVE_WITH_ACCELERATION = true;
