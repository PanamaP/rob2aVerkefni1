
#pragma config(Sensor, dgtl6,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorServoContinuousRotation, openLoop)

int rotation = 563;
int power = 93;

void drive(){
	wait1Msec(500);
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

	while(abs(SensorValue[leftEncoder]) < (rotation))
  {
    motor[rightMotor] = power;
    motor[leftMotor] = -power;

  }

}
// 0 = right turn, 1 = left turn
void turn(int side){
	wait1Msec(500);
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

		if(side == 0){
			while(abs(SensorValue[leftEncoder]) < (rotation))
		  {
		    motor[rightMotor] = -power;
		    motor[leftMotor] = -power;

		  }
	}	else if(side == 1){
		   while(abs(SensorValue[rightEncoder]) < (rotation))
		  {
		    motor[rightMotor] = power;
		    motor[leftMotor] = power;

		  }

		}
	drive();
}


int nrTurns[14] = {0,1,1,0,0,1,0,0,1,0,0,1,1,0};

task main()
{

  drive();
  turn(0);
  drive();
  turn(1);
	/*
  for(int i = 0;i<14;i++){
  	int nr = nrTurns[i];
  	turn(nr);
	}*/

}
