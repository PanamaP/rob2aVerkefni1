
#pragma config(Sensor, dgtl6,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorServoContinuousRotation, openLoop)

// dist/ummalhjol = rotation


int rotation = 563;
int power = 93;
int basedeg = 0;

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

void turn(int deg, int side){
	while(SensorValue[leftEncoder] < deg*basedeg){
	motor[leftMotor] = 127*side;
	motor[rightMotor] = 127*side;
	}
	drive();
}

int nrTurns[14] = {0,1,1,0,0,1,0,0,1,0,0,1,1,0};

task main()
{

  for(int i = 0;i<14;i++){
  	int nr = nrTurns[i];
  	turn(90, nr);
	}

}
