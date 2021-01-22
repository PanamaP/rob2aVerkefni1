
#pragma config(Sensor, dgtl6,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorServoContinuousRotation, openLoop)

/*Þetta forrit er eins og fyrsta verkefnið ( suiside ) en nú er notað encoder gildi í stað tíma. Við notum sama Drive fall og í fyrsta forritinu þar sem að það
er svokallað global fall. Hér notum við absolue til þess að forritð keyri í gegn þótt að við erum með mínus tölu í encoder gildinu. Síðan keyrum við forritið í task
main með for loopu eins og í verkefni 1.
*/

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
