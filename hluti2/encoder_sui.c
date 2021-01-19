
#pragma config(Sensor, dgtl6,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorServoContinuousRotation, openLoop)

/* Program which makes your robot go forward and backwards by increment of 0.5m each time until 2.5m*/

// circumference = diameter of wheel x pi
// 10.16 * pi = 31.9


// distance = circumference x number of revolutions
// 50/32 =  1.56 * 360 = 563


int rotation = 563;
int power = 126;

void drive(int dist){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

	while(abs(SensorValue[leftEncoder]) < (rotation*dist))
  {
    motor[rightMotor] = power;
    motor[leftMotor] = -power;

  }
  while(abs(SensorValue[leftEncoder]) > 0)
  {
    motor[rightMotor] = -power;
    motor[leftMotor] = power;

  }
}

task main()
{
  for(int i = 0; i<6;i++){
  	drive(i);
  }
}
