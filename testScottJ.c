#pragma config(Motor,  port1,           rightPush,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           five,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           hDrive,        tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           backLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          leftPush,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[rightPush] = 0;
	motor[leftPush] = 0;
//set all motors to 0

	wait1Msec(1);

//move backward towards fence
	motor[frontLeft] = -127;
	motor[backLeft] = -127;
	motor[frontRight] = -127;
	motor[backRight] = -127;
	wait1Msec(2700);
//stop at fence
	motor[frontLeft] = 0;
	motor[backLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	wait1Msec(1);

//raise tower knock off star
	motor[rightLift] = 127;
	motor[leftLift] = 127;
	wait1Msec(3000);

	motor[leftLift] = 0;
	motor[rightLift] = 0;
	wait1Msec(1);

//move left knock off stars
	motor[hDrive] = 127;
	wait1Msec(3000);

	motor[leftLift] = 0;
	motor[rightLift] = 0;
	motor[hDrive] = 0;
	wait1Msec(1);

	motor[frontLeft] = 127;
	motor[backLeft] = 127;
	motor[frontRight] = 127;
	motor[backRight] = 127;
	wait1Msec(1000);
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
  // User control code here, inside the loop

  while (true)
  {

  //Drive Train
		motor[frontLeft] = vexRT[Ch3];
		motor[frontRight] = vexRT[Ch2];
	//	motor[five] = vexRT[Ch2];  - not using this port
		motor[backLeft] = vexRT[Ch3];
		motor[backRight] = vexRT[Ch2];



//Push arm
		motor[rightPush] = vexRT[Ch3Xmtr2];
		motor[leftPush] = vexRT[Ch3Xmtr2];
//Lift
		motor[rightLift] = vexRT[Ch2Xmtr2];
		motor[leftLift] = vexRT[Ch2Xmtr2];
//hDrive
		//motor[hDrive] = vexRT[Ch2];

		if (vexRT(Btn5U)==1)
		{
			motor[hDrive]=-127;
		}
		else if (vexRT(Btn6U)==1)
		{
			motor[hDrive]=127;
		}
		else
		{
			motor[hDrive]=0;
		}

		}
}

//CHECK H-DRIVE ON 2/15/17
