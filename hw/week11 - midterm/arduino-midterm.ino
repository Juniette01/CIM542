#include <CapacitiveSensor.h>
#include <Servo.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);

Servo myservo;
Servo myservo2;

int pos = 0;    // variable to store the servo position

void setup() {
  // put your setup code here, to run once:
capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
 Serial.begin(9600);
 pinMode(2,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(3); // attaches the servo on pin 3 to the servo object

}

void loop() {
  // put your main code here, to run repeatedly:
  long sensor1 = capSensor.capacitiveSensor(50);

   Serial.println(sensor1);  // print sensor output
   if(sensor1 >= 1000)
   {
    digitalWrite(2, HIGH);

    for (pos = 0; pos <= 100; pos += 1) { // degrees that servo turns

    myservo.write(pos);
     myservo2.write(pos);
    delay(5);                       // waits 5 for the servo to reach the position
  }
  for (pos = 100; pos >= 0; pos -= 1) {
    myservo.write(pos);
     myservo2.write(pos);
    delay(5);
  }



   }
   else {
    digitalWrite(2,LOW);
   }


}
