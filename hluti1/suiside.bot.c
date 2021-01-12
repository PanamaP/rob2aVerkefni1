#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  rightIEM,       sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  leftIEM,        sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)

/*
	Programs which makes the robot do suiside.
	Robot goes forward and backwards, with each loop the length increments by 0.5m
*/


task main
{
	wait1Msec(2000);


	int power = 127;
	const int BASETIME = 1000;

	//Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;

	for(int i=0;i < 6;i++){
		motor[rightMotor] = power;
		motor[leftMotor] = -power;
		wait1Msec(BASETIME * i);

		motor[rightMotor] = -power;
		motor[leftMotor] = power;
		wait1Msec(BASETIME * i);
		}
}
