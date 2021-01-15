
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorServoContinuousRotation, openLoop)

int rotation = 700; // 3 rotations and 45degree
int power = 126;

void drive(int dist){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

	while(SensorValue[leftEncoder] < (rotation*dist))
  {
    motor[rightMotor] = power;
    motor[leftMotor] = power;

  }
  while(SensorValue[leftEncoder] > 0)
  {
    motor[rightMotor] = -power;
    motor[leftMotor] = -power;

  }
}

task main()
{

  //Clear Encoders


  for(int i = 0; i<6;i++){
  	drive(i);
  }



}
