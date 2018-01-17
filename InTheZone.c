#include <vex_recorder.c>
task main() {
	int X2 = 0, Y1 = 0, X1 = 0, Y2 = 0, threshold = 15;
	bool startedRecording = false;
	while(true) {
		if(!startedRecording && vexRT[Btn7U]==1) {
			startTask(record_autonomous);
			startedRecording=true;
		}
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
			} else {
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
		if(vexRT[Btn6U]) {
			X1/=3;
			X2/=3;
			Y1/=3;
			Y2/=3;
		}
		//Remote Control Commands
		motor[port5] = (Y1 - X2 + X1 + Y2);
		motor[port3] =  (Y1 + X2 + X1 + Y2);
		motor[port4] = (Y1 - X2 + X1 - Y2);
		motor[port2] =  (Y1 + X2 + X1 - Y2);

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
