/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the auto211nomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	int X2 = 0, Y1 = 0, X1 = 0, Y2 = 0, threshold = 15;
	while(true) {
			//Create "deadzone" for Y1/Ch3
			if(abs(vexRT[Ch2]) > threshold) {
				Y1 = -vexRT[Ch2];
			}
			else {
				Y1 = 0;
			}
			//Create "deadzone" for X1/Ch4
			if(abs(vexRT[Ch1]) > threshold) {
				X1 = -vexRT[Ch1];
			}
			else {
				X1 = 0;
			}
			//Create "deadzone" for X2/Ch1
			if(abs(vexRT[Ch4]) > threshold){
				X2 = vexRT[Ch4];
			}
			else {
				X2 = 0;
			}
			//Create "deadzone" for X2/Ch1
			if(abs(vexRT[Ch3]) > threshold) {
				Y2 = vexRT[Ch3];
			}
			else {
				Y2 = 0;
			}
			//Slow down movement
			if(vexRT[Btn6U]) {
				X1/=3;
				X2/=3;
				Y1/=3;
				Y2/=3;
			}
			//Remote Control Commands
			motor[port5] = Y1 - X2 + X1 + Y2;
			motor[port3] =  Y1 + X2 + X1 + Y2;
			motor[port4] = Y1 - X2 + X1 - Y2;
			motor[port2] =  Y1 + X2 + X1 - Y2;
			//Lift
			if(vexRT[Btn8U]) {
				motor[port6]=127;
				motor[port7]=127;
				motor[port8]=-127;
				motor[port10]=127;
			}
			else if(vexRT[Btn8D]) {
				motor[port6]=-127;
				motor[port7]=-127;
				motor[port8]=127;
				motor[port10]=-127;
			}
			else {
				motor[port6]=0;
				motor[port7]=0;
				motor[port8]=0;
				motor[port10]=0;
			}
			//Claw
			if(vexRT[Btn6D]) {
				motor[port9]=-127;
			}
			else if(vexRT[Btn5D]) {
				motor[port9]= 127;
			}
			else {
				motor[port9]=0;
			}
	}
}
