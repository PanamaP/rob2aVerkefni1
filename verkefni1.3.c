#pragma config(Sensor, dgtl6,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* Foll og breytur */
int BASEDIST = 564;
int BASEDEGleft = 3.2; /* D = 33cm, d = 10.16cm.... D/d = 3,2 */
int BASEDEGright = 2.0; /* Eitt dekkid a tessum as er einhvad laust svo ad eg turfti ad finna tad sjalfur */
int power = 80;

void reset(){ /* Tetta fall resetar encoderunum svo ad vidmidin sem eg set i naestkomandi follum fara i gegn */
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}
void stopMotors(){ /* Tad tarf lika ad endurraesa eda stoppa motorana tegar verid er ad vinna med svona beygur tar sem ad teir gera tad ekki sjalfir */
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

void turn(int deg, int beyga){ /* Tetta er turn fallid sem eg nota til tess ad beygja til haegri og vinstri. Er med if og else af tvi ad hann beygjdi alltaf
	mikid lengra til haegri tott ad eg var ad nota somu gildin. */
	if(beyga == 1){
		while(abs(SensorValue[rightEncoder]) < deg * BASEDEGleft){
			motor[leftMotor] = power * beyga;
			motor[rightMotor] = power * beyga;
		}
	}
	else{
		while(abs(SensorValue[rightEncoder]) < deg * BASEDEGright){
			motor[leftMotor] = power * beyga;
			motor[rightMotor] = power * beyga;
		}
	}
}
void drive(int dist){ /* Tetta er drive fallid sem er notad til ad fara afram. Eg tok tetta bara ur fyrstu forritunum tar sem ad tad er global. */
	while(abs(SensorValue[rightEncoder]) < dist){
		motor[rightMotor] = power;
		motor[leftMotor] = -power;
	}
}
/*-----------*/
/* KEYRSLA */

int beyga[14] = {1,-1,-1,1,1,-1,1,1,-1,1,1,-1,-1,1};

task main()
{
	wait1Msec(1000);
	for(int i = 0;i < 13;i++){
		wait1Msec(1000);
		reset();
		drive(BASEDIST);
		stopMotors();
		reset();
		wait1Msec(2000);
		turn(90, beyga[i]);
		stopMotors();
	}
	drive(BASEDIST);

}
